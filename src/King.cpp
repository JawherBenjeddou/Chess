#include "King.h"



//TO DO : FIGURE OUT HOW TO MOVE THE KING
void King::PossibleMoves(Piece* ChessBoard[8][8])
{
	uint16_t row = getPosition(ChessBoard).first;
	uint16_t col = getPosition(ChessBoard).second;

	// Check all neighboring cells
	for (uint16_t i = __MAX(0, row - 1); i <= __MIN(7, row + 1); i++)
	{
		for (uint16_t j = __MAX(0, col - 1); j <= __MIN(7, col + 1); j++)
		{
			if (i == row && j == col)
			{
				continue;  // Skip the current position
			}
			if (ChessBoard[i][j] == nullptr)
			{
				std::cout << i << "," << j << " => is valid position  \n";
			}
		}
	}
}

/*
	black king (0.4)
	white king (7.4)
	what needs to be free?
	black king 0.3 ,0.5 ,1.3 ,1.4, 1.5
*/