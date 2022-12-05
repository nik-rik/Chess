/* ChessBoard.h - header file for the Piece class */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include"Piece.h"

class Piece;

/*********************** ChessBoard Class ***************************/


class ChessBoard{
 public:
  ChessBoard();

  void resetBoard();
  
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
  Piece* whitePieces[6];
  Piece* blackPieces[6];
  Colour turn;

  void makeMove(const char*, const char*, const int, const int, const int, const int, Piece*, Piece*);

  bool checkAttacking(const Piece*);
  
  bool isInCheck(Colour colour);
  
  bool whiteCheck;
  bool blackCheck;






};


#endif
