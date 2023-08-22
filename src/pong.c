#include "pong.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "render.h"

void run() {
    initCurses();

    Ball ball = {39, 12, 1};
    Player first_player = {13, 0}, second_player = {13, 0};
    int exit_flag = false;
    clear();
    render(ball, first_player, second_player);
    refresh();

    do {
        char player_input = getch();
        validatePlayerInput(&first_player, &second_player, &exit_flag, player_input);
        moveBall(&ball, first_player, second_player);
        clear();
        render(ball, first_player, second_player);
        refresh();
        fflush(stdin);
    } while (!isEndGame(first_player, second_player) && !exit_flag);
    endwin();
}

void initCurses() {
    initscr();
    raw();
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
    if (isWallPuchBall(*ball) || isPlayerPuchBall(*ball, first_player, second_player)) ball->speed *= -1;

    ball->x += ball->speed;
    ball->y += ball->speed;
}

int isWallPuchBall(Ball ball) { return ball.y + 1 == 24 || ball.y - 1 == 0; }

int isPlayerPuchBall(Ball ball, Player first_player, Player second_player) {
    return (first_player.racket_pos - 1 <= ball.y <= first_player.racket_pos + 1 && ball.x - 1 == 2) ||
           (first_player.racket_pos - 1 <= ball.y <= first_player.racket_pos + 1 && ball.x + 1 == 77);
}