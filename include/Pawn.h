#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	//Default constructor
	Pawn();
	// Constructor
	Pawn(SDL_Renderer* renderer,std::pair<int,int> pos, const char* Path = "assets/PawnB.png") 
		: SUPER(renderer, Path, pos)// Call parent constructor using initializer list
	{
		LoadPiece();
	}
	// Destructor
	~Pawn() {}
};

