/* Rook.h - header file for the Rook class */

#ifndef ROOK_H
#define ROOK_H

#include"Piece.h"
#include"ChessBoard.h"

/*********************** Rook Class ***************************/


class Rook : public Piece {
 public:
  Rook(Colour);

  void checkMove(const int, const int, const int, const int, Piece*, Piece*, ChessBoard&) /*const*/ override final;


 private:

};


#endif
