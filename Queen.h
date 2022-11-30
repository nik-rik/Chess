/* Queen.h - header file for the Queen class */

#ifndef QUEEN_H
#define QUEEN_H

#include"Piece.h"

/*********************** Queen Class ***************************/


class Queen : public Piece {
 public:
  Queen(Colour);

  bool checkMove() const /*override final*/;

 private:

};


#endif
