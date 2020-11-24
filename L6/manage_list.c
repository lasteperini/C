#include <stdio.h>
#include <stdlib.h>

struct node {   
  int info;   
  struct node *next;
};

typedef struct node Node;

void list_delete( int n, struct node *l);
struct node *list_search( int n, struct node *l );
void list_print( struct node *l );
void list_insert( int n , struct node **l );

int main() {
  struct node *first = NULL;
  struct node *p = NULL;
  list_insert(5, &first);
  list_insert(7, &first);
  list_insert(12, &first);
  list_insert(4, &first);
  list_insert(8, &first);
  list_insert(12, &first);
  list_print(first);
  list_delete(7, first);
  list_print(first);
  p = list_search(7, first);
  if (p != NULL) {
  	printf("trovato: 7\n");
  } else {
  	printf("non trovato: 7\n");
  } 
  p = list_search(12, first);
  if (p != NULL) {
  	printf("trovato: 12\n");
  } else {
  	printf("non trovato: 12\n");
  } 
  return 0;
}


struct node *list_search( int n, struct node *l ){
struct node *p;
for (p = l; p != NULL; p = p-> next) {
	printf("cerco: %d current value: %d\n", n, p -> info);
 	if ( p -> info == n)
		return p;
}
  return NULL;
}

void list_delete( int n, struct node *l){
  struct node *curr, *prev;
  for ( curr = l, prev = NULL; curr != NULL; prev = curr, curr = curr -> next ) {
    if (curr -> info == n ) break;
  }
  if (curr == NULL) 
    return;
  if (prev == NULL) 
    l = l -> next;
  else 
    prev -> next = curr -> next;
  free(curr);
}

void list_insert( int n, struct node **l){
  struct node *new = malloc( sizeof (struct node));
  new -> info = n;
  new -> next = *l;
  *l = new ;
}

void list_print(struct node *l ) {
	struct node *p;
	printf("List:");
	for (p = l; p != NULL; p = p-> next)
		printf("%d ", p -> info);

	printf("\n");
}

