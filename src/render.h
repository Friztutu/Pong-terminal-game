#ifndef RENDER
#define RENDER

#include "pong.h"

// Base settings
#define BALL_CHAR '*'
#define RACKET_CHAR '|'
#define FIELD_SIZE_X 80
#define FIELD_SIZE_Y 25

void render(Ball ball, Player player_one, Player player_two);

void renderField();

void renderScore(Player player_one, Player player_two);

void renderBall(Ball ball);

void renderBar();

void renderRackets(Player player_one, Player player_two);
#endif