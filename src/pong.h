#ifndef PONG
#define PONG

#include <stdlib.h>

// Control
#define MOVE_UP_BOTTON_PL1 'a'
#define MOVE_DOWN_BOTTON_PL1 'z'
#define MOVE_UP_BOTTON_PL2 'k'
#define MOVE_DOWN_BOTTON_PL2 'm'
#define EXIT_BOTTON_CODE 27

typedef struct ball_obj {
    int x;
    int y;
    int speed_x;
    int speed_y;
} Ball;

typedef struct player_obj {
    int racket_pos;
    int score;
} Player;

void setUp(Ball *ball, Player *first_player, Player *second_player);

int isGoalFirstPl(Ball ball);

int isGoalSecondPl(Ball ball);

void run();

void initCurses();

int isEndGame(Player first_player, Player second_player);

void validatePlayerInput(Player *first_player, Player *second_player, int *exit_flag, char player_input);

int isWallPuchBall(Ball ball);

int isPlayerPuchBall(Ball ball, Player first_player, Player second_player);

void moveBall(Ball *ball, Player first_player, Player second_player);

void delay(unsigned int msecs);

#endif