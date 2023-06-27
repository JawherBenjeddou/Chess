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

	void UpdateGameState(uint32_t x, uint32_t y);
private:

	SDL_Handler* m_handler = nullptr;

	//BLACK PIECES
	std::vector<Pawn> m_bpvector;
	Rook m_BR1;
	Rook m_BR2;
	Knight m_BKnight;
	Knight m_BKnight2;
	Bishop m_BB;
	Bishop m_BB2;
	Queen m_BQ;
	King  m_BKing;

	//WHITE PIECES
	std::vector<Pawn> m_wpvector;
	Rook m_WR1;
	Rook m_WR2;
	Knight m_WKnight;
	Knight m_WKnight2;
	Bishop m_WB;
	Bishop m_WB2;
	Queen m_WQ;
	King m_WKing;

};

