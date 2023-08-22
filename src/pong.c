#include "pong.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "render.h"

void run() {
    initCurses();

    Ball ball = {39, 12, 1, 1};
    Player first_player = {13, 0}, second_player = {13, 0};
    int exit_flag = false;
    int ms = 75;
    char buffer[100];
    clear();
    render(ball, first_player, second_player);
    refresh();

    do {
        delay(ms);
        char player_input = getch();
        validatePlayerInput(&first_player, &second_player, &exit_flag, player_input);
        moveBall(&ball, first_player, second_player);
        clear();
        render(ball, first_player, second_player);
        refresh();

        if (isGoalFirstPl(ball)) {
            first_player.score += 1;
            setUp(&ball, &first_player, &second_player);
        } else if (isGoalSecondPl(ball)) {
            second_player.score += 1;
            setUp(&ball, &first_player, &second_player);
        }
        
        scanw("%s", buffer);
    } while (!isEndGame(first_player, second_player) && !exit_flag);
    endwin();
}

int isGoalFirstPl(Ball ball) { return ball.x == 78; }

int isGoalSecondPl(Ball ball) { return ball.x == 1; }

void setUp(Ball *ball, Player *first_player, Player *second_player) {
    ball->x = 39;
    ball->y = 12;
    ball->speed_x = 1;
    ball->speed_y = 1;
    first_player->racket_pos = 13;
    second_player->racket_pos = 13;
}

void initCurses() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
}

int isEndGame(Player first_player, Player second_player) {
    return first_player.score == 21 || second_player.score == 21;
}

void validatePlayerInput(Player *first_player, Player *second_player, int *exit_flag, char player_input) {
    switch (player_input) {
        case MOVE_UP_BOTTON_PL1:
        case MOVE_UP_BOTTON_PL1 - 32:
            first_player->racket_pos != 2 ? first_player->racket_pos -= 1 : first_player->racket_pos;
            break;

        case MOVE_DOWN_BOTTON_PL1:
        case MOVE_DOWN_BOTTON_PL1 - 32:
            first_player->racket_pos != 22 ? first_player->racket_pos += 1 : first_player->racket_pos;
            break;

        case MOVE_UP_BOTTON_PL2:
        case MOVE_UP_BOTTON_PL2 - 32:
            second_player->racket_pos != 2 ? second_player->racket_pos -= 1 : second_player->racket_pos;
            break;

        case MOVE_DOWN_BOTTON_PL2:
        case MOVE_DOWN_BOTTON_PL2 - 32:
            second_player->racket_pos != 22 ? second_player->racket_pos += 1 : second_player->racket_pos;
            break;

        case EXIT_BOTTON_CODE:
            *exit_flag = true;
            break;

        default:
            break;
    }
}

void moveBall(Ball *ball, Player first_player, Player second_player) {
    if (isWallPuchBall(*ball)) ball->speed_y *= -1;
    if (isPlayerPuchBall(*ball, first_player, second_player)) ball->speed_x *= -1;

    ball->x += ball->speed_x;
    ball->y += ball->speed_y;
}

int isWallPuchBall(Ball ball) { return ball.y + 1 == 24 || ball.y - 1 == 0; }

int isPlayerPuchBall(Ball ball, Player first_player, Player second_player) {
    return (first_player.racket_pos - 1 <= ball.y + ball.speed_y &&
            ball.y + ball.speed_y <= first_player.racket_pos + 1 && ball.x - 1 == 2) ||
           (second_player.racket_pos - 1 <= ball.y + ball.speed_y &&
            ball.y + ball.speed_y <= second_player.racket_pos + 1 && ball.x + 1 == 77);
}

void delay(unsigned int msecs) {
    clock_t goal = msecs * CLOCKS_PER_SEC / 1000 + clock();
    while (goal > clock()) {
    };
}