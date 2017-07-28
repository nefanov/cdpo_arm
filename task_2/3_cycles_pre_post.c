#include <stdio.h>

void func_print(int begin, int end)
{
	for (; begin < end; begin++)
        printf ("%d\n", begin);
    return;
};

/* Examine this example on your compiler. Are there any excessive checks? */