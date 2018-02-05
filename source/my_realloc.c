/*
** EPITECH PROJECT, 2018
** my_realloc.c
** File description:
** Implementation of realloc
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
	++ptr;
	++size;
	write(1, "REALLOC\n", 8);
	return NULL;
}
