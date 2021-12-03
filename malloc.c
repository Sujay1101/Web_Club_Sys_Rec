#include <stdio.h>
#include "malloc_h.h"

int main()
{
	
	int *a = (int *)malloc_n(sizeof(int) * 4);

	
	if(a == NULL)
	{
		perror("Call to malloc failed");
	}

	
	return 0;
}
