#pragma once

#include "SDL_Handler.h"
#include "ChessGame.h"

namespace Chess {

	void Run()
	{
		SDL_Event* Event = new SDL_Event();
		SDL_Handler* Handler = new SDL_Handler();
		
		bool isRunning = true;

		ChessGame Game(Handler);
		while (isRunning)
		{
			while (SDL_PollEvent(Event) != 0)
			{
				if (Event->type == SDL_QUIT)
				{
					isRunning = false;
				}
			}
			int32_t mouseX, mouseY;
			Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
			std::cout << mouseX << " " << mouseY << std::endl;
			Handler->UpdateBoard();
			Game.UpdateGameState(mouseX,mouseY);
			// Present the renderer
			SDL_RenderPresent(Handler->GetRenderer());
	}
		Handler->CleanUp();
		delete Handler;
		Handler = nullptr;
	}
}