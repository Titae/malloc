/*
** EPITECH PROJECT, 2018
** my_realloc.c
** File description:
** Implementation of realloc
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
//	write(1, "REALLOC : ", 10);
//	my_putnbr(size);
//	my_putstr(" NULL : ");
//	my_putnbr(ptr == NULL);
//	my_putchar('\n');
	meta_data_t block_ptr;
	void *block;

	if (ptr)
		block_ptr = ((meta_data_t)ptr - 1); 

	block = malloc(size);
	
//	my_putnbr((long long)block - (long long)sbrk(0));
//	my_putstr("\n");
	if (block && ptr && block_ptr->ptr == block_ptr) {
//		my_putstr("ICIIIIIIIIIIIIIIIIIIIIIIIII\n");
//		my_putnbr(block_ptr->size);
//		my_putstr("\n");
		size_t s = (block_ptr->size < size) ? block_ptr->size : size;
		for (size_t  i = 0; i < s; ++i) {
//			my_putstr("i: ");
//			my_putnbr(i);
//			my_putstr(" | addr + i: ");
//			my_putnbr((long long)((char *)block + i));
//			my_putstr(" | sbrk(0): ");
//			my_putnbr((long long)sbrk(0));
//			my_putstr("\n");
			((char *)block)[i] = ((char *)ptr)[i];
		}
	}

	if (ptr) {
//		my_putstr("BEFOREFREE\n");
		free(ptr);
//		my_putstr("AFTERFREE\n");
	}
//	my_putstr("ENDREALLOC\n");
	return block;
}
