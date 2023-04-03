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

  // Load in the background texture
  SDL_Surface* bgSurface = SDL_LoadBMP("background1.bmp");

  SDL_Texture* background = NULL;

  // Load in the pipe texture
  SDL_Surface* pipeSurface = SDL_LoadBMP("pipe_Up.bmp");
  
  SDL_Surface* bottomPipeSurface = SDL_LoadBMP("pipe_Down.bmp");

  SDL_Surface* pipeSurface2 = SDL_LoadBMP("pipe_Up.bmp");
  
  SDL_Surface* bottomPipeSurface2 = SDL_LoadBMP("pipe_Down.bmp");

  SDL_Surface* pipeSurface3 = SDL_LoadBMP("pipe_Up.bmp");
  
  SDL_Surface* bottomPipeSurface3 = SDL_LoadBMP("pipe_Down.bmp");
  
  
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
  if (pipeSurface == NULL)  {
    std::cout<<"Pipe surface not loaded" <<std::endl;
  }else{
    std::cout<<"Pipe surface loaded"<<std::endl;
  }

  // New instance of my Bird Class
  Bird* flappy = new Bird(50,50,30.5,0.1);

  Pipe *Tpipe = new Pipe(670, -300, 0.05);
  Pipe *Bpipe = new Pipe(670, 200, 0.05);

  Pipe *Tpipe2 = new Pipe(Tpipe->getX() + 200, -300, 0.05);
  Pipe *Bpipe2 = new Pipe(Tpipe->getX() + 200, 200, 0.05);

  Pipe *Tpipe3 = new Pipe(Tpipe2->getX() + 200, -300, 0.05);
  Pipe *Bpipe3 = new Pipe(Tpipe2->getX() + 200, 200, 0.05);

  
  background = SDL_CreateTextureFromSurface(renderer, bgSurface);
  
  Tpipe->pipeTexture = SDL_CreateTextureFromSurface(renderer, pipeSurface);
  Bpipe->pipeTexture = SDL_CreateTextureFromSurface(renderer, bottomPipeSurface);
 
  Tpipe2->pipeTexture = SDL_CreateTextureFromSurface(renderer, pipeSurface2);
  Bpipe2->pipeTexture = SDL_CreateTextureFromSurface(renderer, bottomPipeSurface2);

  Tpipe3->pipeTexture = SDL_CreateTextureFromSurface(renderer, pipeSurface3);
  Bpipe3->pipeTexture = SDL_CreateTextureFromSurface(renderer, bottomPipeSurface3);
  
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
    Tpipe->moveLeft();
    Bpipe->moveLeft();
    
    Tpipe2->moveLeft();
    Bpipe2->moveLeft();

    Tpipe3->moveLeft();
    Bpipe3->moveLeft();

    SDL_Rect* bgRect = new SDL_Rect();
    bgRect->x = 0;
    bgRect->y = 0;
    bgRect->h = 480;
    bgRect->w = 640;
    
    
    int TimeStarted = SDL_GetTicks();
    SDL_Rect* birdReact = new SDL_Rect();
    birdReact->x = flappy->getX();
    birdReact->y = flappy->getY();
    birdReact->h = 32;
    birdReact->w = 32;

    SDL_Rect *pipeRect = new SDL_Rect();
    pipeRect->x = Tpipe->getX();
    pipeRect->y = Tpipe->getY();
    pipeRect->h = 402;
    pipeRect->w = 60;

    SDL_Rect *pipeRect2 = new SDL_Rect();
    pipeRect2->x = Bpipe->getX();
    pipeRect2->y = Bpipe->getY();
    pipeRect2->h = 402;
    pipeRect2->w = 60;

    SDL_Rect *pipeRect3 = new SDL_Rect();
    pipeRect3->x = Tpipe2->getX();
    pipeRect3->y = Tpipe2->getY();
    pipeRect3->h = 402;
    pipeRect3->w = 60;

    SDL_Rect *pipeRect4 = new SDL_Rect();
    pipeRect4->x = Bpipe2->getX();
    pipeRect4->y = Bpipe2->getY();
    pipeRect4->h = 402;
    pipeRect4->w = 60;

    SDL_Rect *pipeRect5 = new SDL_Rect();
    pipeRect5->x = Tpipe3->getX();
    pipeRect5->y = Tpipe3->getY();
    pipeRect5->h = 402;
    pipeRect5->w = 60;

    SDL_Rect *pipeRect6 = new SDL_Rect();
    pipeRect6->x = Bpipe3->getX();
    pipeRect6->y = Bpipe3->getY();
    pipeRect6->h = 402;
    pipeRect6->w = 60;


    SDL_RenderClear(renderer);

    // Background render 
    SDL_RenderCopy(renderer, background, NULL, bgRect);
        
    SDL_RenderCopy(renderer, TimeStarted % 500 > 250 ? flappy->wingUpTexture : flappy->wingDownTexture, NULL, birdReact);

    // First pipe pair render
    SDL_RenderCopyEx(renderer, Tpipe->pipeTexture,  NULL, pipeRect, 180, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopy(renderer, Bpipe->pipeTexture,  NULL, pipeRect2);

    // Second pipe pair render
    SDL_RenderCopyEx(renderer, Tpipe2->pipeTexture,  NULL, pipeRect3, 180, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopy(renderer, Bpipe2->pipeTexture,  NULL, pipeRect4);

    // Third pipe pair render
    SDL_RenderCopyEx(renderer, Tpipe3->pipeTexture,  NULL, pipeRect5, 180, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopy(renderer, Bpipe3->pipeTexture,  NULL, pipeRect6);
    
    SDL_RenderPresent(renderer);

  }

  SDL_DestroyWindow( window );
  
  SDL_Quit();

  return 0;
}

// Todo
// [x] Commit in my new repo or overwrite an one of my old repos
// [x] Get bird to drop by gravity 
// [x] Make movement less janky
// [x] When I tab on the space bar bird goes up
// [x] Pipe scroll on the screen moving from the right to left
// [x] Get multiple pipes to scroll across the window
// [x] Randomise the height of the pipes
// [ ] Moving Background
// [ ] Multi ring placement
// [ ] Bird collision with pipes
// [ ] Background sound
// [ ] Sound for ring collision 
// [ ] Ring disappers on collision
// [ ] In game timer
// [ ] Start screen and game over
// [ ] Buttons to restart
//
// --------------------------------