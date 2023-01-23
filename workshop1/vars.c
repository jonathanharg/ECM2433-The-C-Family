#include <stdio.h>

int main()
{
	unsigned short int x = 1;
	unsigned short int y = 65535;
	unsigned char c = 'A';

    y = y + 5;
    x = -1;
    c = 66;

	printf("x has the value %d\n", x);
	printf("y has the value %d\n", y);
	printf("c has the value %c\n", c);
	return 0;
}
