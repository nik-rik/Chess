#include"Piece.h"
#include"Queen.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Queen::Queen(Colour colour) : Piece(colour, QUEEN){
  
}

bool Queen::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, ChessBoard& board) {
  Piece* destinationPiece = board.getSquare(destinationCol, destinationRow);
  
  if(destinationPiece == nullptr || destinationPiece->getColour() != getColour()){
    if(sourceRow == destinationRow){
      int colOffset = (destinationCol - sourceCol > 0) ? 1 : -1;
      for (int checkCol = sourceCol + colOffset; checkCol != destinationCol; checkCol+= colOffset)
	if (board.getSquare(checkCol,sourceRow) != nullptr)
	  return false;
      return true;
    }

    else if (destinationCol == sourceCol){
      int rowOffset = (destinationRow - sourceRow > 0) ? 1 : -1;
      for(int checkRow = sourceRow + rowOffset; checkRow != destinationRow; checkRow += rowOffset)
	if(board.getSquare(sourceCol,checkRow) != nullptr)
	  return false;
      return true;
    }

    else if (abs(destinationCol - sourceCol) == abs(destinationRow - sourceRow) && destinationCol - sourceCol != 0){
      int rowOffset = (destinationRow - sourceRow > 0) ? 1 : -1;
      int colOffset = (destinationCol - sourceCol > 0) ? 1 : -1;
      int checkRow;
      int checkCol;
      for(checkRow = sourceRow + rowOffset, checkCol = sourceCol + colOffset; checkRow != destinationRow; checkRow += rowOffset, checkCol += colOffset)
	if (board.getSquare(checkCol, checkRow) != nullptr)
	  return false;
      return true;
    }
  }

  return false;
}






