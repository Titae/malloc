/*
** EPITECH PROJECT, 2018
** show_alloc_mem.c
** File description:
** Show the memory allocated
*/

#include <unistd.h>
#include <stdio.h>
#include "my_malloc.h"

void show_alloc_mem(void)
{
	meta_data_t block;
	
//	printf("break : %p\n", sbrk(0));
	printf("break : %lld\n", (long long)sbrk(0));
	block = heap_head;
	while (block) {
//		printf("%p - %p : %lu\n", block, ((char*)(block + 1)) + block->size, block->size);
		printf("%lld - %lld : %lu (%lld)\n", (long long)block, (long long)(((char*)(block + 1)) + block->size), block->size, (long long)(((char*)(block + 1)) + block->size) - (long long)block);
		block = block->next;
	}
}
