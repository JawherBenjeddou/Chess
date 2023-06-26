#pragma once


#include<iostream>
#include<vector>
#include "SDL.h"
#include "Macros.h"
#include "SDL_image.h"
	class SDL_Handler
	{

	public:
		//Constructor
		SDL_Handler();
		//Creating board and loading all stuff
		void RenderBoard();

		//Loading Board on screen
		void LoadBoard();

		// cleans up SDL stuff
		void CleanUp();

		//Returns A message about the specific ERROR occured or true if everything worked
		bool init();

		//Gets called every frame To Render Updated texture onto the screen
		void UpdateBoard();

		//Get Window Renderer
		 SDL_Renderer* GetRenderer() const { return m_renderer; }

		//Get Window
		 SDL_Window* GetWindow() const { return m_window; }
	private:
		// window we'll be rendering to
		SDL_Window* m_window = nullptr;
		//Renderer used 
		SDL_Renderer* m_renderer = nullptr;
		// Surface that contains the board
		SDL_Surface* m_surface_board = nullptr;
		//Texture that handles the chess board
		SDL_Texture* m_texture_board = nullptr;

		SDL_Rect m_dst_rect ;
	};
