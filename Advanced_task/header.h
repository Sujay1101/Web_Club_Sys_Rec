#include <unistd.h>/*contains sbrk system call definition*/
#include <errno.h>/*Not necessary. Will be helpful to identify type of error encountered if any by sbrk*/
#include <stdio.h>/*perror defined here*/
#include <stdbool.h>/*boolean datatype defined here*/

//datatype to store metadata of the memory allocation by malloc_n
typedef struct metadata{
        size_t size;/*size of memory allocation*/
        bool occupied;/*True if the memory is in use. False oif memory freed*/
} metadata;

//Function returns pointer to the beginning of a block of memory of length size
//Function first allocates space to the metadata then initializes the metadata and finally allocates space to the data
void *malloc_n(size_t size)
{

        //Allocate memory to the metadata of the memory allocation
        metadata *m = (metadata *)sbrk(sizeof(metadata));
        
        //If memory could not be allocated to the metadata print diagnostic message and return NULL
        if(m == (void *)-1)
        {
                perror("");
                return NULL;
        }
        //Initialize size and status of metadata 
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

//Function to free a block of memory previously allocated by the malloc function 
//First updates status field in the metadata and then dellocates memory occupied by data and metadata
void free_n(void *p)
{
        metadata *m = (metadata *)(p - sizeof(metadata));/*m points to the metadata of memory pointed by p*/
        m->occupied = false;/*update status of the allocation*/

	sbrk(-(m->size)); /*deallocate memory occupied by data*/
	sbrk(-sizeof(metadata));/*deallocate memory occupied by the metadata*/

        return;
}
