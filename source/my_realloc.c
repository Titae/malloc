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
	meta_data_t block_ptr;
	void *block;

	if (ptr)
		block_ptr = ((meta_data_t)ptr - 1); 
	block = malloc(size);
      	if (block && ptr && block_ptr->ptr == block_ptr) {
		size_t s = (block_ptr->size < size) ? block_ptr->size : size;
		for (size_t  i = 0; i < s; ++i)
			((char *)block)[i] = ((char *)ptr)[i];
	}
	if (ptr)
		free(ptr);
	return block;
}
