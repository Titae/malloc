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

typedef struct meta_data *meta_data_t;

struct meta_data {
	meta_data_t next;
	meta_data_t prev;
	size_t size;
	int used;
	meta_data_t ptr;
};

extern pthread_mutex_t heap_mutex;
extern meta_data_t heap_head;
extern meta_data_t heap_tail;
extern const void *break_origin;

#endif /* MY_MALLOC_H_ */
