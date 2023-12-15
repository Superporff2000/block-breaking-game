#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_Texture *texture;
    int width;
    int height;
} Image;

Image loadImage(SDL_Renderer *renderer, const char *imagePath);
void renderImage(SDL_Renderer *renderer, Image *image, SDL_Rect *destRect);

#endif