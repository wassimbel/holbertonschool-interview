#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 **/

void menger(int level)
{
	int i, j, x, y, num;
	char c;

	num = pow(3, level);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			c = '#';
			x = i;
			y = j;
			while (x || y)
			{
				if (x % 3 == 1 && y % 3 == 1)
					c = ' ';
				x /= num;
				y /= num;
			}
			putchar(c);
		}
		printf("\n");
	}
}
