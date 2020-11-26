//
// Created by User on 2020-04-11.
//

# include "centralcommand.h"
#include "setup.h"

CentralCommand::CentralCommand(int argc, char *argv[]):
                                    currentBoard{new Board}, nextBoard{new Board},
                                    currentEndOfRound(new Subject), nextEndOfRound(new Subject),
                                    currentChoice(new Choice("choice", "clear", 0, 1)),
                                    nextChoice(new Choice("choice", "clear", 0, 1)),
                                    currentClock{ new int(0)}, nextClock{new int(0)}
                                    {
    Setup().setup(*this,argc, argv);
    //TODO add the matching between observers and subjects
}
int CentralCommand::takeCareOfMultiplier(string & commandMessage) {
    int commandNumber;
    string commandPrefix;
    string command;
    stringstream stream;
    stream << commandMessage;
    if(!(stream >> commandNumber)){
        commandNumber = 1;
    }
    stream >> commandMessage;
    return commandNumber;
}
WhatComesNext CentralCommand::doCommand(string commandMessage) {
    int commandNumber = takeCareOfMultiplier(commandMessage);
    string commandOnOurInterpretation = currentPlayer->playerCommands.getCommandNameOnOurInterpretation(commandMessage);
    //removes the multiplier if the command is one of those
    for (auto it : noMultiplierCommands){
        if(commandOnOurInterpretation == it){
            commandNumber = 1;
        }
    }
    //sets default return value
    WhatComesNext whatComesNext =WhatComesNext::NextMove;
    // here we put all of the commands
    for(int i = 0; i < commandNumber; i++) {
        if (commandOnOurInterpretation == "drop") {
            currentBoard->drop();
            if(i!=commandNumber-1){
                if(!currentBoard->setNewBlock(currentPlayer->createNewBlock())){
                    return WhatComesNext::EndGame;
                }
            }
            whatComesNext = WhatComesNext::NextRound;
        } else if (commandOnOurInterpretation == "left") {
            currentBoard->left();
            if(i == commandNumber -1){
                if (!heavyEffect(currentPlayer->getHeavynessFromLevel() + currentPlayer->getHeavynessFromChoice())) {
                    return WhatComesNext::NextRound;
                }
            }
        } else if (commandOnOurInterpretation == "right") {
            currentBoard->right();
            if(i == commandNumber - 1) {
                if (!heavyEffect(currentPlayer->getHeavynessFromLevel() + currentPlayer->getHeavynessFromChoice())) {
                    return WhatComesNext::NextRound;
                }
            }
        } else if (commandOnOurInterpretation == "clockwise") {
            currentBoard->clockWise();
            if(i == commandNumber - 1) {
                if (!heavyEffect(currentPlayer->getHeavynessFromLevel())) {
                    return WhatComesNext::NextRound;
                }
            }

        } else if (commandOnOurInterpretation == "counterclockwise") {
            currentBoard->counterClockWise();
            if(i == commandNumber - 1) {
                if (!heavyEffect(currentPlayer->getHeavynessFromLevel())) {
                    return WhatComesNext::NextRound;
                }
            }
        } else if (commandOnOurInterpretation == "levelup"){
            currentPlayer->level.levelAdder(1);
        } else if (commandOnOurInterpretation == "leveldown"){
            currentPlayer->level.levelAdder(-1);
        }  else if(commandOnOurInterpretation == "down"){
            currentBoard->down();
        } else if(commandOnOurInterpretation == "didNotFindAnything"){
            cout << "Wrong Command Name" << endl;
            return whatComesNext;
        } else if(commandOnOurInterpretation == "norandom") {
            string filename;
            cin >> filename;
            if (currentPlayer->level.getLevel() < 3) {
                cout << "This Operation has on effect under this level" << endl;
            }
            else{
                currentPlayer->noRandom(filename);
            }
        } else if(commandOnOurInterpretation == "random"){
            currentPlayer->randomize();
        } else if(commandOnOurInterpretation == "sequence"){
            commandsComeFromSequence = true;
            string filename;
            cin >> filename;
            inputfile = ifstream(filename);
        } else if(commandOnOurInterpretation == "restart"){
            return WhatComesNext::Restart;
        }
    }
    for (auto it: blockCommands) {
        if (it == commandOnOurInterpretation) {
            if (!currentBoard->setNewBlock(it[0])) {
                return WhatComesNext::EndGame;
            }
        }
    }
    return whatComesNext;
}
//applies the heavy a number n of times
bool CentralCommand::heavyEffect(int n){
    for(int i = 0; i < n; i++){
        if(!currentBoard->heavy()){
            return false;
        }
    }
    return true;
}

WhatComesNext CentralCommand::endRound(){
    currentChoice->choose();
    if(currentPlayer->gotScrewed()){
        if(!currentBoard->addBrown()){
            return WhatComesNext::EndGame;
        }
        currentChoice->choose();
    }
    vector<string> s{"endOfRound"}; vector<int> i{*currentClock + 1};
    currentEndOfRound->notifyObservers(s,i);
    changeOfTurn();
    return WhatComesNext::NextRound;
}

void CentralCommand::startFirstRound() {
    currentBoard->setNewBlock(currentPlayer->createNewBlock());
    nextBoard->setNewBlock(nextPlayer->createNewBlock());
    currentPlayer->setNextBlock();
    print();
}
WhatComesNext CentralCommand::startNewRound() {
    if(!nextBoard->setNewBlock(nextPlayer->getNextBlock())){
        return WhatComesNext::EndGame;
    }
    currentPlayer->setNextBlock();
    print();
    // this value is irrelevant, it only matters the fact that it is different from EndGame
    return WhatComesNext::NextMove;
}

void CentralCommand::endOfMove() {
    print();
}

void CentralCommand::changeOfTurn() {
    currentPlayer.swap(nextPlayer);
    currentBoard.swap(nextBoard);
    currentChoice.swap(nextChoice);
    currentEndOfRound.swap(nextEndOfRound);
    *currentClock = *currentClock + 1;
     currentClock.swap(nextClock);
     if(turn == 0){
         turn = 1;
     }
     else{
         turn = 0;
     }
}

void CentralCommand::print() {
    printScoresAndLevels();
    string s1 = currentBoard->stringfy(currentPlayer->getBlind());
    string s2 = nextBoard->stringfy(nextPlayer->getBlind());
    if(turn == 0) {
        mergeTexts(s1,s2);
    }
    else{
        mergeTexts(s2,s1);
    }
    printNexts();
    vector<vector<int>> nextBlockShape;
    vector<int> nextBlockCorners;
    char c = currentPlayer->getNextBlock();
    for(auto it = interpreterBetweenCharsAndBlocks.begin(); it != interpreterBetweenCharsAndBlocks.end(); it++){
        if(c == it->first){
            nextBlockShape = it->second->getShape();
            nextBlockCorners = it->second->getCorners();
            break;
        }
    }
    int up = nextBlockCorners[2];
    int down = nextBlockCorners[3];
    string ans = stringMultiplication(" ", columnSize * (down -up + 1));
    for(auto it : nextBlockShape){
        ans[(it[0] - up)*columnSize + it[1]] = c;
    }
    if(turn == 0){
        mergeTexts(ans, stringMultiplication(" ", columnSize * (down - up + 1)));
    }
    else{
        mergeTexts(stringMultiplication(" ", columnSize * (down - up + 1)), ans);
    }
}

void CentralCommand::printScoresAndLevels(){
    string ans = getBlockOfNothingWithSizeColumn();
    if(turn == 1){
        //doing the swap
        currentPlayer.swap(nextPlayer);
    }
    int firstLevel = currentPlayer->level.getLevel();
    int secondLevel = nextPlayer->level.getLevel();
    int firstScore = currentPlayer->level.getScore();
    int secondScore = nextPlayer->level.getScore();
    if(turn == 1) {
        //redoing the swap
        currentPlayer.swap(nextPlayer);
    }
    ans.insert(0, "Level: " + to_string(firstLevel));
    ans = ans.substr(0,columnSize);
    ans += spaceInBetweenPlayers;
    ans += "Level: " + to_string(secondLevel);
    cout << ans << endl;

    ans = getBlockOfNothingWithSizeColumn();
    ans.insert(0, "Score: " + to_string(firstScore));
    ans = ans.substr(0,columnSize);
    ans+= spaceInBetweenPlayers;
    ans += "Score: " + to_string(secondScore);
    cout << ans << endl;
    cout << getSpaceInBetweenBlocksAndScoresAndLevels() << spaceInBetweenPlayers << getSpaceInBetweenBlocksAndScoresAndLevels() << endl;
    // Redoing the swap
}
void CentralCommand::printNexts(){
    cout << getSpaceInBetweenBlocksAndScoresAndLevels() << spaceInBetweenPlayers << getSpaceInBetweenBlocksAndScoresAndLevels() << endl;
    string rest = getBlockOfNothingWithSizeColumn();
    rest = "Next: " + rest;
    rest = rest.substr(0, columnSize);
    cout << rest << spaceInBetweenPlayers << "Next: " << endl;
}
void CentralCommand::mergeTexts(string s1, string s2) {
    int rowSpam = s1.size()/columnSize;
    for(int j = 0; j < rowSpam; j ++) {
        for (int i = 0; i < columnSize; i++) {
            cout << s1[0];
            s1.erase(0, 1);
        }
        cout << spaceInBetweenPlayers;
        for (int i = 0; i < columnSize; i++) {
            cout << s2[0];
            s2.erase(0, 1);
        }
        cout << endl;
    }
}

void CentralCommand::endOfGame() {
    if(turn == 1){
        cout << "Congratulations Player 2" << endl;
    }
    else{
        cout << "Congratulations Player 1" << endl;
    }
}

string CentralCommand::stringMultiplication(string s, int n) {
    string ans;
    for(int i = 0; i < n; i++){
        ans += s;
    }
    return ans;
}
