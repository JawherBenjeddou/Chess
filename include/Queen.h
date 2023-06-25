#pragma once
#include "Piece.h"



class Queen : public Piece
{
public:

	// Constructor
	Queen(SDL_Renderer* renderer, std::pair<int, int> pos, const char* Path = "assets/QueenB.png") : 
		SUPER(renderer, Path, pos) // Call parent constructor using initializer list
	{
		LoadPiece();
	}
	//Default Constructor 
	Queen();

};

