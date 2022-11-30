#include"Piece.h"
#include"Bishop.h"
#include<iostream>

using namespace std;


Bishop::Bishop(Colour colour) {
  setColour(colour);
  setPieceType(BISHOP);
}

bool Bishop::checkMove() const {

  return false;

}
