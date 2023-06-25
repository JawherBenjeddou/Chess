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
	std::vector<Pawn> m_bpvector;
	Rook m_BR1;
	Rook m_BR2;
	Queen m_BQ;
	King  m_BK;

	//WHITE PIECES
	std::vector<Pawn> m_wpvector;
	Rook m_WR2;
	Rook m_WR1;
	Queen m_WQ;
	King  m_WK;

};

