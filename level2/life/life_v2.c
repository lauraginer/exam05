/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 22:27:23 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/27 23:47:35 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int count_neighbours(char *board, int wd, int hg, int x, int y)
{
	int dx;
	int dy;
	int nx; //columna del vecino que comprobamos
	int ny;
	int neighbours; //cont de vecinos vivos

	dy = -1; //la ultima fila
	neighbours = 0;
	while(dy <= 1)
	{
		dx = -1;
		while(dx <= 1)
		{
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
		neigthbours = count_neighbours(board, wd, hg, index % board, index / board); //funcion donde se comprueban las vecinas
		next[index] = ((board[index] && (neighbours == 2 || neighbours == 3)) //comprobaciones para casillas vivas
			|| (!board[index] && neighbours == 3))
		 
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
}