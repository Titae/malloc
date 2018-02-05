/*
** EPITECH PROJECT, 2018
** my_malloc.h
** File description:
** Definition of malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <pthread.h>

#define ALIGN(x, y) (((x) + ((y) - 1)) & ~((y) - 1))

extern pthread_mutex_t heap_mutex;

#endif /* MY_MALLOC_H_ */
