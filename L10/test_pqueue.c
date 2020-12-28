#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pqueue.h"


int main(void) {

	int a[N];
	int i;

        /*inizializzamo il generatore sull'ora attuale
        dell'elaboratore time(0), in questo modo si hanno 
        valori diversi*/
	srand(time(0)); 

	for(i=0;i<N;i++){
	   a[i]=1+rand()%100; //numeri casuali tra 1 e 100
   	}
	
	Pqueue pq = pqueue_new(N+10);
	
	for(i=0;i<N-1;i++){
		printf("inserisco per a[%d]=%d: ", i, a[i]);
		pqueue_insert(pq, a[i]);
		heap_printarray(pq, i);
 		printf("\n");
  	}	
	
	
	printf("\n");
	
	heap_printassummary(pq, 1);
	
	return 0;
}
