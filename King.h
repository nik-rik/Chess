/* King.h - header file for the King class */

#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "ChessBoard.h"

/*********************** King Class ***************************/


class King : public Piece {
 public:
  King(Colour);

  void checkMove(const int, const int, const int, const int, Piece*, Piece*, ChessBoard&) /*const*/ override final;
  

 private:

};





#endif
