#include <unistd.h>/*contains sbrk system call definition*/
#include <errno.h>/*Not necessary. Will be helpful to identify type of error encountered if any by sbrk*/
#include <stdio.h>/*perror defined here*/


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

/*Function to free memory allocated using malloc*/
void free_n(void *ptr)
{
        /*header points to the beginning of the metadata of malloc allocation*/
        size_t *header = (char *)ptr - SIZE_T_SIZE;
        *header = *header & ~1L;//set the status bit of the metadata to 0
        return;
}
