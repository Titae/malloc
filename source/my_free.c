/*
** EPITECH PROJECT, 2018
** my_free.c
** File description:
** Implementation of free
*/

#include <unistd.h>
#include "my_malloc.h"

int is_valid_ptr(void *ptr)
{
	if (heap_head)
		if (ptr >= (void *)heap_head + 1 && ptr < sbrk(0))
			return ((meta_data_t)ptr - 1)->ptr ==
				((meta_data_t)ptr - 1);
	return 0;
}

void merge_block(meta_data_t block)
{
	if (block->next && !block->next->used) {
		if (block->next == heap_tail)
			heap_tail = heap_tail->prev;
		block->size += block->next->size + sizeof(*block);
		block->next = block->next->next;
		if (block->next)
			block->next->prev = block;
	}
}

void free(void *ptr)
{
	meta_data_t block;
	int direction;

	pthread_mutex_lock(&heap_mutex);
	if (!ptr || !is_valid_ptr(ptr))
		goto end;
	if (ptr - (void *)heap_head < (void *)heap_tail - ptr) {
		block = heap_head;
		direction = 0;
	} else {
		block = heap_tail;
		direction = 1;
	}
	while (block && (block + 1) != ptr)
		block = (direction) ? block->prev : block->next;
	if (block) {
		block->used = 0;
		merge_block(block);
	}
//	if (block && block == heap_tail) {
//		my_putstr("IN\n");
//		if (block == heap_head) {
//			my_putstr("DEDANS\n");
//			heap_head = NULL;
//			heap_tail = NULL;
//		} else {
//			my_putstr("DANSDE\n");
//			heap_tail = heap_tail->prev;
//		}
//		sbrk(-(block->size + sizeof(*block)));
//	}
end:
	pthread_mutex_unlock(&heap_mutex);
}
