#include"Piece.h"
#include"Knight.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Knight::Knight(Colour colour) : Piece(colour, KNIGHT) {
  
}

void Knight::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, Piece* sourcePiece, Piece* destinationPiece, ChessBoard& board) {



}
