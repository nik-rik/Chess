/* ChessBoard.h - header file for the Piece class */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include"Piece.h"

class Piece;

/*********************** ChessBoard Class ***************************/


class ChessBoard{
 public:
  ChessBoard();

  void submitMove(const char*, const char*);
  void resetBoard();
  void printBoard() const;

  Piece* getSquare(const int, const int) const;
  
 private:
  Piece* squares[8][8];
  Piece* whitePieces[6];
  Piece* blackPieces[6];
  Colour turn;

  void placePieces();
  
  void checkTurn(const Piece*) const;
  void checkSourceNULL(const Piece*, const char*) const;
  
  void makeMove(const char*, const char*, const int, const int, const int, const int, Piece*, Piece*);
  
  bool isInCheck(const Colour);
  bool checkCheck(const Colour, const int, const int, const int, const int, Piece*, ChessBoard);
  
  bool isMate(const Colour);
  

};


#endif
