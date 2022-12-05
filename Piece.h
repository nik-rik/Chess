/* Piece.h - header file for the Piece class */

#ifndef PIECE_H
#define PIECE_H

enum Colour {WHITE, BLACK};

#include "ChessBoard.h"
#include<iostream>

/*********************** Piece Class ***************************/

enum PieceType {PAWN, KING, ROOK, BISHOP, QUEEN, KNIGHT};

std::ostream& operator<<(std::ostream&, Colour); // Overloads the << operator for Colour
Colour& operator++(Colour&);

std::ostream& operator<<(std::ostream&, PieceType); // Overloads the << operator for PieceType


class ChessBoard;

class Piece{
 public:
  Piece(Colour colour, PieceType type);
  
  Colour getColour() const;
  void setColour(const Colour&);
  
  PieceType getPieceType() const;
  void setPieceType(const PieceType&);

  virtual bool checkMove(const int, const int, const int, const int, Piece*, Piece*, ChessBoard&) /*const*/ = 0;

  virtual ~Piece() = default;

 private:
  PieceType type;
  Colour colour;
  
  
};

#endif
