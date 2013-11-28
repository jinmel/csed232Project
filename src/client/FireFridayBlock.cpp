#include <iostream>
#include "block.h"
#include "firefridayblock.h"
#include "player.h"
#include "dice.h"


FireFridayBlock::FireFridayBlock(FireFridayType type)
{
    block_type = type;
}

FireFridayBlock::~FireFridayBlock()
{

}

void FireFridayBlock::enter(Player *player)
{
    using namespace FireFridayType;

    switch(block_type)
   {    case TWODARI: inTWODARI(player);
            break;
        case SEOULJONGBIN: inSEOULJONGBIN(player);
            break;
        case TONGZIP: inTONGZIP(player);
            break;
        case CHAMPYO: inCHAMPYO(player);
            break;
    }

}


void FireFridayBlock::inSEOULJONGBIN(Player *player)
{

}

void FireFridayBlock::inCHAMPYO(Player *player)
{

}

void FireFridayBlock::inTONGZIP(Player *player)
{

}

void FireFridayBlock::inTWODARI(Player *player)
{

}

