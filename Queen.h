/* Queen.h - header file for the Queen class */

#ifndef QUEEN_H
#define QUEEN_H

#include"Piece.h"
#include"ChessBoard.h"

/*********************** Queen Class ***************************/


class Queen : public Piece {
 public:
  Queen(Colour);

  void checkMove(const int, const int, const int, const int, Piece*, Piece*, ChessBoard&) /*const*/ override final;
  

 private:

};


#endif
