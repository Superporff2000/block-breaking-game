#include <SDL2/SDL.h>
#include "game.h"

int main(int argc, char **argv) {

    SDL_Window *window = initializeSDL();
    SDL_Renderer *renderer = createRenderer(window);

    runGameLoop(renderer);

    cleanupSDL(window, renderer);
    return EXIT_SUCCESS;
}