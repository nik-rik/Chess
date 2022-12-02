#include<iostream>
#include"Piece.h"
#include"ChessBoard.h"

using namespace std;

Piece::Piece(Colour colour, PieceType type){
  setColour(colour);
  setPieceType(type);

}

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




std::ostream& operator << (std::ostream& out, const Colour colour){
  if (colour == WHITE)
    out << "White";
  else if (colour == BLACK)
    out << "Black";

  return out;
}


std::ostream& operator << (std::ostream& out, const PieceType type){
  switch(type){
  case PAWN:
    out << "Pawn";
    break;

  case ROOK:
    out << "Rook";
    break;
    
  case BISHOP:
    out << "Bishop";
    break;

  case KNIGHT:
    out << "Knight";
    break;

  case KING:
    out << "King";
    break;
    
  case QUEEN:
    out << "Queen";
    break;

  }

  return out;
    
}
