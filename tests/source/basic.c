/*
** EPITECH PROJECT, 2017
** basic.c
** File description:
** basic tests for printf
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my_malloc.h"

void show_alloc_mem(void);

void printBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for (i=size-1;i>=0;i--) {
		for (j=7;j>=0;j--) {
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
		printf(" ");
	}
	puts("");
}

static void my_putchar(char c)
{
	write(1, &c, 1);
}

static void my_putstr(char *str)
{
	write(1, str, strlen(str));
}

static void my_putnbr(long long nb)
{
	long long mod;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			mod = (nb % 10);
			nb = (nb - mod) / 10;
			my_putnbr(nb);
			my_putchar(48 + mod);
		} else
			my_putchar(48 + nb % 10);
	}
}

void put_test(char *test, unsigned int nb)
{
	my_putstr("Test: ");
	my_putstr(test);
	my_putstr(" | no: ");
	my_putnbr((long long)nb);
	my_putstr("\n");
}

void put_got_expected(long long got, long long expected)
{
	my_putstr("Got: ");
	my_putnbr(got);
	my_putstr(" | Expected: ");
	my_putnbr(expected);
	my_putstr("\n");
}

unsigned int assert_alloc_good_size(char *test, unsigned int *nb, size_t size)
{
	void *brk_origin;
	long long got;
	long long expected;
	unsigned int good = 0;
	
	brk_origin = sbrk(0);
	malloc(size);
	got = (long long)sbrk(0) - (long long)brk_origin;
	expected = sizeof(struct meta_data) + ALIGN(size, sizeof(void*));
	if (got != expected && size != 0) {
		put_test(test, *nb);
		put_got_expected(got, expected);
		good++;
	}
	++(*nb);
	return good;
}

static unsigned int ut_malloc_sizes()
{
	char test[] = "ut_malloc_sizes";
	unsigned int nb = 0;
	unsigned int good = 0;

	good += assert_alloc_good_size(test, &nb, 0);
	for (size_t i = 1; i <= 65536; i *= 2)
		good += assert_alloc_good_size(test, &nb, i);
	good += assert_alloc_good_size(test, &nb, sizeof(int));
	good += assert_alloc_good_size(test, &nb, 200 * sizeof(char));
	good += assert_alloc_good_size(test, &nb, 1024 * sizeof(char *));
	good += assert_alloc_good_size(test, &nb, 3 * sizeof(char));
	return good;
}

int main(void)
{
	ut_malloc_sizes();
}
