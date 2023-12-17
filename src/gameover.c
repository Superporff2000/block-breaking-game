// gameover.c
#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include "gameover.h"

void gameOver(SDL_Renderer *renderer) {

    TTF_Font* arial;
    arial = TTF_OpenFont("arial.ttf", 24);

    if (!arial) {

        fprintf(stderr, "Error 1: Failed to load font \"arial.ttf\": %s", TTF_GetError());
    }

    SDL_Color white = {255, 255, 255};

    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    SDL_Surface* gameOverMessage;
    gameOverMessage = TTF_RenderText_Solid(arial, "GGGGG", white);

    if (!gameOverMessage) {

        fprintf(stderr, "Error 2: Failed to render text: %s", TTF_GetError());
    }

    // now you can convert it into a texture
    SDL_Texture* gameOverTexture;
    gameOverTexture = SDL_CreateTextureFromSurface(renderer, gameOverMessage);

    if (!gameOverTexture) {

        fprintf(stderr, "Error 3: Failed to create gameOverTexture: %s", TTF_GetError());
    }

    // Create a rectangle to display the game over message in
    SDL_Rect gameOverBox;

    gameOverBox.x = 0;
    gameOverBox.y = 400;
    gameOverBox.w = gameOverMessage->w;
    gameOverBox.h = gameOverMessage->h;

    // (0,0) is on the top left of the window/screen,
    // think a rect as the text's box,
    // that way it would be very simple to understand

    // Now since it's a texture, you have to put RenderCopy
    // in your game loop area, the area where the whole code executes

    // you put the renderer's name first, the Message,
    // the crop size (you can ignore this if you don't want
    // to dabble with cropping), and the rect which is the size
    // and coordinate of your texture

    SDL_RenderCopy(renderer, gameOverTexture, NULL, &gameOverBox);

    // Don't forget to free your surface and texture
    SDL_FreeSurface(gameOverMessage);
    SDL_DestroyTexture(gameOverTexture);
}