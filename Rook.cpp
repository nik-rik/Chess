#include"Piece.h"
#include"Rook.h"
#include<iostream>

using namespace std;


Rook::Rook(Colour colour) {
  setColour(colour);
  setPieceType(ROOK);
}

bool Rook::checkMove() const {

  return false;

}
