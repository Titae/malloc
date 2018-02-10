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
			return ((meta_data_t)ptr - 1)->ptr == ((meta_data_t)ptr - 1);
	return 0;
}

void merge_block(meta_data_t block)
{
	if (block->next && !block->next->used) {
		block->size = block->next->size + sizeof(*block);
		block->next = block->next->next;
		if (block->next->next)
			block->next->next->prev = block;
	}
}

void free(void *ptr)
{
//	my_putstr("FREE: ");
//	my_putnbr((long long)ptr);
//	my_putstr("\n");
	meta_data_t block;
	int direction;
	
	pthread_mutex_lock(&heap_mutex);
	if (ptr == 0) {
//		my_putstr("OUUUUT\n");
		goto end;
	}
	if (!is_valid_ptr(ptr)) {
//		my_putstr("heap_head: ");
//		my_putnbr((long long)heap_head);
//		my_putstr("\nptr: ");
//		my_putnbr((long long)ptr);
//		my_putstr("\nsbrk: ");
//		my_putnbr((long long)sbrk(0));
//		my_putstr("\n");
//		printf("TA GROSSE MERE\n");
//		exit(0);
		goto end;
	}
	if (ptr - (void *)heap_head < (void *)heap_tail - ptr) {
		block = heap_head;
		direction = 0;
	} else {
		block = heap_tail;
		direction = 1;
	}
//	my_putstr("ICICIIC\n");
	while (block && (block + 1) != ptr) {
		if (block->ptr != block) {
//			my_putstr("BOYAKAAAAAAAAAAAAAA\n");
			goto end;
		}
/*		my_putstr("block: ");
		my_putnbr((long long)block);
		my_putstr("\nsbrk(0): ");
		my_putnbr((long long)sbrk(0));
		my_putstr("\nBOUCLE\n");*/
		block = (direction) ? block->prev : block->next;
	}
//	my_putstr("LALALAL\n");
	if (block) {
//		my_putstr("BLOCKFOUND\n");
		block->used = 0;
//		merge_block(block);
	}
//	if (block && block == heap_tail) {
//		if (heap_head == heap_tail) {
//			heap_head = NULL;
//			heap_tail = NULL;
//		} else
//			heap_tail = heap_tail->prev;
//		sbrk(-(block->size + sizeof(*block)));
//	}
end:

	pthread_mutex_unlock(&heap_mutex);
//	my_putstr("ENDFREE\n");
}
