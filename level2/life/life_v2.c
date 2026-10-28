/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 22:27:23 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/28 21:50:52 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void print_board(char *board, int wd, int hg)
{
	int index;

	index = 0;
	while(index < wd * hg)
	{
		if(board[index])
			putchar('O');
		else
			putchar(' ');
		
		index++;
		if(index % wd == 0)
			putchar('\n');
	}
}

int count_neighbours(char *board, int wd, int hg, int x, int y)
{
	int dx;
	int dy;
	int nx; //columna del vecino que comprobamos
	int ny;
	int neighbours; //cont de vecinos vivos

	dy = -1; //la primera fila
	neighbours = 0;
	while(dy <= 1)
	{
		dx = -1;
		while(dx <= 1)
		{
			nx = x + dx; //pos de las casillas vecinas a comprobar
			ny = y + dy;
			 
			if((dx != 0 || dy != 0) && ny >= 0 && ny < hg && nx >= 0 && nx < wd)
				neighbours += board[ny * wd + nx];
			dx++;
		}
		dy++;
	}
	return(neighbours);
}

void apply_life(char *board, char *next, int wd, int hg)
{
	int index;
	int neighbours;

	index = 0;
	neighbours = 0;
	
	while(index < wd * hg)
	{
		neighbours = count_neighbours(board, wd, hg, index % wd, index / wd); //funcion donde se comprueban las vecinas
		next[index] = ((board[index] && (neighbours == 2 || neighbours == 3)) //comprobaciones para casillas vivas
			|| (!board[index] && neighbours == 3));
		 
		index++;
	}
	index = 0;
	while(index < wd * hg)
	{
		board[index] = next[index];
		index++;
	}
}

int main(int argc, char **argv)
{
	char c;
	int pen;
	int x;
	int y;
	int wd; 
	int hg;
	int it;
	char *board;
	char *next;
	
	if(argc != 4)
		return(1);
	
	wd = atoi(argv[1]);
	hg = atoi(argv[2]);
	it = atoi(argv[3]);
	if(it < 0) //quizas es necesario comprobar los argc si son <= 0
		it = 0;

	board = calloc(wd * hg + 1, 1);
	next = calloc(wd * hg, 1);
	if(!board || !next)
		return(free(board), free(next), 1);

	pen = 0;
	x = 0;
	y = 0;
	while(read(0, &c, 1) == 1)
	{
		if(c == 'w' && y > 0)
			y--;
		else if(c == 's' && y < hg - 1)
			y++;
		else if(c == 'a' && x > 0)
			x--;
		else if(c == 'd' && x < wd - 1)
			x++;
		else if(c == 'x')
			pen = !pen;

		if(pen)
			board[y * wd + x] = 1;
	}
	
	while(it--)
		apply_life(board, next, wd, hg);
	
	print_board(board, wd, hg);
	free(board);
	free(next);

	return(0);
}