#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	// Constructor
	Rook(SDL_Renderer* renderer, std::pair<int, int> pos, const char* Path = "assets/RookB.png") : 
		SUPER(renderer, Path, pos) // Call parent constructor using initializer list
	{
		LoadPiece();
	}

	//Default Constructor
	Rook();

};

