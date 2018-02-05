/*
** EPITECH PROJECT, 2018
** my_malloc.c
** File description:
** Implementation of malloc
*/

#include <unistd.h>
#include "my_malloc.h"

pthread_mutex_t heap_mutex = PTHREAD_MUTEX_INITIALIZER;

void *malloc(size_t size)
{
	write(1, "MALLOC\n", 7);
	size++;
       	pthread_mutex_lock(&heap_mutex);

	return NULL;
}
