#include"Piece.h"
#include"Queen.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Queen::Queen(Colour colour) : Piece(colour, QUEEN){
  
}

void Queen::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, Piece* sourcePiece, Piece* destinationPiece, ChessBoard& board) {



}
