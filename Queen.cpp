#include"Piece.h"
#include"Queen.h"
#include<iostream>

using namespace std;


Queen::Queen(Colour colour) {
  setColour(colour);
  setPieceType(QUEEN);
}

bool Queen::checkMove() const {

  return false;

}
