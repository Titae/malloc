/*
** EPITECH PROJECT, 2018
** my_free.c
** File description:
** Implementation of free
*/

#include <unistd.h>
#include "my_malloc.h"

void free(void *ptr)
{
//	printf("ALIGN 8: %ld\n", ALIGN(8, sizeof(void*)));
	write(1, "FREE\n", 5);
	meta_data_t block;
	
	pthread_mutex_lock(&heap_mutex);

	block = heap_head;
	while (block && (block + 1) != ptr)
		block = block->next;
	if (block)
		block->used = 0;
	if (block == heap_tail) {
		sbrk(-(block->size + sizeof(*block)));
		if (heap_head == heap_tail)
			heap_head = NULL;
		heap_tail = NULL;
	}
	pthread_mutex_unlock(&heap_mutex);
}
