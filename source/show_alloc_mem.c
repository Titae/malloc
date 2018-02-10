/*
** EPITECH PROJECT, 2018
** show_alloc_mem.c
** File description:
** Show the memory allocated
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my_malloc.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *str)
{
	write(1, str, strlen(str));
}

void my_putnbr(long long nb)
{
	long long mod;

	if (nb < 0)
	{
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0)
	{
		if (nb >= 10)
		{
			mod = (nb % 10);
			nb = (nb - mod) / 10;
			my_putnbr(nb);
			my_putchar(48 + mod);
		}
		else
			my_putchar(48 + nb % 10);
	}
}

void show_alloc_mem(void)
{
	meta_data_t block;

	int i = 0;
//	printf("break : %p\n", sbrk(0));
//	printf("break : %lld\n", (long long)sbrk(0));
	my_putstr("break : ");
	my_putnbr((long long)sbrk(0));
	my_putstr("\n");
	block = heap_head;
	while (block) {
//		printf("%p - %p : %lu\n", block, ((char*)(block + 1)) + block->size, block->size);
//		printf("%lld - %lld : %lu (%lld) | used : %d\n", (long long)block, (long long)(((char*)(block + 1)) + block->size), block->size, (long long)(((char*)(block + 1)) + block->size) - (long long)block, block->used);
		my_putnbr((long long)block);
		my_putstr(" - ");
		my_putnbr((long long)(((char*)(block + 1)) + block->size));
		my_putstr(" : ");
		my_putnbr(block->size);
		my_putstr(" (");
		my_putnbr((long long)(((char*)(block + 1)) + block->size) - (long long)block);
		my_putstr(") | used : ");
		my_putnbr(block->used);
		my_putstr(" (");
		if (!i)
			i = (block->ptr != block);
		my_putnbr(block->ptr == block);
		my_putstr(")");
		my_putstr("\n");
		block = block->next;
	}
	my_putnbr(i);
	my_putchar('\n');
}
