#include <stdio.h>

void print_arr(int *arr, unsigned len)
{
	int i;
	for (i=0 ; i < len; i++)
	{
		print("%d ", arr[i]);
	}
	return;
}

int main()
{
	int a[3];
	a[0] = 9;
	a[1] = 3;
	a[2] = 995;
	print_arr(a, 3);
	return 0;
}