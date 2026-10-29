#ifndef LIFE_H
#define LIFE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void apply_life(char *board, char *next, int wd, int hg);
int count_neighbours(char *board, int wd, int hg, int x, int y);
void print_board(char *board, int wd, int hg);
#endif