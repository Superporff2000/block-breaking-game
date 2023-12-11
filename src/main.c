#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    window = SDL_CreateWindow(
        "Jeu de la vie", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN);

    // Setup renderer
    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Clear window
    SDL_RenderClear(renderer);

    // Main tile
    SDL_Rect mainTile;
    mainTile.x = 220;
    mainTile.y = 400;
    mainTile.w = 200;
    mainTile.h = 25;

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // Define tile properties
    int tile_width = 100;
    int tile_height = 25;
    int gap = 5; // gap between tiles

    // Game loop flag
    int quit = 0;

    // Event handler
    SDL_Event e;

    while (!quit)
    {
        // Handle events on the queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
            // Handle key presses
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_a:
                    // Move the main tile to the left
                    mainTile.x -= 10;
                    break;
                case SDLK_d:
                    // Move the main tile to the right
                    mainTile.x += 10;
                    break;
                }
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render the breakable blocks
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 8; ++col)
            {
                SDL_Rect tile;
                tile.x = col * (tile_width + gap);
                tile.y = row * (tile_height + gap);
                tile.w = tile_width;
                tile.h = tile_height;

                // Render rect
                SDL_RenderFillRect(renderer, &tile);
            }
        }

        // Render rect
        SDL_RenderFillRect(renderer, &mainTile);

        // Render the rect to the screen
        SDL_RenderPresent(renderer);

        // Wait for a short period (adjust as needed)
        SDL_Delay(10);
    }

    // Cleanup and quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
