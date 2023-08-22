#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#include "pong.h"
#include "render.h"

void run() {
    initCurses();

    Ball ball = {39, 12, 1};
    Player first_player = {13, 0}, second_player = {13, 0};
    int exit_flag = false;
}

void initCurses() {
    initscr();
    raw();
    noecho();
    curs_set(0);
}