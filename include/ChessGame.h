#pragma once
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"

class ChessGame
{
public:
	// Constructor
	explicit ChessGame(SDL_Handler* HANDLER);

	void movepiece(uint32_t x, uint32_t y);
	
private:
	SDL_Handler* m_handler = nullptr;
	//BLACK PIECES
	/*Queen m_BlackQueen;
	King m_BlackKing;
	Knight m_BlackKnight1;
	Knight m_BlackKnight2;

	//WHITE PIECES
	Queen m_WhiteQueen;
	King  m_WhiteKing;
	Knight m_WhiteKnight1;
	Knight m_WhiteKnight2;*/
	//BLACK ROOKS
	//Rook *m_BlackRook1;
	//Rook *m_BlackRook2;
	////WHITE ROOKS
	//Rook m_WhiteRook1;
	//Rook m_WhiteRook2;
	//PAWNS
	std::vector<Pawn> m_wpvector;
	std::vector<Pawn> m_bpvector;

};

