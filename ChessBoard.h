/* ChessBoard.h - header file for the Piece class */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include"Piece.h"

class Piece;

/*********************** ChessBoard Class ***************************/


class ChessBoard{
 public:
  ChessBoard();  // ChessBoard constructor
  //~ChessBoard();
  void resetBoard();
  void printBoard() const;

  void submitMove(const char*, const char*);  // Function that takes two position inputs and begins processing them 
  
  Piece* getSquare(const int, const int) const; // Gets pointer to the piece (or null) that occupies a specific square 
  
 private:
  Piece* squares[8][8]; // The board is essentialy an 8x8 matrix of pointers to different piece types
  Piece* whitePieces[6]; // Stores the white pieces so that they do not have to be destroyed and created in reset board
  Piece* blackPieces[6]; // Stores the black pieces so that they do not have to be destroyed and created in reset board
  Colour turn;  // Stores the colour that is it move

  void placePieces(); // Helper function for constructing and resetting the board
  
  void checkTurn(const Piece*) const; // Checks if the piece that is selected to be moved corresponds to the turn of the game
  void checkSourceNULL(const Piece*, const char*) const; // Checks if the source piece is null
  
  void makeMove(const char*, const char*, const int, const int, const int, const int, Piece*, Piece*); // Makes move if it is legal
  
  bool isInCheck(const Colour); // Checks if a side is in check 
  bool checkCheck(const Colour, const int, const int, const int, const int, Piece*, ChessBoard); // Checks if a move actually moves the team out of check
  
  bool isMate(const Colour); // Checks if a mate is occuring
  

};


#endif
