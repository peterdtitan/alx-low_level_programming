#include <stdio.h>
/**
* main - create pairs of numbers without repetition
* Return: 0
*/
int main(void)
{
	int j = 0;

	while (j <= 99)
	{
		int i = j;

		while (i <= 99)
		{
			if (i != j)
			{
				int toPrint;

				if (j >= 0 && j <= 9)
					toPrint = 48;

				else
					toPrint = j / 10 + 48;

				putchar(toPrint);
				putchar(j % 10 + 48);
				putchar(' ');
				if (i >= 0 && i <= 9)
					toPrint = 48;
				else
					toPrint = i / 10 + 48;

				putchar(toPrint);
				putchar(i % 10 + 48);
				if (j * 100 + i != 9899)
				{
					putchar(',');
					putchar(' ');
				}
			}
			i++;
		}
		j++;
	}
	putchar('\n');
	return (1);
}
