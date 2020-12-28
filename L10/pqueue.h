#ifndef PQUEUE_H
#define PQUEUE_H

#define N 10

typedef struct pqueue * Pqueue ;
typedef int Item;
typedef Item * Heap ;

/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new(int n);

/* distrugge la coda di priorità */
void pqueue_destroy(Pqueue pq);

/* restituisce la lunghezza della coda di priorità */
int pqueue_length(Pqueue pq);

/* inserisce l?Item nella coda di priorità */
void pqueue_insert (Pqueue pq, Item k);

/* estrae dalla coda di priorità l?Item con chiave minima */
Item pqueue_extractmin(Pqueue pq);

/* restituisce l'Item con chiave minima nella coda di priorità */
Item pqueue_min(Pqueue pq);

void heapify_down(Heap h, int i, int n) ;
void heapify_up(Heap h, int i);

int father(int i);
int left(int i);
int right(int i);
void swap(Heap h, int i, int j);

void heap_printassummary(Pqueue pq, int i);
void heap_printnode(Heap h, int j);
void heap_printarray(Pqueue pq, int i);

#endif
