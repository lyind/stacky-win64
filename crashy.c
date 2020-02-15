
#include <stdio.h>
#include <stdlib.h>

#include "stacky.h"


int c(int z)
{
	volatile int non_zero = rand() + 1;
	if (non_zero != 0)
	{
		stacky_print((void*)&non_zero);
	}

	return non_zero;
}


int b(int y)
{
	return c(rand() / y);
}



int a(int x)
{
	return b(rand() / x);

}


int main(int argc, char *argv[])
{
	srand(argc);

	fprintf(stderr,
		"a @ %016x\n"
		"b @ %016x\n"
		"c @ %016x\n\n",
		&a, &b, &c);

	return (a(argc) % 3) ? 1 : 0;
}

