/* King.h - header file for the King class */

#ifndef KING_H
#define KING_H

#include "Piece.h"

/*********************** King Class ***************************/


class King : public Piece {
 public:
  King(Colour);
  bool checkMove() const /*override final*/;

 private:

};





#endif
