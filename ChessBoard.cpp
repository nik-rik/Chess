#include<iostream>
#include"ChessBoard.h"
#include"Piece.h"
#include"Pawn.h"
#include"King.h"
#include"Rook.h"
#include"Bishop.h"
#include"Queen.h"
#include"Knight.h"

using namespace std;


ChessBoard::ChessBoard() : turn(WHITE), whiteCheck(false), blackCheck(false){
  for (int i = 2; i < 6; i++)
    for (int j = 0; j < 8; j++)
      squares[i][j] = nullptr;

  fullPieceSetup(WHITE);
  fullPieceSetup(BLACK);

  cout << "A new chess game is started!" << endl;

  
}

void ChessBoard::fullPieceSetup(Colour colour){
  // mainPieceSetup(colour);
  pawnSetup(colour);

}

/* void ChessBoard::mainPieceSetup(Colour colour){
  int i;
  
  if (colour == WHITE)
    i = 0;
  else if (colour == BLACK)
    i = 7;

  squares[i][0] = new Rook(colour);
  squares[i][1] = new Knight(colour);
  squares[i][2] = new Bishop(colour);
  squares[i][3] = new Queen(colour);
  squares[i][4] = new King(colour);
  squares[i][5] = new Bishop(colour);
  squares[i][6] = new Knight(colour);
  squares[i][7] = new Rook(colour);

}
*/

void ChessBoard::pawnSetup(Colour colour){
  int i;

  if (colour == WHITE)
    i = 1;
  else if (colour == BLACK)
    i = 6;

  for (int j = 0; j < 8; j++)
    squares[i][j] = new Pawn(colour);

}


void ChessBoard::submitMove(const char* source_square, const char* destination_square){
  try {
    int sourceCol = (*source_square - 'A');
    int sourceRow = (*(source_square + 1) - '1');

    int destinationCol = (*destination_square - 'A');
    int destinationRow = (*(destination_square + 1) - '1');
  
    Piece* sourcePiece = getSquare(sourceCol, sourceRow);

    checkSourceNULL(sourcePiece, source_square);

    checkTurn(sourcePiece);

    sourcePiece->checkMove(sourceCol, sourceRow, destinationCol, destinationRow);
  
    
    



  }
  catch (const out_of_range& ex){
    cout << ex.what() << source_square << "!" << endl;
  }
  catch (const exception& ex){
    cout << ex.what() << endl;
  }
}

  

Piece* ChessBoard::getSquare(const int col, const int row){
  
  return squares[row][col];

}

void ChessBoard::checkSourceNULL(const Piece* sourcePiece, const char* source_square){
    if (sourcePiece == nullptr)
      throw out_of_range("There is no piece at position ");
}

void ChessBoard::checkTurn(const Piece* sourcePiece){
  if (sourcePiece->getColour() != turn){
    if (turn == WHITE)
      throw invalid_argument("It is not Black's turn to move!");
    if (turn == BLACK)
      throw invalid_argument("It is not White's turn to move!");
  }
}


