#include"Piece.h"
#include"Pawn.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Pawn::Pawn(Colour colour) : Piece(colour, PAWN){
 
}

void Pawn::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, Piece* sourcePiece, Piece* destinationPiece, ChessBoard& board) { 

  if(sourcePiece->getColour() == WHITE){
    if (destinationCol - sourceCol == 0 && destinationRow - sourceRow == 1)
      if (destinationPiece == nullptr)
	return;

    if (destinationCol - sourceCol == 0 && destinationRow - sourceRow == 2)
      if(destinationPiece == nullptr)
	if(sourceRow == 1)
	  return;

    if ((abs(destinationCol - sourceCol) == 1 && destinationRow - sourceRow == 1))
      if(destinationPiece != nullptr && destinationPiece->getColour() == BLACK)
	return;

  }
  
  else if(sourcePiece->getColour() == BLACK){
    if (destinationCol - sourceCol == 0 && destinationRow - sourceRow == -1)
      if (destinationPiece == nullptr)
	return;

    if (destinationCol - sourceCol == 0 && destinationRow - sourceRow == -2)
      if(destinationPiece == nullptr)
	if(sourceRow == 6)
	  return;

    if ((abs(destinationCol - sourceCol) == 1 && destinationRow - sourceRow == -1))
      if(destinationPiece != nullptr && destinationPiece->getColour() == WHITE)
	return;
  }
    
  throw domain_error("cannot move to");

}
