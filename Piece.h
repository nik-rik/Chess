/* Piece.h - header file for the Piece class */

#ifndef PIECE_H
#define PIECE_H

/*********************** Piece Class ***************************/

enum Colour {WHITE, BLACK};
enum PieceType {PAWN, KING, ROOK, BISHOP, QUEEN, KNIGHT};


class Piece{
 public:
  Colour getColour() const;
  void setColour(const Colour&);
  
  PieceType getPieceType() const;
  void setPieceType(const PieceType&);

  virtual void checkMove(int, int, int, int) /*const*/ = 0;

  virtual ~Piece() = default;
  
 private:
  Colour colour;
  PieceType type;

 
};

#endif
