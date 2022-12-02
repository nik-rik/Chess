#include"Piece.h"
#include"Rook.h"
#include"ChessBoard.h"
#include<iostream>

using namespace std;


Rook::Rook(Colour colour) : Piece(colour, ROOK){
 
}

void Rook::checkMove(const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, Piece* sourcePiece, Piece* destinationPiece, ChessBoard& board) {


}


