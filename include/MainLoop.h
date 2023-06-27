#pragma once

#include "SDL_Handler.h"
#include "ChessGame.h"

namespace Chess {

	void Run()
	{
		SDL_Event* Event = new SDL_Event();
		SDL_Handler* Handler = new SDL_Handler();
		ChessGame Game(Handler);
		bool isRunning = true;

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
			std::cout << mouseX <<" " <<  mouseY << std::endl;
			Game.UpdateGameState(mouseX, mouseY);
	}
		Handler->CleanUp();
		delete Handler;
		Handler = nullptr;
	}
}