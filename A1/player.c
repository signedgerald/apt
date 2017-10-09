#include "player.h"
#include "game.h"

void initialisePlayer(Player * player, Position * position, Direction direction)
{
	/* TODO 
    Accessing the variable inside the struct of the struct*/
	player->position.x = position->x;
	player->position.y = position->y;
	player->direction = direction;
}

void turnDirection(Player * player, TurnDirection turnDirection)
{
    /* TODO
        Setting each direction to change to the next corresponding direction */
    if(turnDirection == 1)
    {
        if(player->direction == 0)
        {
            player->direction = 1;
        }
        else if(player->direction == 1)
        {
            player->direction = 2;
        }
        else if(player->direction == 2)
        {
            player->direction = 3;
        }
        else
        {
            player->direction = 0;
        }
    }
    else
    {
        if(player->direction == 0)
        {
            player->direction = 3;
        }
        else if(player->direction == 1)
        {
            player->direction = 0;
        }
        else if(player->direction == 2)
        {
            player->direction = 1;
        }
        else
        {
            player->direction = 2;
        }
    }
}

Position getNextForwardPosition(const Player * player)
{
    /* TODO 
    I did not use this function*/
	Position position;

	return position;
}

void updatePosition(Player * player, Position position)
{
    /* TODO 
    Next position is now current position here*/
    player->position.x = position.x;
    player->position.y = position.y;
}

void displayDirection(Direction direction)
{
    /* TODO 
    Output directional arrows*/
    if(direction == 0)
    {
        printf(DIRECTION_ARROW_OUTPUT_NORTH);
    }
    else if(direction == 1)
    {
        printf(DIRECTION_ARROW_OUTPUT_EAST);
    }
    else if(direction == 2)
    {
        printf(DIRECTION_ARROW_OUTPUT_SOUTH);
    }
    else if(direction == 3)
    {
        printf(DIRECTION_ARROW_OUTPUT_WEST);
    }
    else
    {
        printf("Invalid input\n");
        return;
    }

}
