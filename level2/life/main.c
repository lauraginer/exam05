/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:05:08 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/23 01:08:23 by lauragm          ###   ########.fr       */
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
	int board[hg][wd]; //para consultar estado actual
	int next[hg][wd]; //copia para guardar resultados

	/*if (wd <= 0 || hg <= 0 || it < 0)
		return (1);*/
	
	for(int i = 0; i < hg; i++)
	{
		for(int j = 0; j < wd; j++)
		{
			board[i][j] = 0;
		}
	}
	
	char c;
	int pen = 0;
	int x = 0;
	int y = 0;
	
	while(read(0, &c, 1) == 1) //vamos leyendo por 1 caracter
	{
		if(c == 'w' && y > 0)
			y--;
		else if(c == 's' && y < (hg - 1))
			y++;
		else if(c == 'a' && x > 0)
			x--;
		else if(c == 'd' && x < (wd - 1))
			x++;
		else if(c == 'x')
			pen = !pen; //cambia al estado contrario, si es 0 a 1, si es 1 a 0
		
		if(pen)
			board[y][x] = 1; //casilla viva
	}

	for(int k = 0; k < it; k++)
	{
		for(int i = 0; i < hg; i++)
		{
			for(int j = 0; j < wd; j++)
			{
				int alive = 0;

				if((i - 1) >= 0 && (j - 1) >= 0 && board[i - 1][j - 1]) //arriba izq.
					alive++;
				if((i - 1) >= 0 && board[i-1][j]) //arriba centro
					alive++;
				if((i - 1) >= 0 && (j + 1) < wd && board[i - 1][j + 1]) //arriba der.
					alive++;

				if((j - 1) >= 0 && board[i][j - 1]) //izq.
					alive++;
				if((j + 1) < wd && board[i][j + 1]) //der.
					alive++;

				if((i + 1) < hg && (j - 1) >= 0 && board[i + 1][j - 1]) //abajo izq.
					alive++;
				if((i + 1) < hg && board[i + 1][j]) //abajo centro
					alive++;
				if((i + 1) < hg && (j + 1) < wd && board[i + 1][j + 1]) //abajo der.
					alive++;
				
				
				if(board[i][j] == 1 && (alive == 2 || alive == 3)) //comprobación de si viven o mueren
					next[i][j] = 1;
				else if(board[i][j] == 0 && (alive == 3))
					next[i][j] = 1;
				else
					next[i][j] = 0;
			}
		}
		
		for(int i = 0; i < hg; i++)
		{
			for(int j = 0; j < wd; j++)
			{
				board[i][j] = next[i][j];
			}
		}
	}

	for(int i = 0; i < hg; i++)
	{
		for(int j = 0; j < wd; j++)
		{
			if(board[i][j] == 0)
				putchar(' ');
			else if(board[i][j] == 1)
				putchar('O');
		}
		putchar('\n');
	}
	return(0);
}