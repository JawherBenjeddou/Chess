#include "ChessGame.h"

ChessGame::ChessGame(SDL_Handler* HANDLER) 
{
	/*
	m_BlackRook1(HANDLER->GetRenderer(), std::make_pair(16, 15)),
		m_BlackRook2(HANDLER->GetRenderer(), std::make_pair(546, 15))*/
	m_handler = HANDLER;

	//BLACK PIECES
	//BLACK PAWNS
	uint32_t x = 16;
	for (size_t i = 0; i < 8; i++)
	{

		m_bpvector.push_back(Pawn(m_handler->GetRenderer(), std::make_pair(x, 85)));
		x += 76;
	}

	//WHITE PIECES
	//WHITE PAWNS
	int32_t px = 16;
	for (size_t i = 0; i < 8; i++)
	{
		m_wpvector.push_back(Pawn(m_handler->GetRenderer(), std::make_pair(px, 465), "assets/PawnW.png"));
		px += 76;
	}

	//WHITE ROOKS
	//x = 16;
	//for (size_t i = 0; i < 2; i++)
	//{

	//	m_brvector.push_back(Rook(m_handler->GetRenderer(), std::make_pair(x, 545), "assets/RookW.png"));
	//	x += 530;
	//}

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