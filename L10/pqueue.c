#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"


struct pqueue {
	Heap h;
	int size , count ;
};



/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new(int n) {
	Pqueue pq = malloc(sizeof(Pqueue));
	pq -> h = malloc(sizeof(Heap));
	pq -> count = 0;
	pq -> size = n;
	
	return pq;
}

/* distrugge la coda di priorità */
void pqueue_destroy(Pqueue pq) {
	free(pq -> h);
	free(pq);
}

/* restituisce la lunghezza della coda di priorità */
int pqueue_length(Pqueue pq) {
	return pq -> count;
}

/* inserisce l'Item nella coda di priorità */
void pqueue_insert(Pqueue pq, Item k) {
	if (pq -> count < pq -> size-1) {
		pq -> count += 1;
		pq -> h[pq -> count] = k;
		heapify_up(pq -> h, pq -> count);
	}
}

/* inserisce l'Item nella coda di priorità */
void pqueue_remove(Pqueue pq, Item k) {
	swap(pq -> h, 1, pq -> count);
	pq -> count -= 1;
	heapify_down(pq -> h, 1, pq -> count);
}

/* estrae dalla coda di priorità l?Item con chiave minima */
Item pqueue_extractmin(Pqueue pq) {
	Item min = pqueue_min(pq);
	pqueue_remove(pq, 1);
	
}

/* restituisce l'Item con chiave minima nella coda di priorità */
Item pqueue_min(Pqueue pq) {
	return pq -> h[1];
}

void heapify_up(Heap h, int i) {
	if (i > 1) {
		int j = father(i);
		if (h[i] < h[j] ) {
			swap(h, i, j);
			heapify_up(h, j);
		}
	}
}

void heapify_down(Heap h, int i, int n) {
	if ( 2* i <= n ) { /* i ha almeno un figlio */
		int j ; /* indice del figlio di i con chiave minore */
		if (2* i == n) /* i ha solo il figlio sinistro */
			j = 2* i ;
		else /* i ha due figli */
			j = h[2* i] < h[2* i +1] ? 2* i : 2* i + 1;
			if (h[2* i] < h[2* i +1]) {
				swap(h, i, j);
				heapify_down(h, j, n);
			}
	}
}

int father(int i) {
	return i/2;
}

int left(int i) {
	return 2 * i;
}

int right(int i) {
	return (2 * i)+1;
}

void swap(Heap h, int i, int j) {
	Item temp;
	temp = h[i];            /* contenuto di pointer */
	h[i] = h[j];
	h[j] = temp;
}

void heap_printassummary(Pqueue pq, int i)  {
	if ( i < pq -> count ) {
		heap_printnode(pq -> h, i);
		if (2 * i <= pq -> count  || (2 * i)+1 <= pq -> count) {
			heap_printassummary(pq, 2 * i);
			heap_printassummary(pq,(2 * i)+1);
		}
	} else {
		for (int j = 0; j < i; j++) 
			printf("  ");
		printf("*X\n");
	}
}

void heap_printnode(Heap h, int j)  {
	for (int i = 1; i < j; i++) 
		printf("  ");
	printf("*%d \n", h[j]);
}

void heap_printarray(Pqueue pq, int i) {
	for(int j=0;j<i+2;j++){
		printf("|%d|",pq -> h[j]);
   	}
}	

