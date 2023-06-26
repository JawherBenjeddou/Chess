#pragma once
#include"SDL_Handler.h"
#include <utility>
#define SUPER Piece

class Piece
{
public:
	// Constructor
	explicit Piece(SDL_Renderer* renderer, const char* Path , std::pair<int,int > &pos)
	{
		m_Renderer = renderer;
		m_PATH = Path;
		posx = pos.first;
		posy = pos.second;
	}

	// Destructor
	~Piece() {}

	//render this piece
	void LoadPiece();

	//Gets called every frame To Render Updated texture onto the screen
	void UpdatePiece();

	void MovePiece(int32_t x, int32_t y);
	//Get Piece Surface
	 SDL_Surface* GetSurface() const { return m_surface_piece; }

	//Get Piece Texture
	 SDL_Texture* GetTexture() const { return m_texture_piece; }
	
	//Get Renderer
	 SDL_Renderer* GetRenderer() const { return m_Renderer; }
	
	//Get Piece Rect
	  SDL_Rect* GetRect()  const { return &m_dst_rect; }
private:

	//Initial Position
	std::pair<int, int> POS;

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
public:
	uint32_t posx = 0;
	uint32_t posy = 0;
	
};