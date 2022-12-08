#include<iostream>
#include"Piece.h"
#include"Pawn.h"
#include"King.h"
#include"Rook.h"
#include"Bishop.h"
#include"Queen.h"
#include"Knight.h"
#include"ChessBoard.h"

using namespace std;


ChessBoard::ChessBoard() : turn(WHITE), whiteCheck(false), blackCheck(false){
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      squares[i][j] = nullptr;

  whitePieces[0] = new Pawn(WHITE);
  whitePieces[1] = new Rook(WHITE);
  whitePieces[2] = new Knight(WHITE);
  whitePieces[3] = new Bishop(WHITE);
  whitePieces[4] = new Queen(WHITE);
  whitePieces[5]= new King(WHITE);

  for (int j = 0; j < 8; j++)
    squares[1][j] = whitePieces[0];

  squares[0][0] = whitePieces[1];
  squares[0][1] = whitePieces[2];
  squares[0][2] = whitePieces[3];
  squares[0][3] = whitePieces[4];
  squares[0][4] = whitePieces[5];
  squares[0][5] = whitePieces[3];
  squares[0][6] = whitePieces[2];
  squares[0][7] = whitePieces[1];


  blackPieces[0] = new Pawn(BLACK);
  blackPieces[1] = new Rook(BLACK);
  blackPieces[2] = new Knight(BLACK);
  blackPieces[3] = new Bishop(BLACK);
  blackPieces[4] = new Queen(BLACK);
  blackPieces[5]= new King(BLACK);

  for (int j = 0; j < 8; j++)
    squares[6][j] = blackPieces[0];

  squares[7][0] = blackPieces[1];
  squares[7][1] = blackPieces[2];
  squares[7][2] = blackPieces[3];
  squares[7][3] = blackPieces[4];
  squares[7][4] = blackPieces[5];
  squares[7][5] = blackPieces[3];
  squares[7][6] = blackPieces[2];
  squares[7][7] = blackPieces[1];

  cout << "A new chess game is started" << endl;
}

// Piece** ChessBoard::WhitePieces 

void ChessBoard::submitMove(const char* source_square, const char* destination_square){
  try {
    int sourceCol = (*source_square - 'A');
    int sourceRow = (*(source_square + 1) - '1');

    int destinationCol = (*destination_square - 'A');
    int destinationRow = (*(destination_square + 1) - '1');
  
    Piece* sourcePiece = getSquare(sourceCol, sourceRow);
    Piece* destinationPiece = getSquare(destinationCol, destinationRow);
    
    checkSourceNULL(sourcePiece, source_square);
    checkTurn(sourcePiece);

    if (sourcePiece->checkMove(sourceCol, sourceRow, destinationCol, destinationRow, *this) == false)
      throw domain_error("cannot move to");
  
    makeMove(source_square, destination_square, sourceCol, sourceRow, destinationCol, destinationRow, sourcePiece, destinationPiece);
    

  }
  catch (const domain_error& ex){
    int sourceCol = (*source_square - 'A');
    int sourceRow = (*(source_square + 1) - '1');
    
    if (turn == BLACK)
      cout << "Black's ";
    else if (turn == WHITE)
      cout << "White's ";

    cout << (getSquare(sourceCol, sourceRow))->getPieceType() << " " << ex.what() << " " << destination_square << "!" << endl;
	
  }
  catch (const out_of_range& ex){
    cout << "There is no piece at position " << source_square << "!" << endl;
  }
  catch (const invalid_argument& ex){
    cout << "It is not " << ((turn == WHITE) ? "Black's" : "White's") << " turn to move!" << endl; 
  }
  catch (const exception& ex){
    cout << ex.what() << endl;
  }
}

  

Piece* ChessBoard::getSquare(const int col, const int row){
   if (col > 7 || row > 7)
     throw logic_error("You must input a valid square on the board!");
  
    return squares[row][col];
}

void ChessBoard::checkSourceNULL(const Piece* sourcePiece, const char* source_square){
    if (sourcePiece == nullptr)
      throw out_of_range("There is no piece at position: ");
}

void ChessBoard::checkTurn(const Piece* sourcePiece){
  if (sourcePiece->getColour() != turn)
      throw invalid_argument("Incorrect turn");
}


void ChessBoard::makeMove(const char* source_square, const char* destination_square, const int sourceCol, const int sourceRow, const int destinationCol, const int destinationRow, Piece* sourcePiece, Piece* destinationPiece){
  cout << turn << "'s " << sourcePiece->getPieceType() << " moves from " << source_square << " to " << destination_square;

  if (destinationPiece == nullptr)
    cout << endl;

  else {
    cout << " taking ";
    if (turn == WHITE)
      cout << "Black's ";
    else if (turn == BLACK)
      cout << "White's ";

    cout << destinationPiece->getPieceType() << endl;
  }    

  squares[destinationRow][destinationCol] = sourcePiece;
  squares[sourceRow][sourceCol] = nullptr;

if (turn == WHITE){
    if (isInCheck(BLACK)){
      if (isCheckmate(BLACK))
	cout << "Black is in checkmate" << endl;
      else
	cout << "Black is in check" << endl;
    }
  }
  else if (turn == BLACK){
    if (isInCheck(WHITE)){
	if (isCheckmate(WHITE))
	  cout << "White is in checkmate" << endl;
	else
	  cout << "White is in check" << endl;
    }
  }
 
 ++turn;
  
}

bool ChessBoard::isInCheck(Colour colour){
  Piece* attackingPiece;
  int kingRow;
  int kingCol;

  for(int row = 0; row < 8; row++)
    for(int col = 0; col < 8; col++)
      if(squares[row][col] != nullptr)
	if(squares[row][col]->getPieceType() == KING)
	  if(squares[row][col]->getColour() == colour){
	    kingRow = row;
	    kingCol = col;
	    break;
	  }


  for(int row = 0; row < 8; row++)
    for(int col = 0; col < 8; col++)  
      if(squares[row][col] != nullptr)
	if(squares[row][col]->getColour() != colour){
	  attackingPiece = getSquare(col, row);
	  if (attackingPiece->checkMove(col, row, kingCol, kingRow, *this) == true)
	    return true;
	  }

  return false;

}


/*Piece* ChessBoard::findKing(Colour colour){
  int kingRow;
  int kingCol;
  Piece* kingPiece;

  for(int row = 0; row < 8; row++)
    for(int col = 0; col < 8; col++)
      if(squares[row][col] != nullptr)
	if(squares[row][col]->getPieceType() == KING)
	  if(squares[row][col]->getColour() == colour){
	    kingRow = row;
	    kingCol = col;
	    break;
	  }

  kingPiece = getSquare(kingCol, kingRow);

  return kingPiece;

  } */


bool ChessBoard::isCheckmate(Colour colour){
  for(int sourceRow = 0; sourceRow < 8; sourceRow++)
    for(int sourceCol = 0; sourceCol < 8; sourceCol++){
      if(getSquare(sourceCol, sourceRow) == nullptr)
	continue;
      for(int destinationRow = 0; destinationRow < 8; destinationRow++)
	for(int destinationCol = 0; destinationCol < 8; destinationCol++)
	  if(getSquare(sourceCol, sourceRow)->getColour() == colour) 
	    if(getSquare(sourceCol, sourceRow)->checkMove(sourceCol, sourceRow, destinationCol, destinationRow, *this) == true){
	      Piece* sourcePiece = getSquare(sourceCol, sourceRow);
	      if(checkCheck(colour, sourceCol, sourceRow, destinationCol, destinationRow, sourcePiece, *this) == false)
		return false;
	    }
	}

  return true;
}
  


	    
	  


bool ChessBoard::checkCheck(Colour colour, int sourceCol, int sourceRow, int destinationCol, int destinationRow, Piece* sourcePiece, ChessBoard testBoard){
  testBoard.squares[sourceRow][sourceCol] = nullptr;
  testBoard.squares[destinationRow][destinationCol] = sourcePiece;

  if(testBoard.isInCheck(colour) == true)
    return true;

  return false;


}

  
void ChessBoard::resetBoard(){

  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      squares[i][j] = nullptr;

  for (int j = 0; j < 8; j++)
    squares[1][j] = whitePieces[0];

  squares[0][0] = whitePieces[1];
  squares[0][1] = whitePieces[2];
  squares[0][2] = whitePieces[3];
  squares[0][3] = whitePieces[4];
  squares[0][4] = whitePieces[5];
  squares[0][5] = whitePieces[3];
  squares[0][6] = whitePieces[2];
  squares[0][7] = whitePieces[1];

  for (int j = 0; j < 8; j++)
    squares[6][j] = blackPieces[0];

  squares[7][0] = blackPieces[1];
  squares[7][1] = blackPieces[2];
  squares[7][2] = blackPieces[3];
  squares[7][3] = blackPieces[4];
  squares[7][4] = blackPieces[5];
  squares[7][5] = blackPieces[3];
  squares[7][6] = blackPieces[2];
  squares[7][7] = blackPieces[1];

  cout << "A new chess game is started!" << endl;

  turn = WHITE;
  
}


void ChessBoard::printBoard(){
  cout << " ";
  for(char x = 'A'; x != 'H'+1; x++){
    cout <<"|"<< x <<"";
  }
  cout << "|" << endl;

  for(int ranks = 7; ranks >= 0; ranks--){
    cout << ranks +1 << "|";
    for(int files = 0; files < 8; files++){
      cout << "_";

      // This is where the actual pawns are outputted.                                                                                                                                                      

      if(squares[ranks][files] != nullptr){
        switch(squares[ranks][files]->getPieceType()){
        case PAWN:
          if(squares[ranks][files]->getColour() == WHITE) cout << "P";
          else cout << "p";
          break;
        case KNIGHT:
          if(squares[ranks][files]->getColour() == WHITE) cout << "N";
          else cout << "n";
          break;
        case BISHOP:
          if(squares[ranks][files]->getColour() == WHITE) cout << "B";
          else cout << "b";
          break;
        case ROOK:
          if(squares[ranks][files]->getColour() == WHITE) cout << "R";
          else cout << "r";
          break;
        case QUEEN:
          if(squares[ranks][files]->getColour() == WHITE) cout << "Q";
          else cout << "q";
          break;
        case KING:
          if(squares[ranks][files]->getColour() == WHITE) cout << "K";
          else cout << "k";
          break;
        default:
          cout << "_";
        }}else{ cout << "_"; }


      cout << "_|";
    }
    cout << endl;
  }
}
