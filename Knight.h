/* Knight.h - header file for the Knight class */

#ifndef KNIGHT_H
#define KNIGHT_H

#include"Piece.h"
#include"ChessBoard.h"

/*********************** Knight Class ***************************/


class Knight : public Piece {
 public:
  Knight(Colour);

  bool checkMove(const int, const int, const int, const int, Piece*, Piece*, ChessBoard&) /*const*/ override final;

 private:

};


#endif
