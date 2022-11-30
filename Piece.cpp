#include<iostream>
#include"Piece.h"


using namespace std;


Colour Piece::getColour() const{

  return colour;
  
}

void Piece::setColour(const Colour& _colour){

  colour = _colour;
  
}

PieceType Piece::getPieceType() const{

  return type;
  
}

void Piece::setPieceType(const PieceType& _type){

  type = _type;
  
}

