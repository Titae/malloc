/*
** EPITECH PROJECT, 2018
** my_free.c
** File description:
** Implementation of free
*/

#include <unistd.h>
#include "my_malloc.h"

void free(void *ptr)
{
	++ptr;
	write(1, "FREE\n", 5);
}
