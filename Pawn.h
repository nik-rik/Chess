/* Pawn.h - header file for the Pawn class */

#ifndef PAWN_H
#define PAWN_H

#include"Piece.h"
#include"ChessBoard.h"

/*********************** Pawn Class ***************************/


class Pawn : public Piece {
 public:
  Pawn(Colour);

  bool checkMove(const int, const int, const int, const int, ChessBoard&) const override final;

 private:
  
};


#endif





