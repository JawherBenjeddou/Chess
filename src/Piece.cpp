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

std::pair<uint16_t, uint16_t> Piece::getPosition(Piece* ChessBoard[8][8]) {
	for (uint16_t row = 0; row < 8; row++) {
		for (uint16_t col = 0; col < 8; col++) {
			if (ChessBoard[row][col] == (this)) {
				return std::make_pair(row, col);
			}
		}
	}

	// Piece not found, return an invalid position
	return std::make_pair(-1, -1);
}