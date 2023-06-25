#include "ChessGame.h"
ChessGame::ChessGame(SDL_Handler* HANDLER) :
	m_BR1{ HANDLER->GetRenderer(), std::make_pair(16, 15) },
	m_BR2{ HANDLER->GetRenderer(), std::make_pair(546, 15) },
	m_BK{ HANDLER->GetRenderer(), std::make_pair(320, 15), "assets/KingB.png" },
	m_BQ{ HANDLER->GetRenderer(), std::make_pair(244, 15), "assets/QueenB.png" },
	m_WR1{ HANDLER->GetRenderer(), std::make_pair(16, 545), "assets/RookW.png" },
	m_WR2{ HANDLER->GetRenderer(), std::make_pair(320, 545), "assets/RookW.png" },
	m_WQ{ HANDLER->GetRenderer(), std::make_pair(244, 545), "assets/QueenW.png" }
{
	m_handler = HANDLER;

	//BLACK PAWNS
	uint32_t x = 16;
	for (size_t i = 0; i < 8; i++)
	{

		m_bpvector.push_back(Pawn(m_handler->GetRenderer(), std::make_pair(x, 85)));
		x += 76;
	}

	//WHITE PAWNS
	int32_t px = 16;
	for (size_t i = 0; i < 8; i++)
	{
		m_wpvector.push_back(Pawn(m_handler->GetRenderer(), std::make_pair(px, 465), "assets/PawnW.png"));
		px += 76;
	}


}

//TO DO : TRY A FUNCTION THAT UPDATES EVERYTHING EVERY LOOP 
void ChessGame::movepiece(uint32_t x, uint32_t y)
{
	m_bpvector[5].posx = x;
	m_bpvector[5].posy = y;
	for (size_t i = 0; i < 8; i++)
	{
		m_bpvector[i].CalledEveryFrame();
	}
	m_handler->CalledEveryFrame();

}