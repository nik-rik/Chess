#include"Piece.h"
#include"Pawn.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Pawn::Pawn(Colour colour) : Piece(colour, PAWN){
 
}

bool Pawn::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, ChessBoard& board) const{ 
  Piece* destinationPiece = board.getSquare(destinationCol, destinationRow);
  
  if(getColour() == WHITE){
    if (destinationCol - sourceCol == 0 && destinationRow - sourceRow == 1)
      if (destinationPiece == nullptr)
	return true;

    if (destinationCol - sourceCol == 0 && destinationRow - sourceRow == 2)
      if((destinationPiece == nullptr) && (board.getSquare(destinationCol,(destinationRow - 1))) == nullptr)
	 if(sourceRow == 1)
	  return true;

    if ((abs(destinationCol - sourceCol) == 1 && destinationRow - sourceRow == 1))
      if(destinationPiece != nullptr && destinationPiece->getColour() == BLACK)
	return true;

  }
  
  else if(getColour() == BLACK){
    if (destinationCol - sourceCol == 0 && destinationRow - sourceRow == -1)
      if (destinationPiece == nullptr)
	return true;

    if (destinationCol - sourceCol == 0 && destinationRow - sourceRow == -2)
      if((destinationPiece == nullptr) && (board.getSquare(destinationCol,(destinationRow + 1))) == nullptr)
	if(sourceRow == 6)
	  return true;

    if ((abs(destinationCol - sourceCol) == 1 && destinationRow - sourceRow == -1))
      if(destinationPiece != nullptr && destinationPiece->getColour() == WHITE)
	return true;
  }
    
  return false;

}
