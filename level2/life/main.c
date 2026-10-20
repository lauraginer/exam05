/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:05:08 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/20 20:58:10 by lauragm          ###   ########.fr       */
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
	
	
}