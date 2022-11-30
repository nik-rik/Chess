/* Rook.h - header file for the Rook class */

#ifndef ROOK_H
#define ROOK_H

#include"Piece.h"

/*********************** Rook Class ***************************/


class Rook : public Piece {
 public:
  Rook(Colour);

  bool checkMove() const; // override final;

 private:

};


#endif
