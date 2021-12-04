/*Program defines malloc_n and free_n functions
 * Program uses global linked list of all blocks allocated by malloc 
 * malloc traverses list to check if a free memory block of sufficient size exists. If found uses that block. Else it requests OS for memory
 * call to free changes the status of memory block
 */

#include <unistd.h>/*Library defines sbrk system call*/
#include <stdbool.h>/*Contains definietion of boolean datatype*/

//maetadata is stored just before the memory block
typedef struct metadata{
	size_t size;
	void *next;
	bool free;
}metadata;

//linked list of metadata
typedef struct list{
	metadata *head;/*head of linked list*/
	metadata *tail;/*tail of linked list*/
}list;

//Initialize linked list
list blocks;
blocks.head = NULL;/*initialise head as NULL*/
blocks.tail = NULL;/*initialise tail as NULL*/


void *malloc_n(size_t size)
{
	//scan list of blocks
	metadata* m = search(list, size);
	//If suitable block found
	if(m)
	{
		//update metadata of block 
		m->free = false;
		m->size = size;

		//return pointer
		return (void *)(m + 1);
	}
	else/*request OS for memory*/
	{
		//Allocate memory for metadata and data
		n = (metadata *)sbrk(sizeof(metadata));
		d = sbrk(size);

		//Initialize metadata of memory block
		n->free = false;
		n->next = NULL;
		n->size = size;
		
		/*Appending metadata to linked list*/
		//If list was empty
		if(head == NULL)
		{
			//Set head and tail to point to metadata 
			blocks.head = n;
			blocks.tail = n;
			return d;
		}
		//If list not empty
		//Set n as ending of list
		(blocks.tail)->next = n;
		blocks.tail = n;
		return d;
	}
}

void free_n(void *m)
{
	//traverse linked list
	metadata *temp = list.head;

	//find memory block referenced by the argument
	while((void *)(temp + 1) != m)
		temp = temp->next;

	//change status free
	temp->free = true;
	return;
}



















void *malloc_n(size_t size)
{
	//Scan the free list
	metadata* b = search(head, size);
	//If suitable memory block found replace contents of the metadata. 
	//Set size as original - size and beginning as size bytes more than original beginning  
	if(b)
	{
		occupy(b, size);
		return (void *)((char *)b + sizeof(metadata));
	}
	//If suitable block not found request memory from OS
	else{
		m = request_OS(head, size);
	}
}

metadata *search(metadata *head, size_t size)
{
	//Traverse the free list
	metadata *temp = head;
	if(temp == NULL)
		return NULL;
	do
	{
		if(temp->free == true && temp->size > size)
			return temp->beginning;
		temp = temp->next;

	}while(temp != head);

	return NULL;
	
}

void occupy(metadata *key)
/*
void replace(metadata *key, ssize_t size)
{
	key->beginning = ((char*)key_beginning + size);
	key->size -= size;
	return;	
}*/

