#include"Piece.h"
#include"Knight.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Knight::Knight(Colour colour) : Piece(colour, KNIGHT) {
  
}

void Knight::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, Piece* sourcePiece, Piece* destinationPiece, ChessBoard& board) {
  if (sourceCol == destinationCol + 1 || sourceCol == destinationCol - 1)
    if (sourceRow == destinationRow + 2 || sourceRow == destinationRow - 2)
      return;

  if (sourceCol == destinationCol + 2 || sourceCol == destinationCol - 2)
    if (sourceRow == destinationRow + 1 || sourceRow == destinationRow - 1)
      return;

  throw domain_error("cannot move to");

}
