#include "stdio.h"
#include "game.h"
#include "blocks.h"
#include "movement.h"
#include "collision.h"
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400
#define SCREEN_DELAY 16

Block movableBlock;
Block edgeBreakableBlock[3][1];     // The blocks at left edge should be at some distance, so
Block breakableBlock[3][10];        // they have been defined seperately
Ball gameBall;

SDL_Window* initializeSDL(void) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Block Breaker",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!window) {

        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        return NULL;
    }

    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window) {

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (!renderer) {

        fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        
        return NULL;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    return renderer; // Return the created renderer
}

void runGameLoop(SDL_Renderer* renderer) {

    int quit = 0;
    int speed = 5;
    SDL_Event event;

    movableBlock = createBlock(210, 350, 180, 40, 1);
    gameBall = createBall(200, 200, 10, 5, 5);

    for (int i = 0; i < 3; ++i) {

        for (int j = 0; j < 10; ++j) {

            breakableBlock[i][j] = createBlock(j * 60, i * 30, 50, 20, 1);
        }
    }

    while (!quit) {
        
        while (SDL_PollEvent(&event) != 0) {

            if (event.type == SDL_QUIT) {
                
                quit = 1;
            }

            if (event.type == SDL_KEYDOWN)
            {

                // Get the current state of the keyboard
                const Uint8 *keyState = SDL_GetKeyboardState(NULL);

                switch (event.key.keysym.scancode)
                {

                case SDL_SCANCODE_A:
                    moveBlockLeft(&movableBlock, speed, keyState);
                    break;

                case SDL_SCANCODE_D:
                    moveBlockRight(&movableBlock, speed, keyState);
                    break;
                }
            }
        }

        // Make the ball move
        updateBallPosition(&gameBall, SCREEN_WIDTH, SCREEN_HEIGHT);

        // Check for ball collisions with the movable block
        
        int collisionA = checkCollision(&gameBall, &movableBlock);

        if (collisionA) {

            gameBall.speedY = -gameBall.speedY;
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
        SDL_RenderClear(renderer);

        for (int i = 0; i < 3; ++i) {

            for (int j = 0; j < 10; ++j) {

                renderBlock(renderer, &breakableBlock[i][j]);
                
                int collisionB = checkCollision(&gameBall, &breakableBlock[i][j]);
                
                if (collisionB) {

                    gameBall.speedY = -gameBall.speedY;
                    decreaseBlockHealth(&breakableBlock[i][j]);

                    if (breakableBlock[i][j].health <= 0) {

                        breakableBlock[i][j].isVisible = 0;
                    }
                }
            }
        }

        // Render the blocks
        renderBlock(renderer, &movableBlock);
        renderBall(renderer, &gameBall);

        // Render the rect to the screen
        SDL_RenderPresent(renderer);

        SDL_Delay(SCREEN_DELAY);

    }
}

void cleanupSDL(SDL_Window* window, SDL_Renderer* renderer) {

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}