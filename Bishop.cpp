#include"Piece.h"
#include"Bishop.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Bishop::Bishop(Colour colour) : Piece(colour, BISHOP) {
 
}

void Bishop::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, Piece* sourcePiece, Piece* destinationPiece, ChessBoard& board) {
  if (abs(destinationCol - sourceCol) == abs(destinationRow - sourceRow) && destinationCol - sourceCol != 0){
    int rowOffset = (destinationRow - sourceRow > 0) ? 1 : -1;
    int colOffset = (destinationCol - sourceCol > 0) ? 1 : -1;
    int checkRow;
    int checkCol;
    for(checkRow = sourceRow + rowOffset, checkCol = sourceCol + colOffset; checkRow != destinationRow; checkRow += rowOffset, checkCol += colOffset){
      if (board.getSquare(checkCol, checkRow) != nullptr)
	  throw domain_error("cannot move to");
    }

    if (destinationPiece == nullptr || destinationPiece->getColour() !=  sourcePiece->getColour())
      return;
  }
  throw domain_error("cannot move to");
}
