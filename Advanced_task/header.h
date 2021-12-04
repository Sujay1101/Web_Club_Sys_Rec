#include <unistd.h>
#include <stdbool.h>

typedef struct metadata{
	size_t size;
	void *next;
	bool free;
}metadata;

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
		if(temp->size > size)
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

