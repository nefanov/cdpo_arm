#include <stdio.h>

void print(int i)
{
	printf ("%d ", i);
};

int main()
{
	int i;
	for (i = 0; i < 10; i++)
		print(i);

	return 0;
};

/* compile this function then change ranges from 0-10 to 10-20 via binary patching. */