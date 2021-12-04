#include <stdio.h>/* definition of printf function*/ 
#include "malloc_h.h"/* Contains definition of malloc_n function*/

int main()
{
	
	int *a = (int *)malloc_n(sizeof(int) * 4);
	
	//If call to malloc failed
	if(a == NULL)
	{
		printf("Call to malloc failed\n");//print diagnostic message
		return 1; //terminate abnormally
	}

	return 0;
}
