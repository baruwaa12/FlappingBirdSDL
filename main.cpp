//basic init function
#include <SDL.h>
#include <iostream>
#include "bird.hpp"


// Load image as a texture
SDL_Texture *loadTexture(std::string path);

// Window to render to
SDL_Renderer *gameRenderer = NULL;

int main()
{
  //start of colour loop var
  int r = 255;
  int g = 0;
  int b = 0;

  bool sec1 = true;
  const static int SCREEN_HEIGHT = 480;  
  const static int SCREEN_WIDTH = 640;
  
  SDL_Window* window;
  SDL_Renderer* renderer;

  window = SDL_CreateWindow( "Flappy Chicken", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  // loading bird texture
  SDL_Surface* birdSurface = SDL_LoadBMP("wingUp.bmp");

  SDL_Surface* birdSurface2 = SDL_LoadBMP("wingDown.bmp");

  // Did the bird surface load?
  if( birdSurface == NULL) {
    std::cout<<"Bird surface not loaded" << std::endl;
  }
  if (birdSurface2 == NULL ) {
    std::cout<<"Bird surface 2 not loaded" << std::endl;
  }
  else{
    std::cout<<"Bird surfaces loaded" << std::endl;
  }

  // New instance of my Bird Class
  Bird* flappy = new Bird(50,50);

  flappy->wingUpTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);

  flappy->wingDownTexture = SDL_CreateTextureFromSurface(renderer, birdSurface2);
  
  while (true) {

   int TimeStarted = SDL_GetTicks();
    
    SDL_Rect* birdReact = new SDL_Rect();
    birdReact->x = 50;
    birdReact->y = 50;
    birdReact->h = 32;
    birdReact->w = 32;

    SDL_RenderClear(renderer);
        
    SDL_RenderCopy(renderer, TimeStarted % 500 > 250 ? flappy->wingUpTexture : flappy->wingDownTexture, NULL, birdReact);

    SDL_RenderPresent(renderer);
    
  }

  SDL_DestroyWindow( window );
  
  SDL_Quit();

  return 0;
}

// Todo
// Commit in new repo or overwrite existing repo
// Switch image every while
// Get bird to drop by gravity
// When I tab on the space bar bird goes up
// --------------------------------