#include"Piece.h"
#include"King.h"
#include<iostream>

using namespace std;


King::King(Colour colour) {
  setColour(colour);
  setPieceType(KING);
}

bool King::checkMove() const {

  return false;

}

