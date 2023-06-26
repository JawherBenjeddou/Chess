#include "ChessGame.h"
ChessGame::ChessGame(SDL_Handler* HANDLER) :
	m_BR1{ HANDLER->GetRenderer(), std::make_pair(16, 15) },
	m_BR2{ HANDLER->GetRenderer(), std::make_pair(546, 15) },
	m_BKnight{ HANDLER->GetRenderer(), std::make_pair(472, 15) },
	m_BKnight2{ HANDLER->GetRenderer(), std::make_pair(92, 15) },
	m_BB{ HANDLER->GetRenderer(), std::make_pair(396, 15) },
	m_BB2{ HANDLER->GetRenderer(), std::make_pair(168, 15) },
	m_BKing{ HANDLER->GetRenderer(), std::make_pair(320, 15) },
	m_BQ{ HANDLER->GetRenderer(), std::make_pair(244, 15) },
	m_WR1{ HANDLER->GetRenderer(), std::make_pair(16, 545), "assets/RookW.png" },
	m_WR2{ HANDLER->GetRenderer(), std::make_pair(546, 545), "assets/RookW.png" },
	m_WKnight{ HANDLER->GetRenderer(), std::make_pair(472, 545), "assets/KnightW.png" },
	m_WKnight2{ HANDLER->GetRenderer(), std::make_pair(92, 545), "assets/KnightW.png" },
	m_WKing{ HANDLER->GetRenderer(), std::make_pair(320, 545), "assets/KingW.png" },
	m_WB{ HANDLER->GetRenderer(), std::make_pair(396, 545), "assets/BishopW.png" },
	m_WB2{ HANDLER->GetRenderer(), std::make_pair(168, 545), "assets/BishopW.png" },
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

void ChessGame::UpdateGameState()
{
	
}

void ChessGame::UpdatePieces()
{
	for (size_t i = 0; i < 8; i++)
	{
		m_bpvector[i].MovePiece(92,200);
	}

}