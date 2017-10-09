#include "game.h"
#include "player.h"

void playGame()
{
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];
    /* TODO
     * This is some sample code using the functions provided.
     * Note that NULL is passed as the "Player * player" parameter as there is
     * no player cell present on the board in this example.
     */
    char input[BUFSIZ];
    char sinput[BUFSIZ];
    char ginput[BUFSIZ];
    char posx[BUFSIZ];
    char posy[BUFSIZ];
    char pdir[BUFSIZ];
    char throw[BUFSIZ];
    long x,y;
    char *xptr, *yptr;
    Player player;
    Position position;
    initialiseBoard(board);
    displayBoard(board, NULL);
    /*First game menu*/
    do
    {
        printf("At this stage of the program, only two commands are acceptable: \n");
        printf("load <g> \n");
        printf("quit \n\n");
        fgets(sinput, sizeof(sinput), stdin);
        sinput[strlen(sinput) - 1] = '\0';
        if(strcmp(sinput, COMMAND_LOAD1) == 0)
        {
            printf("\n");
            loadBoard(board, BOARD_1);
            displayBoard(board, NULL);
            /*Second game menu*/
            do
            {
                printf("At this stage of the program, only three commands are acceptable: \n");
                printf("load <g>\n");
                printf("init <x>,<y>,<direction>\n");
                printf("quit\n");
                fgets(input, sizeof(input), stdin);
                input[strlen(input) - 1] = '\0';
                /*Tokenize string input here*/
                strcpy(throw, strtok(input, " ,"));
                strcpy(posx, strtok(NULL, " ,"));
                strcpy(posy, strtok(NULL, " ,"));
                strcpy(pdir, strtok(NULL, " ,"));
                x = strtol(posx, &xptr, 10);
                y = strtol(posy, &yptr, 10);
                /*Set position variables*/
                position.x = x;
                position.y = y;
                if(strcmp(throw, COMMAND_INIT) == 0)
                {
                    if(strcmp(pdir, DIRECTION_NORTH) == 0)
                    {
                        player.direction = 0;
                    }
                    else if(strcmp(pdir, DIRECTION_EAST) == 0)
                    {
                        player.direction = 1;
                    }
                    else if(strcmp(pdir, DIRECTION_SOUTH) == 0)
                    {
                        player.direction = 2;
                    }
                    else if(strcmp(pdir, DIRECTION_WEST) == 0)
                    {
                        player.direction = 3;
                    }
                    else
                    {
                        printf("Invalid input\n");
                    }
                    initialisePlayer(&player, &position, player.direction);
                    placePlayer(board, player.position);
                    displayBoard(board, &player);
                    /*Present third game menu*/
                    do
                    {
                        printf("At this stage of the program, only four commands are acceptable: \n");
                        printf("forward (or f)\n");
                        printf("turn_left (or l)\n");
                        printf("turn_right (or r)\n");
                        printf("quit\n");
                        fgets(ginput, sizeof(ginput), stdin);
                        ginput[strlen(ginput) - 1] = '\0';
                        if(strcmp(ginput, COMMAND_FORWARD) == 0 || strcmp(ginput, COMMAND_FORWARD_SHORTCUT) == 0)
                        {
                            movePlayerForward(board, &player);
                            displayBoard(board, &player);
                        }
                        else if(strcmp(ginput, COMMAND_TURN_LEFT) == 0 || strcmp(ginput, COMMAND_TURN_LEFT_SHORTCUT) == 0)
                        {
                            turnDirection(&player, TURN_LEFT);
                            displayBoard(board, &player);
                        }
                        else if(strcmp(ginput, COMMAND_TURN_RIGHT) == 0 || strcmp(ginput, COMMAND_TURN_RIGHT_SHORTCUT) == 0)
                        {
                            turnDirection(&player, TURN_RIGHT);
                            displayBoard(board, &player);
                        }
                        else if(strcmp(ginput, COMMAND_QUIT) == 0)
                        {
                            return;
                        }
                        else
                        {
                            printf("Invalid input\n");
                        }
                    }
                    while(strcmp(ginput, COMMAND_QUIT) != 0);
                    return;
                }
                else
                {
                    printf("Invalid input\n");
                }
            }
            while(strcmp(input, COMMAND_QUIT) != 0);
            return;
        }

        /*Repeat same instructions for the second board... this is why the code is so long.. I should have done this part differently */

        
        else if(strcmp(sinput, COMMAND_LOAD2) == 0)
        {
            printf("\n");
            loadBoard(board, BOARD_2);
            displayBoard(board, NULL);
            do
            {
                printf("At this stage of the program, only three commands are acceptable: \n");
                printf("load <g>\n");
                printf("init <x>,<y>,<direction>\n");
                printf("quit\n");
                fgets(input, sizeof(input), stdin);
                input[strlen(input) - 1] = '\0';
                strcpy(throw, strtok(input, " ,"));
                strcpy(posx, strtok(NULL, " ,"));
                strcpy(posy, strtok(NULL, " ,"));
                strcpy(pdir, strtok(NULL, " ,"));
                x = strtol(posx, &xptr, 10);
                y = strtol(posy, &yptr, 10);
                position.x = x;
                position.y = y;
                if(strcmp(throw, COMMAND_INIT) == 0)
                {
                    if(strcmp(pdir, DIRECTION_NORTH) == 0)
                    {
                        player.direction = 0;
                    }
                    else if(strcmp(pdir, DIRECTION_EAST) == 0)
                    {
                        player.direction = 1;
                    }
                    else if(strcmp(pdir, DIRECTION_SOUTH) == 0)
                    {
                        player.direction= 2;
                    }
                    else if(strcmp(pdir, DIRECTION_WEST) == 0)
                    {
                        player.direction = 3;
                    }
                    else
                    {
                        printf("Invalid input\n");
                    }
                    initialisePlayer(&player, &position, player.direction);
                    placePlayer(board, player.position);
                    displayBoard(board, &player);
                    do
                    {
                        printf("At this stage of the program, only four commands are acceptable: \n");
                        printf("forward (or f)\n");
                        printf("turn_left (or l)\n");
                        printf("turn_right (or r)\n");
                        printf("quit\n");
                        fgets(ginput, sizeof(ginput), stdin);
                        ginput[strlen(ginput) - 1] = '\0';
                        if(strcmp(ginput, COMMAND_FORWARD) == 0 || strcmp(ginput, COMMAND_FORWARD_SHORTCUT) == 0)
                        {
                            movePlayerForward(board, &player);
                            displayBoard(board, &player);
                        }
                        else if(strcmp(ginput, COMMAND_TURN_LEFT) == 0 || strcmp(ginput, COMMAND_TURN_LEFT_SHORTCUT) == 0)
                        {
                            turnDirection(&player, TURN_LEFT);
                            displayBoard(board, &player);
                        }
                        else if(strcmp(ginput, COMMAND_TURN_RIGHT) == 0 || strcmp(ginput, COMMAND_TURN_RIGHT_SHORTCUT) == 0)
                        {
                            turnDirection(&player, TURN_RIGHT);
                            displayBoard(board, &player);
                        }
                        else if(strcmp(ginput, COMMAND_QUIT) == 0)
                        {
                            return;
                        }
                        else
                        {
                            printf("Invalid input\n");
                        }
                    }
                    while(strcmp(input, COMMAND_QUIT) != 0);
                    return;
                }
                else
                {
                    printf("Invalid input\n");
                }
            }
            while(strcmp(sinput, COMMAND_QUIT) != 0);
            return;
        }
        else
        {
            printf("\nInvalid input. \n\n");
        }    
    }
    while(strcmp(sinput, COMMAND_QUIT) != 0);
    return;
}