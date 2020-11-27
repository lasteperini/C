#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *next;
};

typedef struct node *Node;

void list_delete( int n, Node l);
Node list_search( int n, Node l );
void list_print( Node l );
void list_insert( int n , Node *l );
void list_printInv( Node l );
int *listToArray(Node l);
void list_destroy( Node l );
Node olist_insert( int n, Node l );
Node olist_search( int n, Node l );

int main() {
	Node head = NULL;
	Node p = NULL;

	list_insert(5, &head);
	list_insert(7, &head);
	list_insert(12, &head);
	list_insert(4, &head);
	list_insert(8, &head);
	list_insert(12, &head);
	printf("\nLista 1:");
	list_print(head);
	list_delete(7, head);
	p = list_search(7, head);
	if (p != NULL) {
  		printf("trovato: 7\n");
	} else {
  		printf("non trovato: 7\n");
	}
	p = list_search(12, head);
	if (p != NULL) {
  		printf("trovato: 12\n");
	} else {
  		printf("non trovato: 12\n");
	}
	printf("\nprint inverso:");
	list_printInv(head);
	list_print(head);
	list_destroy(head);
	head = NULL;
	list_insert(12, &head);
	list_insert(9, &head);
	list_insert(6, &head);
	list_insert(2, &head);
	list_insert(1, &head);
	printf("\nLista 2:");
	list_print(head);
	Node q = olist_insert(4,head);
	printf("\nDopo inserimento ordinato di 4:");
	list_print(head);
	q = olist_search(8,head);
	q = olist_search(15,head);
	q = olist_search(6,head);
  return 0;
}


Node list_search( int n, Node l ) {
	Node p;
	for (p = l; p != NULL; p = p-> next) {
 		if ( p -> info == n)
			return p;
	}
  	return NULL;
}

void list_delete( int n, Node l){
	Node curr, prev;
	for ( curr = l, prev = NULL; curr != NULL; prev = curr, curr = curr -> next ) {
		if (curr -> info == n ) break;}
		if (curr == NULL)
			return;
		if (prev == NULL)
			l = l -> next;
		else
			prev -> next = curr -> next;
	free(curr);
}

void list_insert( int n, Node *l){
	Node new = malloc( sizeof (struct node));
	new -> info = n;
	new -> next = *l;
	*l = new ;
}

/*
1. Scrivete una funzione void list_print( Node l ) che stampa gli 
elementi di una lista (individuata dall?indirizzo del suo primo elemento).
*/
void list_print(Node l ) {
	Node p;
	int n = 1;
	for (p = l; p != NULL; p = p-> next) {
		printf("--> %d ", p -> info);
		if ( n == 20) {break;}
		n = n+1;
	}
	printf("\n");
	
}

/*
2. Scrivete una funzione ricorsiva void list_printInv( Node l ) 
che stampa gli elementi della lista al contrario.
Nel passo iterativo, la funzione dovrà prima richiamare sé stessa 
sul prossimo nodo e poi concludersi stampando
il valore del nodo corrente
*/

void list_printInv(Node l) {
	if (l->next != NULL) {
		list_printInv(l -> next);
	} else {
		printf("\n");
	}
	printf("%d ", l -> info);

}

/*
3. Scrivete una funzione che, data una lista, costruisce un array con gli 
elementi della lista e ne restituisce l'indirizzo;
l'array va allocato dinamicamente
*/

/*
4. Scrivete una funzione int* listToArray( Node l ) che, data una lista l 
contenente n interi, restituisce l'indirizzo di un array di interi allocato 
dinamicamente contenente gli elementi della lista.
*/

int *listToArray(Node l) {
	Node p;
	int *a, size = 5, i = 0;
	for (p = l; p != NULL; p = p-> next)
		if ( i >= size  ) {
			size += 5;
			a = realloc( a, size * sizeof(int) );
		}
		a[i++] = p -> info;
	
	return a;
}

/*5. Scrivete una funzione void list_destroy( Node l ) che cancelli tutti 
gli elementi della lista e liberi con free lo spazio che era occupato dai nodi. 
Provate a scrivere la funzione sia in forma iterativa che in forma
ricorsiva. Perché la funzione è di tipo void?
*/

void list_destroy( Node l ) {
	if (l->next != NULL) {
		list_destroy(l -> next);
	} 
	l -> next = NULL;
	free(l);
}

/*1. Scrivete una funzione struct node *olist_insert( int n, struct node *l ) che inserisca 
un elemento di valore n nella lista ordinata l. 
Per trovare la posizione corretta in cui inserire n potete scorrere la lista fintanto che
il nodo corrente contiene un valore minore di quello di n.
*/

Node olist_insert( int n, struct node *l ) {
	struct node *curr, *prev;
	for ( curr = l, prev = NULL; curr != NULL; prev = curr, curr = curr -> next ) {
		if (curr -> info > n ) {
			printf("\nLeggo %d allora inserisco %d", curr -> info, n);
			Node new = malloc( sizeof (struct node));
			new -> info = n;
			new -> next = curr;
			prev -> next = new ;
			break ;
		} else {
			printf("\nLeggo %d", curr -> info);
		}
		if (curr == NULL)
			return;
		if (prev == NULL)
			l = l -> next;
	}
}

/*
2. Scrivete una funzione struct node *olist_search( int n, struct node *l ) che cerchi un elemento 
di valore n nella lista ordinata l. In quali casi si può interrompere la scansione della lista 
prima di arrivare all'ultimo elemento?
*/
Node olist_search( int n, Node l ) {
	struct node *curr, *prev;
	for ( curr = l, prev = NULL; curr != NULL; prev = curr, curr = curr -> next ) {
		if (curr -> info > n) {
			break;
		} 
		if (curr -> info == n ) {
			printf("Elemento %d trovato\n", n);
			return curr;
		} 
	}
	printf("Elemento %d non trovato\n", n);
	return NULL;
}

