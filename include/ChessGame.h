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

	// Destructor
	~ChessGame()
	{

	}
	void movepiece(uint32_t x, uint32_t y);
private:
	SDL_Handler* m_handler = nullptr;
	//BLACK PIECES
	Queen m_BlackQueen;
	King m_BlackKing;
	Knight m_BlackKnight1;
	//Knight m_BlackKnight2;
	std::vector<Pawn> m_bpvector;
	std::vector<Rook> m_brvector;
	//WHITE PIECES
	Queen m_WhiteQueen;
	King  m_WhiteKing;
	Knight m_WhiteKnight1;
	//Knight m_WhiteKnight2;
	std::vector<Pawn> m_wpvector;
	//TO DO : REMOVE ROOK VECTORS AND INITIALIZE THEM USING INITIALIZER LIST..
	std::vector<Rook> m_wrvector;
};

