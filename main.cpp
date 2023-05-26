#undef main
#include <SDL.h>
#include "bird.h"
#include <iostream>

int main(int argc, char* args[]) {

    const static int SCREEN_HEIGHT = 480;
    const static int SCREEN_WIDTH = 640;


    // Create the window 
    SDL_Window* window = SDL_CreateWindow("FlappyBird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);

    // Create the renderer
    SDL_Renderer* gameRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Set the color to draw rectangles
    SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Load in the bird textures
    SDL_Surface* birdSurface = SDL_LoadBMP("wingUp.bmp");
    SDL_Surface* birdSurface2 = SDL_LoadBMP("wingDown.bmp");

    // Create the bird textures
    SDL_Texture* wingUpTexture = SDL_CreateTextureFromSurface(gameRenderer, birdSurface);
    SDL_Texture* wingDownTexture = SDL_CreateTextureFromSurface(gameRenderer, birdSurface2);

    // Check if the textures have loaded 
    if (wingUpTexture == NULL) {
        std::cout << "wingUpTexture not loaded" << std::endl;
    }
    else {
        std::cout << "wingUpTexture loaded" << std::endl;
    }
    if (wingDownTexture == NULL) {
        std::cout << "wingDownTexture has not loaded" << std::endl;
    }
    else {
        std::cout << "wingDownTexture loaded" << std::endl;
    }

    // Needed conditions and variables
    SDL_Event event;
    bool gameActive = true;
    int TimeStarted = SDL_GetTicks();


    // Create an instance of the bird
    Bird* flappy = new Bird(50.0, 70.00, 30.5, 0.1);

    // Start of the game loop
    while (gameActive) {


        // Event handler to check if SDL has been quit
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
            {
                bool quit = true;
            }
        }
        SDL_RenderClear(gameRenderer);

        // Clear the renderer 
        SDL_Texture* birdTexture = TimeStarted % 500 > 250 ? flappy->wingUpTexture : flappy->wingDownTexture;
        SDL_RenderCopy(gameRenderer, wingUpTexture, NULL, flappy->BirdRect);

        SDL_RenderPresent(gameRenderer);

    }



    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}

// Tasks Todo

// [] Place bird on screen
// [] Gravity on the bird
// [] Bird movement with spacebar
// [] Place background
// [] Place pipes on screen 
// [] Pipe movement
// [] Bird collision with pipes
// [] Pipe movement 
// [] Vary the pipe heights
// [] 

// --------------------------------