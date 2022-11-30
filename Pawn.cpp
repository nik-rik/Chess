#include"Piece.h"
#include"Pawn.h"
#include<iostream>

using namespace std;


Pawn::Pawn(Colour colour) {
  setColour(colour);
  setPieceType(PAWN);
}

void Pawn::checkMove(int sourceCol, int sourceRow, int destinationCol, int destinationRow) {
  
  

}
