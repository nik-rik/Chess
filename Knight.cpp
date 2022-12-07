#include"Piece.h"
#include"Knight.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Knight::Knight(Colour colour) : Piece(colour, KNIGHT) {
  
}

bool Knight::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, ChessBoard& board) {
  Piece* destinationPiece = board.getSquare(destinationCol, destinationRow);
  
  if(destinationPiece == nullptr || destinationPiece->getColour() != getColour()){
    if (sourceCol == destinationCol + 1 || sourceCol == destinationCol - 1)
      if (sourceRow == destinationRow + 2 || sourceRow == destinationRow - 2)
	return true;

    if (sourceCol == destinationCol + 2 || sourceCol == destinationCol - 2)
      if (sourceRow == destinationRow + 1 || sourceRow == destinationRow - 1)
	return true;
  }
  
  return false;
  
}
