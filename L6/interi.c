#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *next;
};

typedef struct node *Node;

typedef struct {
	Node head ;
	int count;
} Set ;


void list_insert( int n , Set *s );
void list_delete( int n, Set *s);
Node list_search( int n, Set *s );
void list_print(Set *s) ;
void list_destroy(Node l);

int main() {
	char cmd;
	int n;
	Set *s = malloc( sizeof(Set));;
	s -> head = NULL;
	s -> count = 0;
	scanf("%c", &cmd);
	Node p = NULL;
	
	while (cmd != 'f'){
		switch (cmd) {
			case '+':
				scanf("%d",&n);
				list_insert(n, s);
            			break;	
			case '-':
				scanf("%d",&n);
				list_delete(n, s);
            			break;	
			case '?':
				scanf("%d",&n);
				p = list_search(n, s);
				if ( p != NULL) {
					printf("trovato %d\n", n);
				} else {
					printf("non trovato %d\n", n);
				}
            			break;	
			case 'p':
				list_print(s);
            			break;	
			case 'c':
				printf("elem: %d\n",s -> count);
            			break;	
			default:
            			break;
		}
		scanf("%c", &cmd);		
	}
	
	return 0;
}


void list_insert( int n, Set *s){
	Node new = malloc( sizeof (struct node));
	new -> info = n;
	new -> next = s -> head;
	s -> head = new ;
	s -> count += 1;
}


void list_delete( int n, Set *s){
	Node curr, prev;
	for ( curr = s -> head, prev = NULL; curr != NULL; prev = curr, curr = curr -> next ) {
		if (curr -> info == n ) break;}
		if (curr == NULL)
			return;
		if (prev == NULL)
			s -> head = s -> head -> next;
		else
			prev -> next = curr -> next;
	s -> count -= 1;
	free(curr);
}

Node list_search( int n, Set *s ) {
	Node p;
	for (p = s -> head; p != NULL; p = p-> next) {
 		if ( p -> info == n)
			return p;
	}
  	return NULL;
}

void list_print(Set *s) {
	Node p;
	int n = 1;
	for (p = s -> head; p != NULL; p = p-> next) {
		printf("--> %d ", p -> info);
		if ( n == 30) {break;}
		n = n+1;
	}
	printf("\n");
	
}

