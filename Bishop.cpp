#include"Piece.h"
#include"Bishop.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Bishop::Bishop(Colour colour) : Piece(colour, BISHOP) {
 
}

bool Bishop::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, ChessBoard& board) {
  Piece* destinationPiece = board.getSquare(destinationCol, destinationRow);
  
  if(destinationPiece == nullptr || destinationPiece->getColour() != getColour()){
    if (abs(destinationCol - sourceCol) == abs(destinationRow - sourceRow) && destinationCol - sourceCol != 0){
      int rowOffset = (destinationRow - sourceRow > 0) ? 1 : -1;
      int colOffset = (destinationCol - sourceCol > 0) ? 1 : -1;
      int checkRow;
      int checkCol;
      for(checkRow = sourceRow + rowOffset, checkCol = sourceCol + colOffset; checkRow != destinationRow; checkRow += rowOffset, checkCol += colOffset){
	if (board.getSquare(checkCol, checkRow) != nullptr)
	  return false;
      }
      return true;
    }
  }
  return false;
}
