//
// Created by User on 4/15/2020.
//

#include "blockoperation.h"

bool BlockOperation::executeTransformation(BlockContent &blockContent, const TheBoard &theBoard) {
    if(! checkIfPossibleToDoTransformation(blockContent, theBoard)){
        return false;
    }
    vector<vector<int>> copyShape;
    for(int i = 0; i < blockContent.shape.size(); i++) {
        copyShape.push_back({transformationOnRow(blockContent.shape[i], blockContent),
                transformationOnColumn(blockContent.shape[i], blockContent)});
    }
    blockContent.shape = copyShape;
    blockContent.updateCorners();
    return true;
}

bool BlockOperation::checkIfPossibleToDoTransformation(BlockContent &blockContent, TheBoard theBoard) {
    for(int i = 0; i < blockContent.shape.size(); i++){
        int transformedRow = transformationOnRow(blockContent.shape[i], blockContent);
        int transformedColumn = transformationOnColumn(blockContent.shape[i], blockContent);
        //check if it goes out of the board
        vector<vector<Celula>> boardCopy = theBoard.getTheBoardState();
        if(transformedRow < 0 or transformedRow > boardCopy.size() - 1){return false;}
        if(transformedColumn < 0 or transformedColumn > boardCopy[0].size() - 1){return false;}
        // check if there is already an occupied celula there
        if (boardCopy[transformedRow][transformedColumn].isItFilled()) {return false;}
    }
    return true;
}