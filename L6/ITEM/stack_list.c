#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"

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
		return 1;
	} else {
		return 0;
	}
}

Item pop( void ) {
	if (is_empty() == 0) {
		Node p = s -> head;
		int n = s -> head -> info;
		s -> count--;
		s -> head = s -> head -> next;
		free(p);
		return n;
	} else {
		exit(EXIT_FAILURE);
	}
}

int top( void ) {
	if (is_empty() == 0) {
		return s -> head -> info;
	} else {
		exit(EXIT_FAILURE);
	}
}

void push( Item item ) {
	Node new = malloc( sizeof (struct node));
	new -> info = item;
	new -> next = s -> head;
	s -> head = new ;
	s -> count += 1;
}

void print_stack( void ) {
	Node p;
	for (p = s -> head; p != NULL; p = p-> next) {
		print_item(p -> info);
	}
	printf("\n");
}
