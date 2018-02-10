/*
** EPITECH PROJECT, 2018
** my_malloc.c
** File description:
** Implementation of malloc
*/

#include <unistd.h> // TODO_END: Delete
#include <stdlib.h>
#include "my_malloc.h"

pthread_mutex_t heap_mutex = PTHREAD_MUTEX_INITIALIZER;
meta_data_t heap_head = NULL;
meta_data_t heap_tail = NULL;

static void split_block(meta_data_t block, size_t size)
{
	meta_data_t other = (meta_data_t)((char *)(block + 1) + size);

	other->size = block->size - size - sizeof(*other);
	other->next = block->next;
	if (other->next)
		other->next->prev = other;
	other->prev = block;
	block->next = other;
	block->size = size;
	other->used = 0;
	if (block == heap_tail)
		heap_tail = other;
	other->ptr = other;
}

static meta_data_t get_not_used_block(size_t size)
{
	meta_data_t block = heap_head;

	while (block != NULL && !(!block->used && block->size >= size))
		block = block->next;
	return block;
}

static meta_data_t push_break(size_t size)
{
	meta_data_t block = sbrk(0);

	if (sbrk(sizeof(*block) + size) == (void *)-1)
		return NULL;
	block->size = size;
	block->next = NULL;
	block->prev = NULL;
	block->used = 1;
	block->ptr = block;
	return block;
}

void *malloc(size_t size)
{
	meta_data_t block;

	if (size == 0)
		return NULL;
	size = ALIGN(size, sizeof(void *));
	pthread_mutex_lock(&heap_mutex);
	if (heap_head == NULL) {
		block = push_break(size);
		heap_head = block;
		heap_tail = block;
	} else {
		block = get_not_used_block(size);
		if (block == NULL) {
			block = push_break(size);
			if (block == NULL)
				goto end;
			heap_tail->next = block;
			block->prev = heap_tail;
			heap_tail = block;
		} else if (block->size > sizeof(*block) + size)
			split_block(block, size);
		block->used = 1;
	}
end:
	pthread_mutex_unlock(&heap_mutex);
	return (block) ? block + 1 : NULL;
}
