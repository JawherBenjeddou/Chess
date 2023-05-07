#include "Piece.h"

void Piece::LoadPiece()
{
	m_surface_piece = IMG_Load(m_PATH);
	if (!m_surface_piece)
	{
		std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
		return;
	}
	m_texture_piece = SDL_CreateTextureFromSurface(m_Renderer, m_surface_piece);
	m_dst_rect.x = posx;
	m_dst_rect.y = posy;
	m_dst_rect.w = PIECE_SIZE;
	m_dst_rect.h = PIECE_SIZE;
	SDL_RenderCopy(m_Renderer, m_texture_piece, nullptr, &m_dst_rect);
	SDL_RenderPresent(m_Renderer);
}

void Piece::CalledEveryFrame()
{
	// Set destination rectangle
	m_dst_rect.x = posx;
	m_dst_rect.y = posy;
	// Render the texture onto the screen
	SDL_RenderCopy(m_Renderer, m_texture_piece, nullptr, &m_dst_rect);
	SDL_RenderPresent(m_Renderer);
}