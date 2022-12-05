#include"Piece.h"
#include"Queen.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Queen::Queen(Colour colour) : Piece(colour, QUEEN){
  
}

void Queen::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, Piece* sourcePiece, Piece* destinationPiece, ChessBoard& board) {
  if(sourceRow == destinationRow){
    int colOffset = (destinationCol - sourceCol > 0) ? 1 : -1;
    for (int checkCol = sourceCol + colOffset; checkCol != destinationCol; checkCol+= colOffset)
      if (board.getSquare(checkCol,sourceRow) != nullptr)
	throw domain_error("cannot move to");
  }

  else if (destinationCol == sourceCol){
    int rowOffset = (destinationRow - sourceRow > 0) ? 1 : -1;
    for(int checkRow = sourceRow + rowOffset; checkRow != destinationRow; checkRow += rowOffset)
      if(board.getSquare(sourceCol,checkRow) != nullptr)
	throw domain_error("cannot move to");
  }

  else if (abs(destinationCol - sourceCol) == abs(destinationRow - sourceRow) && destinationCol - sourceCol != 0){
    int rowOffset = (destinationRow - sourceRow > 0) ? 1 : -1;
    int colOffset = (destinationCol - sourceCol > 0) ? 1 : -1;
    int checkRow;
    int checkCol;
    for(checkRow = sourceRow + rowOffset, checkCol = sourceCol + colOffset; checkRow != destinationRow; checkRow += rowOffset, checkCol += colOffset)
      if (board.getSquare(checkCol, checkRow) != nullptr)
	  throw domain_error("cannot move to");
    
  }

    if (destinationPiece == nullptr || destinationPiece->getColour() !=  sourcePiece->getColour())
      return;

  throw domain_error("cannot move to");
}






