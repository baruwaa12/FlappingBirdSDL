#undef main
#include <SDL.h>
#include "bird.h"
#include <iostream>
#include <chrono>
#include <thread>

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
    bool birdActive = true;
    const int GRAVITY_INTERVAL_MS = 16; // Gravity update interval in milliseconds

    auto startTime = std::chrono::steady_clock::now();

    // Create an instance of the bird
    Bird* flappy = new Bird(50.0, 70.00, 1.5, 1.05);

    // Start of the game loop
    while (gameActive) {

        // Event handler to check if SDL has been quit
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
            {
                bool quit = true;
            }
        }

        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
        

        if (elapsedTime >= GRAVITY_INTERVAL_MS) {
            flappy->flyDown();
            startTime = std::chrono::steady_clock::now();
        }

        // Clear the renderer 
        SDL_RenderClear(gameRenderer);
        // SDL_Texture* birdTexture = TimeStarted % 500 > 250 ? flappy->wingUpTexture : flappy->wingDownTexture;

        // Render all animating objects (Birds, pipes etc)
        //> SDL_RenderCopy(gameRenderer, flappy->currentTexture, NULL, flappy->BirdRect);
        //> SDL_RenderCopy(gameRenderer, dog->currentTexture, NULL, dog->rect);

        SDL_RenderCopy(gameRenderer, wingUpTexture, NULL, flappy->BirdRect);
        SDL_RenderPresent(gameRenderer);

        // Give time to the CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}

// Tasks Todo

// [x] Place bird on screenc
// [x] Gravity on the bird
// [] Bird movement with spacebar
// [] Place background
// [] Place pipes on screen 
// [] Pipe movement
// [] Bird collision with pipes
// [] Pipe movement 
// [] Vary the pipe heights
// [] 

// --------------------------------