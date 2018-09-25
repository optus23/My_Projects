#include "SDL/include/SDL.h"
#pragma comment(lib, "SDL/lib/x86/SDL2.lib")
#pragma comment(lib, "SDL/lib/x86/SDL2main.lib")



int main(int argc, char* argv[]) {
	int cont = 0;
	int x = 0;
	int y = 0;
	int down = 1;
	//INITIALIZE SDL2 
	SDL_Init(SDL_INIT_EVERYTHING);

	//WINDOW
	SDL_Window* window; 						   
	window = SDL_CreateWindow(// Create an application window with the following settings:
		"My Awesome Game",// window title                  
		SDL_WINDOWPOS_UNDEFINED,// initial x position          
		SDL_WINDOWPOS_UNDEFINED,// initial y position           
		640,// width, in pixels           '                    
		480,// height, in pixels                              
		SDL_WINDOW_SHOWN // flags - see below                 
	);
	
	//RENDER
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);// The window is open: could enter program loop here (see SDL_PollEvent()) We must call SDL_CreateRenderer in order for draw calls to affect this window.// Declare a pointer
	while (1) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);// Select the color for drawing. It is set to blue here.	
	SDL_RenderClear(renderer);// Clear the entire screen to our selected color.
	
		
		if (cont >= 100) {
			SDL_Rect rect = { x, y, 50, 50 }; // the rectangle
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderFillRect(renderer, &rect);
			SDL_RenderPresent(renderer);// Up until now everything was drawn behind the scenes. This will show the new, red contents of the window.


			if(y==455){
				down = 0;
			}

			if (down == 1) {
				y++;
			}
			if (y <= 0) {
				down = 1;
			}

			if (down == 0) {
				y--;
			}

			cont = 0;
		}
		else {
			SDL_RenderClear(renderer);// Clear the entire screen to our selected color.
			SDL_Rect rect = { x, y, 50, 50 }; // the rectangle
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderFillRect(renderer, &rect);
			SDL_RenderPresent(renderer);
			cont++;


		}
		

	
	}

	
	//SDL_Delay(3000);// Pause execution for 3000 milliseconds, for example
	

	
	
	//CLEAN UP
	SDL_DestroyWindow(window);// Close and destroy the window
	SDL_Quit();// Clean up
	
	return 0;
}


//int main(int argc, char ** argv)
//{
//	// variables
//
//	bool quit = false;
//	SDL_Event event;
//	int x = 360;
//	int y = 240;
//
//	// init SDL
//
//	SDL_Init(SDL_INIT_VIDEO);
//	SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
//	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
//
//	SDL_Surface * image = SDL_LoadBMP("Star.bmp");
//	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
//	SDL_FreeSurface(image);
//
//	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
//
//	// handle events
//
//	while (!quit)
//	{
//
//		x -= 4;
//		y += 4;
//		SDL_Rect rect = { x, y, 75, 75 };
//
//		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//		SDL_RenderFillRect(renderer, &rect);
//		SDL_RenderPresent(renderer);
//
//
//		SDL_RenderClear(renderer);
//		/*SDL_RenderCopy(renderer, texture, NULL, &dstrect);*/
//		
//	}
//
//	// cleanup SDL
//
//	
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//
//	return 0;
//}