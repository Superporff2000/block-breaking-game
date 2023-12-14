#include "movement.h"

void moveBlockLeft(Block *block, int speed, const Uint8 *keyState)
{

    block -> rect.x -= speed;
}

void moveBlockRight(Block *block, int speed, const Uint8 *keyState)
{

    block -> rect.x += speed;
}

void stopBlock(Block *block, const Uint8 *keyState)
{
    block -> rect.x = 0;
}