//
// Created by User on 2020-04-11.
//

#ifndef BIQUADRIS_CENTRALCOMMAND_H
#define BIQUADRIS_CENTRALCOMMAND_H
#include <string>
#include <memory>
#include <map>
#include <sstream>
#include "playerinfo.h"
#include "board.h"
#include "subject.h"
#include "choice.h"
#include "whatcomesnext.h"
#include "blockcontent.h"
#include <iostream>
using namespace std;
class CentralCommand{
  //Every field that both players have, for example each player has a board.
  // there will be two pointers one for the player 1, and the other  for the player 2.
  // their names with follow the template currentxxx and nextxxx
  // where the current points to the field of the player that is currently playing
  // and next points to the player that will play next round
  unique_ptr<PlayerInfo> nextPlayer{new PlayerInfo(2)};
  unique_ptr<PlayerInfo> currentPlayer{new PlayerInfo(1)};
  unique_ptr<Board> currentBoard;
  unique_ptr<Board> nextBoard;
  unique_ptr<Subject> currentEndOfRound;
  unique_ptr<Subject> nextEndOfRound;
  unique_ptr<int> currentClock;
  unique_ptr<int> nextClock;
  unique_ptr<Choice> currentChoice;
  unique_ptr<Choice> nextChoice;
  // these are the commands that multipliers that do not  apply
  vector<string> noMultiplierCommands = {"restart", "random", "norandom", "didNotFindAnyThing"};
  // determines whether the -text command line flag was sent
  bool IsGraphicsOn = true;
  map<char, unique_ptr<BlockContent>> interpreterBetweenCharsAndBlocks;
  int turn = 0;
  int rowSize = 18;
  int columnSize = 11;
  string spaceInBetweenPlayers = stringMultiplication(" ", 3);
  string stringMultiplication(string, int);
  string getSpaceInBetweenBlocksAndScoresAndLevels() {return stringMultiplication("-", columnSize);}
  string getBlockOfNothingWithSizeColumn(){return stringMultiplication(" ", columnSize);}
  void changeOfTurn();
  bool heavyEffect(int);
  void print();
  void printScoresAndLevels();
  int getRowSize(){return rowSize;}
  void mergeTexts(string, string);
  vector<string> blockCommands = {"I","J","O","L","T","S","Z"};
  void printNexts();
  int takeCareOfMultiplier(string &);

public:
    CentralCommand(int, char* []);
    WhatComesNext doCommand(string);
    void startFirstRound();
    WhatComesNext startNewRound();
    void endOfMove();
    WhatComesNext endRound();
    void endOfGame();
    bool commandsComeFromSequence = false;
    ifstream inputfile;
    friend class Setup;
};

#endif //BIQUADRIS_CENTRALCOMMAND_H