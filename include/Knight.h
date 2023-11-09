#pragma once
#include "Piece.h"

class Knight :
    public Piece
{
public:
    Knight(Team team, std::pair<int, int> pos, SDL_Handler* handler);

    // calls name an
    void sayMyName();

    // calculates the possible moves
    void calcPossibleMoves(Piece* field[8][8], bool checkCheck);
};

