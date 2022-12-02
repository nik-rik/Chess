/* Bishop.h - header file for the Bishop class */

#ifndef BISHOP_H
#define BISHOP_H

#include"Piece.h"
#include"ChessBoard.h"

/*********************** Bishop Class ***************************/


class Bishop : public Piece {
 public:
  Bishop(Colour);

  void checkMove(const int, const int, const int, const int, Piece*, Piece*, ChessBoard&) /*const*/ override final;  

 private:

};


#endif
