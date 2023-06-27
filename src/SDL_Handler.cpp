#include"SDL_Handler.h"

SDL_Handler::SDL_Handler()
{
	RenderBoard();
}

void SDL_Handler::RenderBoard()
{
	m_window = SDL_CreateWindow("CHESS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	// set the window flags to be movable but not resizable
	SDL_SetWindowResizable(m_window, SDL_FALSE);
	SDL_SetWindowBordered(m_window, SDL_TRUE);

	//Checks if there are init errors
	if (init() == false)
	{
		return;
	}

	//Load Chess Board Texture and Surface
	LoadBoard();
}

void SDL_Handler::LoadBoard()
{
	m_surface_board = IMG_Load("assets/Chess_Wood.png");
	if (!m_surface_board)
	{
		std::cerr << "Failed to load Board : " << IMG_GetError() << std::endl;
		return;
	}
	m_texture_board = SDL_CreateTextureFromSurface(m_renderer, m_surface_board);

	// Set destination rectangle
	m_dst_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	//Clear the screen
	SDL_RenderClear(m_renderer);

	// Render the texture onto the screen
	SDL_RenderCopy(m_renderer, m_texture_board, nullptr, &m_dst_rect);

}

//called every frame after piece updated
void SDL_Handler::UpdateBoard()
{
	SDL_RenderClear(m_renderer);

	// Render the texture onto the screen
	SDL_RenderCopy(m_renderer, m_texture_board, nullptr, &m_dst_rect);

	// Update the screen
	SDL_RenderPresent(m_renderer);
}


bool SDL_Handler::init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error : %s\n", SDL_GetError());
		CleanUp();
		return false;
	}
	if (m_renderer == nullptr)
	{
		// Handle Renderer Creation failure
		std::cerr << "Renderer Creation Error :  %s\n" << SDL_GetError() << std::endl;
		// Handle initialization failure
		return false;
	}
	if (m_window == nullptr)
	{
		// Handle Window Creation failure
		std::cerr << "Window Creation Error :  %s\n" << SDL_GetError() << std::endl;
		// Handle initialization failure
		return false;
	}
	return true;
}

void SDL_Handler::CleanUp()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_DestroyTexture(m_texture_board);
	SDL_FreeSurface(m_surface_board);
	SDL_Quit();
}
