/*
** EPITECH PROJECT, 2018
** my_calloc.c
** File description:
** calloc implementation
*/

#include <unistd.h> // TODO_END:
#include <stdlib.h>
#include <string.h>
#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
//	write(1, "CALLOC\n", 7);
	void *ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return ptr;
	for (unsigned int i = 0; i < ((meta_data_t)ptr - 1)->size; ++i)
		((char *)ptr)[i] = 0;
//	memset(ptr, 0, ((meta_data_t)ptr - 1)->size);
	return ptr;
}
