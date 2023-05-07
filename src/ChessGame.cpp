#include "ChessGame.h"

ChessGame::ChessGame(SDL_Handler* HANDLER) :
    m_WhiteQueen{ HANDLER->GetRenderer(), std::make_pair(244, 545), "assets/QueenW.png" },
    m_WhiteKing{ HANDLER->GetRenderer(), std::make_pair(320, 545), "assets/KingW.png" },
    m_WhiteKnight1{ HANDLER->GetRenderer(), std::make_pair(95, 545), "assets/KnightW.png" },
    m_BlackQueen{ HANDLER->GetRenderer(), std::make_pair(244, 15) },
    m_BlackKing{ HANDLER->GetRenderer(), std::make_pair(320, 15), "assets/KingB.png" },
    m_BlackKnight1{ HANDLER->GetRenderer(), std::make_pair(95, 15), "assets/KnightB.png" }
{
    m_handler = HANDLER;

    //BLACK PIECES
    //BLACK PAWNS
    uint32_t x=16;
    for (size_t i = 0; i < 8; i++)
    {
       
        m_bpvector.push_back(Pawn(m_handler->GetRenderer(), std::make_pair(x, 85)));
        x += 76;
    }

    //BLACK ROOKS
    x = 16;
    for (size_t i = 0; i < 2; i++)
    {

        m_wrvector.push_back(Rook(m_handler->GetRenderer(), std::make_pair(x, 15)));
        x += 530;
    }
   
    //WHITE PIECES
    //WHITE PAWNS
    int32_t px = 16;
    for (size_t i = 0; i < 8; i++)
    {
        m_wpvector.push_back(Pawn(m_handler->GetRenderer(), std::make_pair(px, 465), "assets/PawnW.png"));
        px += 76;
    }

    //WHITE ROOKS
    x = 16;
    for (size_t i = 0; i < 2; i++)
    {

        m_brvector.push_back(Rook(m_handler->GetRenderer(), std::make_pair(x, 545),"assets/RookW.png"));
        x += 530;
    }

}

//TO DO : TRY A FUNCTION THAT UPDATES EVERYTHING EVERY LOOP 
void ChessGame::movepiece(uint32_t x, uint32_t y) 
{
    m_bpvector[5].posx = x;
    m_bpvector[5].posy = y;
    for (size_t i = 0; i < 8; i++)
    {
        m_bpvector[i].CalledEveryFrame();
    }
    m_handler->CalledEveryFrame();

}