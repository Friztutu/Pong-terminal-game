#include <stdlib.h>

typedef struct ball_obj {
    int x;
    int y;
    int speed;
} Ball;

typedef struct player_obj {
    int racket_pos;
    int score;
} Player;

void initCurses();

int checkEndGame();

int isWallPuchBall();

int isPlayerPuchBall();
 