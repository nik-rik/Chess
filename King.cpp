#include"Piece.h"
#include"King.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


King::King(Colour colour) : Piece(colour, KING) {

}

bool King::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, ChessBoard& board) {
  int rowOffset = abs(destinationRow - sourceRow);
  int colOffset = abs(destinationCol - sourceCol);

  if((rowOffset == 1) || (colOffset == 1))
    return true;

  
  return false;

  
}
