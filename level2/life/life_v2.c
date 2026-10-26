/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 22:27:23 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/26 21:08:03 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void apply_life(char *board, char *next, int wd, int hg)
{
	int index;
	int neighbours;

	index = 0;
	neighbours = 0;
	
	while(index < wd * hg)
	{
		neigthbours = count_neighbours; //funcion donde se comprueban las vecinas
		next[index] = //comprobaciones para casillas vivas
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