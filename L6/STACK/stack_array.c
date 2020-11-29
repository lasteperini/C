#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define N 20

int Count = 0;
int Pila[N] ;

void create_stack (void) {
	printf("create stack\n");
}

void make_empty( void ) {
 	Count = 0;
}

int is_empty( void ) {
	if (Count == 0) {
		printf("stack vuoto\n");
		return 1;
	} else {
		printf("stack non vuoto\n");
		return 0;
	}
}

int pop( void ) {
	if (is_empty() == 0) {;
		int n = Pila[Count-1];
		Count--;
		printf("pop = %d\n", n);
		print_stack();
		return n;
	} else {
		exit(EXIT_FAILURE);
	}
}

int top( void ) {
	if (is_empty() == 0) {
		printf("top = %d\n", Pila[Count-1]);
		return Pila[Count-1];
	} else {
		exit(EXIT_FAILURE);
	}
}

void push( int n ) {
	printf("push = %d\n", n);
	Pila[Count++] = n;
	print_stack();
}

void print_stack( void ) {
	int i;
	for (i = 0; i < Count; i++) 
		printf( "** %d ", Pila[i]);
	printf("\n");
}
