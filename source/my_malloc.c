/*
** EPITECH PROJECT, 2018
** my_malloc.c
** File description:
** Implementation of malloc
*/

#include <unistd.h> // TODO_END: Delete
#include <stdlib.h>
#include <signal.h> // TODO_END:
#include "my_malloc.h"

pthread_mutex_t heap_mutex = PTHREAD_MUTEX_INITIALIZER;
meta_data_t heap_head = NULL;
meta_data_t heap_tail = NULL;

/*static void split_block(meta_data_t block, size_t size)
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
}*/

static meta_data_t get_not_used_block(size_t size)
{
	meta_data_t block = heap_head;

//	my_putstr("BEFORE\n");
//	my_putnbr(block == NULL);
//	my_putchar('\n');
	while (block != NULL && !(!block->used && block->size >= size)) {
		/*		if (block->ptr != block) {
			printf("C'est pas bon batar\n");
			exit(1);
		}
			
		if (!block->used && block->size >= size)
		break;*/
		block = block->next;
	}
//	my_putstr("ENDOS\n");
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

//void sigHandler(int signum)
//{
//	show_alloc_mem();
//	exit(1);
//}

void *malloc(size_t size)
{
//	static int la = 0;

//	if (!la) {
//		signal(SIGSEGV, &sigHandler);
//		signal(SIGINT, &sigHandler);
//		la++;
//	}
//	my_putstr("\n----------\n");
//	write(1, "MALLOC : ", 9);
//	my_putnbr(size);
//	my_putchar('\n');
	meta_data_t block;

	if (size == 0) {
		return NULL;
	}
	size = ALIGN(size, sizeof(void *));
	pthread_mutex_lock(&heap_mutex);
//	block = push_break(size);

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
		
		}// else if (block->size > sizeof(*block) + size) {
		//	split_block(block, size);
		//}
//		else {
//			my_putstr("in malloc: block: ");
///			my_putnbr((long long)block);
//			my_putstr("sbrk(0): ");
//			my_putnbr((long long)sbrk(0));
//			my_putstr("\n");
//		}
		block->used = 1;
	}
end:
	
	pthread_mutex_unlock(&heap_mutex);
//	my_putnbr((size_t)block);
//	write(1, "\nend\n", 5);
	return (block) ? block + 1 : NULL;
}
