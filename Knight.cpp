#include"Piece.h"
#include"Knight.h"
#include<iostream>

using namespace std;


Knight::Knight(Colour colour) {
  setColour(colour);
  setPieceType(KNIGHT);
}

bool Knight::checkMove() const {

  return false;

}
