#undef main
#include <SDL.h>
#include "bird.h"
#include "pipe.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

const int PIPE_GAP = 200;
const static int SCREEN_HEIGHT = 480;
const static int SCREEN_WIDTH = 640;

void renderPipes(SDL_Renderer* gameRenderer, std::vector<Pipe>& pipes, SDL_Texture* pipeTexture) {
    for (auto& pipe : pipes) {
        SDL_Rect upperPipeRect = { pipe.getX(), 0, pipe.getWidth(), pipe.getTopHeight() };
        SDL_Rect lowerPipeRect = { pipe.getX(), pipe.getBottomY(), pipe.getWidth(), pipe.getBottomHeight()};

        SDL_RenderCopy(gameRenderer, pipeTexture, NULL, &upperPipeRect);  // Render upper pipe
        SDL_RenderCopy(gameRenderer, pipeTexture, NULL, &lowerPipeRect);  // Render lower pipe
    }
}

void newPipe(std::vector<Pipe>& pipes) {
    Pipe newPipe(SCREEN_WIDTH);
    pipes.push_back(newPipe);

}

int main(int argc, char* args[]) {

    // Create the window 
    SDL_Window* window = SDL_CreateWindow("FlappyBird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);

    // Create the renderer
    SDL_Renderer* gameRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Set the color to draw rectangles
    SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Load in the bird textures
    SDL_Surface* birdSurface = SDL_LoadBMP("wingUp.bmp");
    SDL_Surface* birdSurface2 = SDL_LoadBMP("wingDown.bmp");

    // Load in the pipe texture
    SDL_Surface* pipeSurface = SDL_LoadBMP("pipe_Up.bmp");

    // Create the bird textures
    SDL_Texture* wingUpTexture = SDL_CreateTextureFromSurface(gameRenderer, birdSurface);
    SDL_Texture* wingDownTexture = SDL_CreateTextureFromSurface(gameRenderer, birdSurface2);

    // Create the pipe textures
    SDL_Texture* pipeTexture = SDL_CreateTextureFromSurface(gameRenderer, pipeSurface);

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

    // Vector to store the pipes 
    std::vector<Pipe> pipes;

    const int INITIAL_PIPE_COUNT = 3;
    const int PIPE_GAP = 200;

    for (int i = 0; i < INITIAL_PIPE_COUNT; i++) {
        Pipe pipe(SCREEN_WIDTH + i * PIPE_GAP);
        pipes.push_back(pipe);
    }
    
    auto startTime = std::chrono::steady_clock::now();

    // Create an instance of the bird
    Bird* flappy = new Bird(50.0, 70.00, 2.8, 2.05);

    // Create an instance of the pipe

    flappy->StartTimer();


    // Start of the game loop
    while (gameActive) {

        int pipeSpawnInterval = 200; // interval at which new pipes are spawned
        int pipeSpawnTimer = 0;

        // Event handler to check if SDL has been quit
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
            {
                bool quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE) {
                    flappy->jump();
                }
            }
        }
        for (auto& pipe : pipes) {
            pipe.move();
        }

 
        // Spawn the new pipes
        if (pipeSpawnTimer >= pipeSpawnInterval) {
            newPipe(pipes);
            pipeSpawnTimer = 0;
        }
        else {
            pipeSpawnTimer++;
        }

       
        // Clear the renderer 
        SDL_RenderClear(gameRenderer);
        SDL_RenderCopy(gameRenderer, wingUpTexture, NULL, flappy->BirdRect);
        
        renderPipes(gameRenderer, pipes, pipeTexture);

        SDL_RenderPresent(gameRenderer);

        // Give time to the CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    }

    flappy->StopTimer();
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}

// Tasks Todo

// [x] Place bird on screenc
// [x] Gravity on the bird
// [x] Bird movement with spacebar
// [] Place background
// [] Place pipes on screen 
// [] Pipe movement
// [] Bird collision with pipes
// [] Pipe movement 
// [] Vary the pipe heights
// [] 

// --------------------------------