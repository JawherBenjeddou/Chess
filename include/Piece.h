#pragma once
#include"SDL_Handler.h"
#include <utility>

class Piece
{
public:
	// Constructor
	explicit Piece(SDL_Renderer* renderer, const char* Path , std::pair<int,int > &pos)
	{
		m_Renderer = renderer;
		m_PATH = Path;
		m_dst_rect.x = pos.first;
		m_dst_rect.y = pos.second;
	}
	//Default Constructor 
	
	Piece();

	// Destructor
	~Piece() {}

	//render this piece
	void LoadPiece();

	//Gets called every frame To Render Updated texture onto the screen
	void UpdatePiece();

	//Get Piece Surface
	 SDL_Surface* GetSurface() const { return m_surface_piece; }

	//Get Piece Texture
	 SDL_Texture* GetTexture() const { return m_texture_piece; }
	
	//Get Renderer
	 SDL_Renderer* GetRenderer() const { return m_Renderer; }
	
	//Get Piece Rect
	  SDL_Rect* GetRect()  const { return &m_dst_rect; }

private:

	//SDL_Handler Renderer
	SDL_Renderer* m_Renderer = nullptr;

	//PATH to the ASSET used
	const char* m_PATH = nullptr;

	
	// Surface that contains the piece
	SDL_Surface* m_surface_piece = nullptr;

	//Texture that handles the piece
	SDL_Texture* m_texture_piece = nullptr;
	//Rect used For piece movement and size etc..
	mutable SDL_Rect m_dst_rect = { 0 };
};