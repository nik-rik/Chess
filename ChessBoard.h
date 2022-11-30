/* ChessBoard.h - header file for the Piece class */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include"Piece.h"

/*********************** ChessBoard Class ***************************/

class ChessBoard{
 public:
  ChessBoard();

  void submitMove(const char*, const char*);

  Piece* getSquare(const int, const int) /*const*/; 

  void checkTurn(const Piece*);//const;
  void checkSourceNULL(const Piece*, const char*);//const;
  
  bool checkWhiteCheck();
  bool checkBlackCheck();

  bool checkStalemate();
  bool checkCheckmate();

 private:
  Piece* squares[8][8];
  Colour turn;

  void fullPieceSetup(const Colour);
  void mainPieceSetup(const Colour);
  void pawnSetup(const Colour);

  bool whiteCheck;
  bool blackCheck;






};


#endif
