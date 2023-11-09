#pragma once
#include "Piece.h"

class Rook :
    public Piece
{
public:
    // Constructor
    Rook(Team team, std::pair<int, int> pos, SDL_Handler* handler);

    // prints name of piece
    void sayMyName();

    // Destructor
    ~Rook();

    // calculates the possible moves
    void calcPossibleMoves(Piece* field[8][8], bool checkCheck);
};



