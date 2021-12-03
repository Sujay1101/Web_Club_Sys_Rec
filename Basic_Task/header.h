#include <unistd.h>
#include <errno.h>
#include <stdio.h>


void *malloc_n(size_t size)
{

        //Extend heap memory by size bytes and return pointer to start of the memory
        void *p = sbrk(size);

        //If call to sbrk failed print diagnostic message and return NULL
        if(p == (void *) -1)
        {
                perror("");
                return NULL;
        }

        return p;/*Return a pointer to the beginning of memory block*/
}
