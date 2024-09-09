#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char* argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(SDL_INIT_EVERYTHING);

	// Creating a Window
	SDL_Window* window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
	if (!window) {
		std::cout << "Window failed to init: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return -1;
	}

	// Creating a Renderer
	SDL_Renderer* ren = SDL_CreateRenderer(window, -1, 0);
	if (!ren) {
		std::cout << "Renderer failed to init: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	// SDL2's Event capture
	SDL_Event e;

	// Player Rectangle
	SDL_Rect r;

	// Player Rectangle Decelaration
	r.w = 100;
	r.h = 100;
	r.x = 100;
	r.y = 100;

	// Game is running
	bool running = true;

	// Main Loop
	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			// Window Close handeler
			if (e.type == SDL_QUIT) { running = false; }
			
			// Player Movement Handler
			else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
					r.y -= 10;
					break;

				case SDLK_s:
					r.y += 10;
					break;

				case SDLK_a:
					r.x -= 10;
					break;

				case SDLK_d:
					r.x += 10;
					break;
				}
			}

		}

		// Setting the background Color to black
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);

		// Setting the player color to Grenn
		SDL_SetRenderDrawColor(ren, 0, 234, 0, 255);
		// Creating the player
		SDL_RenderFillRect(ren, &r);

		SDL_RenderPresent(ren);

	}

	// Cleaning up
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}