/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 22:27:23 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/25 23:15:03 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc != 4)
		return(1);

	int wd = atoi(argv[1]);
	int hg = atoi(argv[2]);
	int it = atoi(argv[3]);
	if(iter < 0) //quizas es necesario comprobar los argc si son <= 0
		iter = 0;

	char *board = calloc(wd * hg + 1, 1);
	char *next = calloc(wd * hg, 1);
	if(!board || !next)
		return(free(board), free(next_board), 1);

	char c;
	int pen = 0;
	int x = 0;
	int y = 0;
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
}