/*
** EPITECH PROJECT, 2018
** my_calloc.c
** File description:
** calloc implementation
*/

#include <stdlib.h>
#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
	void *ptr = malloc(nmemb * size);

	if (!ptr)
		return ptr;
	for (unsigned int i = 0; i < ((meta_data_t)ptr - 1)->size; ++i)
		((char *)ptr)[i] = 0;
	return ptr;
}
