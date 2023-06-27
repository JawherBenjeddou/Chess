#include "Piece.h"

void Piece::LoadPiece()
{
	m_surface_piece = IMG_Load(m_PATH);
	if (!m_surface_piece)
	{
		std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
		return;
	}

	// Set the blend mode for the loaded texture
	SDL_SetSurfaceBlendMode(m_surface_piece, SDL_BLENDMODE_BLEND);

	m_texture_piece = SDL_CreateTextureFromSurface(m_Renderer, m_surface_piece);
	m_dst_rect.w = PIECE_SIZE;
	m_dst_rect.h = PIECE_SIZE;
	SDL_RenderCopy(m_Renderer, m_texture_piece, nullptr, &m_dst_rect);
	SDL_RenderPresent(m_Renderer);
}

void Piece::UpdatePiece()
{
	// Render the texture onto the screen
	SDL_RenderCopy(m_Renderer, m_texture_piece, nullptr, &m_dst_rect);
	
}
void Piece::MovePiece(int32_t X,int32_t Y)
{
	m_dst_rect.x = X;
	m_dst_rect.y = Y;

}