/* Pawn.h - header file for the Pawn class */

#ifndef PAWN_H
#define PAWN_H

#include"Piece.h"

/*********************** Pawn Class ***************************/


class Pawn : public Piece {
 public:
  Pawn(Colour);

  void checkMove(int, int, int, int) /*const*/ override final;

 private:

};


#endif





