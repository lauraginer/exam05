#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	if(argc != 4)
		return(1);

	int wd = atoi(argv[1]);
	int hg = atoi(argv[2]);
	int it = atoi(argv[3]);
	board[hg][wd];
	next[hg][wd];

	for(int i = 0, i < hg, i++)
	{
		for(int j = 0, j < wd, j++)
		{
			board[i][j] = 0;
		}
	}

	char c;
	int pen = 0;
	int x = 0;
	int y = 0;
	while(read(0, &c, 1) == 1)
	{
		if(c == 'w' && y > 0)
			y--;
		else if(c == 's' && y < (hg - 1))
			y++;
		else if(c == 'a' && x > 0)
			x--:
		else if(c == 'd' && x < (wd - 1))
			x++
		else if(c == 'x')
			pen = !pen;
		if(pen)
			board[y][x] = 1;
	}

	for(int k = 0, k < it, k++)
	{
		
	}
}