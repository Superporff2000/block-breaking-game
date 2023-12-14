#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <SDL2/SDL.h>
#include "blocks.h"

void moveBlockLeft(Block *block, int speed, const Uint8 *keyState);
void moveBlockRight(Block *block, int speed, const Uint8 *keyState);
void stopBlock(Block *block, const Uint8 *keyState);

#endif