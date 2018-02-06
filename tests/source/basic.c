/*
** EPITECH PROJECT, 2017
** basic.c
** File description:
** basic tests for printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "my_malloc.h"

//#define align8(x) (((((x)-1)>>5)<<5)+32)
//#define align4(x) (((((x)-1)>>2)<<2)+4)
//# define ALIGN(x, y) (((x) + ((y) - 1)) & ~((y) - 1))
void show_alloc_mem(void);

void printBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for (i=size-1;i>=0;i--)
	{
		for (j=7;j>=0;j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
		printf(" ");
	}
	puts("");
}

//Test(my_printf_basic, lala)
int main()
{
	void *brk = sbrk(0);
	char *l = malloc(sizeof(char) * 4);
	long long addrl = (long long)l;
	free(l);
	int *i = malloc(sizeof(int));
	printf("break begin: %lld\n", (long long)brk);
	show_alloc_mem();
//	write(1, l, 2);
	printf("addrl: %lld\n", addrl);
	printf("addri: %lld\n", (long long)i);
	printf("MINUS: %lld\n", addrl - (long long)i);
	printf("ALIGN 8 : %ld\n", ALIGN(8, sizeof(void*)));
	printf("sizeof struct : %d\n", sizeof(struct meta_data));
	printf("sizeof size_t : %d\n", sizeof(size_t));
//	if (l == NULL)
//		write(1, "NULL\n", 5);
	
//	int *lll = sbrk(0);
//	*(lll + 1) = 200;
//	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//	(void)mutex;
//	int lal = 8;
//	printf("%ld\n", sizeof(void*));
//	printf("%ld\n", ALIGN(lal, sizeof(void*)));

//	int *p1 = malloc(48);
//	int *p2 = malloc(1);
//	printf("p1: %lld\np2: %lld\n", (long long)p1, (long long)p2);

//	printBits(sizeof(*p1), &p1);
//	printBits(sizeof(*p2), &p2);
//	int *i = malloc(sizeof(int));

//	*i = 15;
//	printf("%p\n", i);	
//	i = (int *)(((char*)i) + 1);
//	printf("%p\n", i);
//	printBits(sizeof(i), &i);
//	int *u = (int *)((long long)i << 2);
//	i = (int *)align8((long long)i);
//	printBits(sizeof(i), &i);


	
/*	printf("%p\n", sbrk(0));
	printf("%#llx\n", align8((long long)sbrk(0)));
	printf("sizeof int: %ld\n", sizeof(int));
	char *p = malloc(sizeof(char));
	printf("p: %lld\n", (align8((long long)p) + 1) % 8);
	printf("%p\n", sbrk(0));
	free(p);
	printf("%p\n", sbrk(0));
	printf("%p\n", sbrk(0));
//	printf("salu%dt\n", 12);*/

/*	printf("sbrk(0): %p\n", sbrk(0));
	printf("sbrk(0): %p\n", sbrk(0));
	printf("sbrk(5): %p\n", sbrk(5));
	printf("sbrk(0): %p\n", sbrk(0));
	printf("sbrk(-5): %p\n", sbrk(-5));
	printf("sbrk(0): %p\n", sbrk(0));*/
}
