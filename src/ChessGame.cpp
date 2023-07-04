#include "ChessGame.h"
ChessGame::ChessGame(SDL_Handler* HANDLER) :
	m_BR1{ new Rook(HANDLER->GetRenderer(), std::make_pair(16, 15)) },
	m_BR2{ new Rook(HANDLER->GetRenderer(), std::make_pair(548, 15)) },
	m_BKnight{ new Knight(HANDLER->GetRenderer(), std::make_pair(472, 15)) },
	m_BKnight2{ new Knight(HANDLER->GetRenderer(), std::make_pair(92, 15)) },
	m_BB{ new Bishop(HANDLER->GetRenderer(), std::make_pair(396, 15)) },
	m_BB2{ new Bishop(HANDLER->GetRenderer(), std::make_pair(168, 15)) },
	m_BKing{ new King(HANDLER->GetRenderer(), std::make_pair(320, 15)) },
	m_BQ{ new Queen(HANDLER->GetRenderer(), std::make_pair(244, 15)) },
	m_WR1{ new Rook(HANDLER->GetRenderer(), std::make_pair(16, 547), "assets/RookW.png") },
	m_WR2{ new Rook(HANDLER->GetRenderer(), std::make_pair(548, 547), "assets/RookW.png") },
	m_WKnight{ new Knight(HANDLER->GetRenderer(), std::make_pair(472, 547), "assets/KnightW.png") },
	m_WKnight2{ new Knight(HANDLER->GetRenderer(), std::make_pair(92, 547), "assets/KnightW.png") },
	m_WKing{ new King(HANDLER->GetRenderer(), std::make_pair(320, 547), "assets/KingW.png") },
	m_WB{ new Bishop(HANDLER->GetRenderer(), std::make_pair(396, 547), "assets/BishopW.png") },
	m_WB2{ new Bishop(HANDLER->GetRenderer(), std::make_pair(168, 547), "assets/BishopW.png") },
	m_WQ{ new Queen(HANDLER->GetRenderer(), std::make_pair(244, 547), "assets/QueenW.png") }
{
	m_handler = HANDLER;
	//BLACK PAWNS
	uint32_t x = 15;
	for (size_t i = 0; i < 8; i++)
	{

		m_bpvector.push_back(new Pawn(m_handler->GetRenderer(), std::make_pair(x, 91)));
		x += 76;	
	}

	//WHITE PAWNS
	int32_t px = 15;
	for (size_t i = 0; i < 8; i++)
	{
		m_wpvector.push_back(new Pawn(m_handler->GetRenderer(), std::make_pair(px, 471), "assets/PawnW.png"));
		px += 76;
	}
	generateChessboardMatrix();
	generatePosMatrix();
}

void ChessGame::generateChessboardMatrix()
{
	//BLACK PIECES
	m_Matrix[0][0] = m_BR1;
	m_Matrix[0][1] = m_BKnight;
	m_Matrix[0][2] = m_BB;
	m_Matrix[0][3] = m_BQ;
	m_Matrix[0][4] = m_BKing;
	m_Matrix[0][5] = m_BB2;
	m_Matrix[0][6] = m_BKnight2;
	m_Matrix[0][7] = m_BR2;
	//BLACK PIECES
	m_Matrix[7][0] = m_WR1;
	m_Matrix[7][1] = m_WKnight;
	m_Matrix[7][2] = m_WB;
	m_Matrix[7][3] = m_WQ;
	m_Matrix[7][4] = m_WKing;
	m_Matrix[7][5] = m_WB2;
	m_Matrix[7][6] = m_WKnight2;
	m_Matrix[7][7] = m_WR2;
	for (uint32_t row = 2; row < 7; row++)
	{
		for (uint32_t col = 0; col < 8; col++)
		{
			m_Matrix[row][col] = nullptr;
		}
		if (row == 5) break;
	}

}

void ChessGame::generatePosMatrix()
{
	int x=16 ,y = 15;
	for (uint16_t row = 0; row < 8; row++)
	{
		for (uint16_t col = 0; col< 8; col++)
		{
			m_PosMatrix[row][col] = std::make_pair(x, y);
				x += 76;
		}
		y += 76;
		x = 16;
	}

}

void ChessGame::UpdateGameState()
{
	//Update Board
	m_handler->UpdateBoard();
	//Update Pieces
	m_WKing->UpdatePiece();
	m_BR1->UpdatePiece();
	m_BR2->UpdatePiece();
	m_BKnight->UpdatePiece();
	m_BKnight2->UpdatePiece();
	m_BB->UpdatePiece();
	m_BB2->UpdatePiece();
	m_BQ->UpdatePiece();
	m_BKing->UpdatePiece();

	////WHITE PIECES
	m_WR1->UpdatePiece();
	m_WR2->UpdatePiece();
	m_WKnight->UpdatePiece();
	m_WKnight2->UpdatePiece();
	m_WB->UpdatePiece();

	m_WB2->UpdatePiece();
	m_WQ->UpdatePiece();
	for (size_t i = 0; i < 8; i++)
	{

		m_bpvector[i]->UpdatePiece();
	}

	for (size_t i = 0; i < 8; i++)
	{
		m_wpvector[i]->UpdatePiece();
	}
}

bool ChessGame::arePiecesColliding(const SDL_Rect& rect1, const SDL_Rect& rect2) {
	SDL_Rect intersection;
	return SDL_IntersectRect(&rect1, &rect2, &intersection) == SDL_TRUE;
}