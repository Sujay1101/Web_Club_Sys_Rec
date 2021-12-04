#include "header.h"
#include <stdio.h>
int main()
{
	int *p = (int *)malloc_n(sizeof(int) * 4);
	free_n(p);
	return 0;
}
