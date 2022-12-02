chess: ChessMain.o ChessBoard.o Piece.o Pawn.o King.o Rook.o Bishop.o Queen.o Knight.o
	g++ ChessMain.o ChessBoard.o Piece.o Pawn.o King.o Rook.o Bishop.o Queen.o Knight.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h Piece.h
	g++ -c -g -Wall ChessMain.cpp

Piece.o: Piece.cpp Piece.h ChessBoard.h
	g++ -c -g -Wall Piece.cpp

ChessBoard.o: ChessBoard.cpp Piece.h ChessBoard.h
	g++ -c -g -Wall ChessBoard.cpp

Pawn.o: Pawn.cpp Pawn.h Piece.h ChessBoard.h
	g++ -c -g -Wall Pawn.cpp

King.o: King.cpp King.h Piece.h ChessBoard.h
	g++ -c -g -Wall King.cpp

Rook.o: Rook.cpp Rook.h Piece.h ChessBoard.h
	g++ -c -g -Wall Rook.cpp

Bishop.o: Bishop.cpp Bishop.h Piece.h ChessBoard.h
	g++ -c -g -Wall Bishop.cpp

Queen.o: Queen.cpp Queen.h Piece.h ChessBoard.h
	g++ -c -g -Wall Queen.cpp

Knight.o: Knight.cpp Knight.h Piece.h ChessBoard.h
	g++ -c -g -Wall Knight.cpp

