//
// Created by User on 4/16/2020.
//

#include <cstring>
#include <memory>
#include "setup.h"

void setupBlocks(map<char, unique_ptr<BlockContent>> &m){
    m['T'] = unique_ptr<BlockContent>(new TBlockContent());
    m['S'] = unique_ptr<BlockContent>(new SBlockContent());
    m['O'] = unique_ptr<BlockContent>(new OBlockContent());
    m['Z'] = unique_ptr<BlockContent>(new ZBlockContent());
    m['J'] = unique_ptr<BlockContent>(new JBlockContent());
    m['I'] = unique_ptr<BlockContent>(new IBlockContent());
    m['L'] = unique_ptr<BlockContent>(new LBlockContent());
}

void Setup::setup(CentralCommand & c, int argc, char* argv[]) {
    //making the match between the Observers and Subject
    c.currentEndOfRound->attach(& c.nextPlayer->blindChoice);
    c.currentEndOfRound->attach(& c.nextPlayer->forceChoice);
    c.currentEndOfRound->attach(& c.nextPlayer->heavyChoice);
    c.currentEndOfRound->attach(& c.currentPlayer->timeWithoutScoring);
    c.currentEndOfRound->attach(c.currentChoice.get());

    c.nextEndOfRound->attach(& c.currentPlayer->blindChoice);
    c.nextEndOfRound->attach(& c.currentPlayer->forceChoice);
    c.nextEndOfRound->attach(& c.currentPlayer->heavyChoice);
    c.nextEndOfRound->attach(& c.nextPlayer->timeWithoutScoring);
    c.nextEndOfRound->attach(c.nextChoice.get());


    c.currentChoice->attach(& c.nextPlayer->heavyChoice);
    c.currentChoice->attach(& c.nextPlayer->blindChoice);
    c.currentChoice->attach(& c.nextPlayer->forceChoice);

    c.nextChoice->attach(& c.currentPlayer->heavyChoice);
    c.nextChoice->attach(& c.currentPlayer->blindChoice);
    c.nextChoice->attach(& c.currentPlayer->forceChoice);

    c.currentBoard->clear.attach(& c.currentPlayer->timeWithoutScoring);
    c.currentBoard->clear.attach(& c.currentPlayer->level);
    c.currentBoard->clear.attach(c.currentChoice.get());

    c.nextBoard->clear.attach(& c.nextPlayer->timeWithoutScoring);
    c.nextBoard->clear.attach(& c.nextPlayer->level);
    c.nextBoard->clear.attach(c.nextChoice.get());

    // making the graphics an observer of the levels, playerinfos, theBoard, Board

    // initialize the interpreterBetweenCharsAndBlocks
    setupBlocks(c.interpreterBetweenCharsAndBlocks);
    setupBlocks(c.currentBoard->interpreterBetweenCharsAndBlocks);
    setupBlocks(c.nextBoard->interpreterBetweenCharsAndBlocks);

    // initialize the row size and column size;
    int rowSize = 18;
    int columnSize = 11;
    c.rowSize = rowSize;
    c.currentBoard->rowSize = rowSize;
    c.nextBoard->rowSize = rowSize;
    c.currentBoard->columnSize = columnSize;
    c.nextBoard->columnSize = columnSize;

    //setup the files from block 0;
    c.currentPlayer->level.factoryLevel0->setFile("biquadris_sequence1.txt");
    c.nextPlayer->level.factoryLevel0->setFile("biquadris_sequence2.txt");
    // CommandLinePart
    int i = 0;
    while(i < argc){
        if(strncmp(argv[i], "-text", 20) == 0){
            c.IsGraphicsOn = false;
        } else if(strncmp(argv[i], "-seed", 20) == 0){
            int seed = stoi(argv[i+1]);
            c.currentPlayer->level.useSeeds(seed);
            c.nextPlayer->level.useSeeds(seed);
            i++;
        } else if(strncmp(argv[i], "-scriptfile1", 20) == 0){
            string filename = argv[i+1];
            c.currentPlayer->level.factoryLevel0->setFile(filename);
            i++;
        } else if(strncmp(argv[i], "-scriptfile2", 20) == 0){
            string filename = argv[i+1];
            c.nextPlayer->level.factoryLevel0->setFile(filename);
            i++;
        } else if(strncmp(argv[i], "-startlevel", 20) == 0){
            int startLevel;
            startLevel = stoi(argv[i+1]);
            c.currentPlayer->level.levelAdder(startLevel);
            c.nextPlayer->level.levelAdder(startLevel);
            i++;
        }
        i++;
    }
    // sets the id of theBoards
    c.currentBoard->id = 1;
    c.nextBoard->id =2 ;
    c.currentBoard->theBoard.id = 1;
    c.nextBoard->theBoard.id = 2;
    c.currentPlayer->id = 1;
    c.currentPlayer->level.id = 1;
    c.nextPlayer->id = 2;
    c.nextPlayer->level.id = 2;
}