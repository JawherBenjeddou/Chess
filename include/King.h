#pragma once
#include "Piece.h"






class King : public Piece
{
public:

	// Constructor
	King(SDL_Renderer* renderer, std::pair<int, int> pos, const char* Path = "assets/KingB.png") 
		: SUPER(renderer, Path, pos) // Call parent constructor using initializer list
	{
		LoadPiece();
	}
	King();

	void PossibleMoves(Piece* m_PosMatrix[8][8]) override;
};