#pragma once
#include "Piece.h"



class Knight : public Piece
{
public:
	// Constructor
	Knight(SDL_Renderer* renderer, std::pair<int, int> pos, const char* Path = "assets/KnightB.png")
		: SUPER(renderer, Path, pos) // Call parent constructor using initializer list
	{
		LoadPiece();
	}				

	// Destructor
	~Knight();
};

