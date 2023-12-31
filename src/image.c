#include <stdio.h>
#include "image.h"
#include <SDL2/SDL_image.h>

Image loadImage(SDL_Renderer *renderer, const char *imagePath) {

    Image image;
    image.texture = NULL;

    SDL_Surface *surface = IMG_Load(imagePath);

    if (!surface) {

        fprintf(stderr, "Failed to load image %s: %s\n", imagePath, IMG_GetError());
        return image;
    }

    image.texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (!image.texture) {
        
        fprintf(stderr, "Failed to create texture from image %s: %s\n", imagePath, SDL_GetError());
        SDL_FreeSurface(surface);
        return image;
    }

    image.width = surface->w;
    image.height = surface->h;

    SDL_FreeSurface(surface);

    return image;
}

void renderImage(SDL_Renderer *renderer, Image *image, SDL_Rect *destRect) {

    if (image->texture) {

        SDL_RenderCopy(renderer, image->texture, NULL, destRect);
    }
}