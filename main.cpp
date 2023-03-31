//basic init function
#include <SDL.h>
#include <iostream>
#include "bird.hpp"
#include "pipe.hpp"


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

  // Load in the pipe texture
  SDL_Surface* pipeSurface = SDL_LoadBMP("pipeDown.bmp");

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

  // Check if the pipe texture loaded
  if (pipeSurface == NULL) {
    std::cout<<"Pipe surface not loaded" <<std::endl;
  }else{
    std::cout<<"Pipe surface loaded"<<std::endl;
  }

  // New instance of my Bird Class
  Bird* flappy = new Bird(50,50,30.5,0.1);

  Pipe *Fpipe = new Pipe(100, 40, 30.5);
  
  Fpipe->pipeUp = SDL_CreateTextureFromSurface(renderer, pipeSurface);

  flappy->wingUpTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);

  flappy->wingDownTexture = SDL_CreateTextureFromSurface(renderer, birdSurface2);

  SDL_Event event;
  bool space_bar_hit = false;
  while (true) {
    // Listen for the space bar key event
    // If the Space Bar is pressed. Call the 
    while( SDL_PollEvent(&event))
    {
      // User requests quit
      if (event.type == SDL_KEYDOWN )
      {
        switch (event.key.keysym.sym) 
        {
          case SDLK_SPACE:
            space_bar_hit = true;
            flappy->flyUp();
            break;
          default:
          
            break;
        }
      }
      // Not a key down - need to move on to the game loop
      break;
    }

    if(space_bar_hit == false){
      flappy->flyDown();
    }else{
      space_bar_hit = false;
    }
    
    int TimeStarted = SDL_GetTicks();
    SDL_Rect* birdReact = new SDL_Rect();
    birdReact->x = flappy->getX();
    birdReact->y = flappy->getY();
    birdReact->h = 32;
    birdReact->w = 32;

    SDL_Rect *pipeRect = new SDL_Rect();
    pipeRect->x = Fpipe->getX();
    pipeRect->y = Fpipe->getY();
    pipeRect->h = 114;
    pipeRect->w = 60;
    
    

    SDL_RenderClear(renderer);
        
    SDL_RenderCopy(renderer, TimeStarted % 500 > 250 ? flappy->wingUpTexture : flappy->wingDownTexture, NULL, birdReact);

    SDL_RenderCopy(renderer, Fpipe->pipeUp,  NULL, pipeRect);

    SDL_RenderPresent(renderer);

    
  }

  SDL_DestroyWindow( window );
  
  SDL_Quit();

  return 0;
}

// Todo
// [ ] Commit in my new repo or overwrite an one of my old repos
// [x] Get bird to drop by gravity 
// [x] When I tab on the space bar bird goes up
// [ ] Pipe scroll on the screen moving from the right to left
// [ ] Bird collision with pipes
// [ ] Sound effects
// [ ] In game timer
// [x] Make movement less janky
// [ ] Start screen and game over
// [ ] Buttons to restart
// --------------------------------