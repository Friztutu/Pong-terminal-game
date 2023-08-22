#include "pong.h"
#include "render.h"

#include <ncurses.h>

void render(Ball ball, Player player_one, Player player_two) {
    renderField();
    renderScore(player_one, player_two);
    renderRackets(player_one, player_two);
    renderBall(ball);
    renderBar();
}

void renderField() {
    for (int i = 0; i < FIELD_SIZE_X; i++) mvprintw(0, i, "-");
    for (int i = 1; i < FIELD_SIZE_Y; i++) {
        mvprintw(i, 0, "|");
        mvprintw(i, 79, "|");
        if (i % 2) mvprintw(i, 39, "|");
    }
    for (int i = 0; i < FIELD_SIZE_X; i++) mvprintw(24, i, "-");
}   

void renderScore(Player player_one, Player player_two) {
    mvprintw(5, 35, "%d", player_one.score);   
    mvprintw(5, 43, "%d", player_two.score);
}

void renderBall(Ball ball) {
    mvprintw(ball.y, ball.x, "*");
}

void renderBar() {
    mvprintw(25, 0, "UP = a/A");
    mvprintw(26, 0, "DOWN = z/Z");
    mvprintw(26, 35, "EXIT = ESC");
    mvprintw(25, 70, "UP = k/K");
    mvprintw(26, 70, "DOWN = m/M");
}

void renderRackets(Player player_one, Player player_two) {
    mvprintw(player_one.racket_pos - 1, 2, "|");
    mvprintw(player_one.racket_pos, 2, "|");
    mvprintw(player_one.racket_pos + 1, 2, "|");
    mvprintw(player_two.racket_pos - 1, 77, "|");
    mvprintw(player_two.racket_pos, 77, "|");
    mvprintw(player_two.racket_pos + 1, 77, "|");
}