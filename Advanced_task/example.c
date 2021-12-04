#include "header.h"/* header file contains definietion of malloc_n and free_n functions*/
#include <stdio.h>

int main()
{
	int *p = (int *)malloc_n(sizeof(int) * 4);
	
	//If call to malloc failed print diagnostic message and terminate abnormally
	if(p == NULL)
	{
		printf("Call to malloc failed\n");
		return 1;
	}
	
	free_n(p);
	
	return 0;
}
