#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:

	// Constructor
	Bishop(SDL_Renderer* renderer, std::pair<int, int> pos, const char* Path = "assets/BishopB.png") 
		: SUPER(renderer, Path, pos) // Call parent constructor using initializer list
	{
		LoadPiece();
	}


	// Destructor
	~Bishop();

};

