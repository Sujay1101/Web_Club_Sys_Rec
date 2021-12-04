#include <unistd.h>/*Header file defines sbrk system call*/
#include <stdio.h>/*perror defined here*/

//datatype to store metadata of the memory allocation
typedef struct metadata{
        size_t size;/*size of memory allocation*/
        bool occupied;/*True if the memory is in use. False otherwise*/
} metadata;

void *malloc_n(size_t size)
{
        //Allocate memory to metadata of the allocation
        metadata *m = sbrk(sizeof(metadata));
        
        //If memory could not be allocated print diagnostic message and return NULL
        if(m == (void *)-1)
        {
                perror("");
                return NULL;
        }
        
        //Initialize metadata of the allocation
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
