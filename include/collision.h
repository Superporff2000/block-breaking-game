#ifndef COLLISION_H
#define COLLISION_H

#include "blocks.h"

int checkCollision(Ball *ball, Block *block);
void handleBallWindowBounds(Ball *ball, int screenWidth, int screenHeight);
void handleMovableBlockWindowBounds(Block *block, int screenWidth);

#endif