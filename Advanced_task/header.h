#include <unistd.h>/*contains sbrk system call definition*/
#include <errno.h>/*Not necessary. Will be helpful to identify type of error encountered if any by sbrk*/
#include <stdio.h>/*perror defined here*/
#include <stdbool.h>/*boolean datatype defined here*/

//datatype to store metadata of the memory allocation
typedef struct metadata{
        size_t size;/*size of memory allocation*/
        bool occupied;/*True if the memory is in use. False otherwise*/
} metadata;

void *malloc_n(size_t size)
{
        //Initialize metadata of the allocation
        metadata *m = (metadata *)sbrk(sizeof(metadata));
        
        //If memory could not be allocated print diagnostic message and return NULL
        if(m == (void *)-1)
        {
                perror("");
                return NULL;
        }
        
        m->size = size;
        m->occupied = true;

        //Allocate memory to data
        void *d = sbrk(size);

        //If memory could not be allocated to the data print diagnostic message and return NULL
        if(d == (void *)-1)
        {
                perror("");
                return NULL;
        }

        //Return pointer to data
        return d;
}

void free_n(void *p)
{
        metadata *m = (metadata *)(p - sizeof(metadata));
        m->occupied = false;
        return;
}
