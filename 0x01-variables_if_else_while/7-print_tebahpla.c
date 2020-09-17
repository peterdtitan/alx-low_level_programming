#include <stdio.h>

/**
* main - prints the alphabet in the reverse order
* Return: 0
*/
int main(void)
{
	char a = 'z';

	while (a >= 'a')
	{
		putchar(a);
		a--;
	}

	putchar('\n');
	return (0);
}
