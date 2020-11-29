#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
  int info;
  struct node *next;
};

typedef struct node *Node;

typedef struct {
	Node head ;
	int count;
} Set ;

Set *s ;

void create_stack (void) {
	s = malloc( sizeof(Set));
	s -> head = NULL;
	s -> count = 0;

}

void make_empty( void ) {

  if(s->head==NULL)
    return;

  s->head=s->head->next;
  make_empty();
  s->count--;
  free(s->head);


}

int is_empty( void ) {
	if (s -> head == NULL) {
		printf("stack vuoto\n");
		return 1;
	} else {
		printf("stack non vuoto\n");
		return 0;
	}
}

int pop( void ) {
	if (is_empty() == 0) {
		Node p = s -> head;
		int n = s -> head -> info;
		s -> count--;
		s -> head = s -> head -> next;
		free(p);
		printf("pop = %d\n", n);
		print_stack();
		return n;
	} else {
		exit(EXIT_FAILURE);
	}
}

int top( void ) {
	if (is_empty() == 0) {
		printf("top = %d\n", s -> head -> info);
		return s -> head -> info;
	} else {
		exit(EXIT_FAILURE);
	}
}

void push( int n ) {
	printf("push = %d\n", n);
	Node new = malloc( sizeof (struct node));
	new -> info = n;
	new -> next = s -> head;
	s -> head = new ;
	s -> count += 1;
	print_stack();
}

void print_stack( void ) {
	Node p;
	int n = 1;
	for (p = s -> head; p != NULL; p = p-> next) {
		printf("--> %d ", p -> info);
		if ( n == 30) {break;}
		n = n+1;
	}
	printf("\n");
}
