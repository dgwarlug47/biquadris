#include <iostream>
#include <string>
using namespace std;

#include "centralcommand.h"
#include "whatcomesnext.h"
//TODO: add the command line arguments.

int main(int argc, char * argv[]) {
    bool restart = true;
    while(restart) {
        restart = false;
        CentralCommand centralCommand(argc, argv);
        centralCommand.startFirstRound();
        string command;
        while (true) {
            if (!centralCommand.commandsComeFromSequence) {
                cin >> command;
            } else {
                if (!(centralCommand.inputfile >> command)) {
                    centralCommand.commandsComeFromSequence = false;
                    cin >> command;
                }
            }
            WhatComesNext whatComesNext = centralCommand.doCommand(command);
            if (whatComesNext == WhatComesNext::NextRound) {
                if(centralCommand.endRound() == WhatComesNext::EndGame){
                    centralCommand.endOfGame();
                    break;
                }
                if (centralCommand.startNewRound() == WhatComesNext::EndGame) {
                    centralCommand.endOfGame();
                    break;
                }
            } else if (whatComesNext == WhatComesNext::EndGame) {
                centralCommand.endOfGame();
                break;
            } else if (whatComesNext == WhatComesNext::Restart){
                restart= true;
                break;
            }
            else {
                centralCommand.endOfMove();
            }
        }
    }
}