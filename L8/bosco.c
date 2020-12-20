#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "albero.h"

#define N 30

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

	
	Bit_node root = bit_arr2tree(a, N, 0);
		
	bit_printassummary(root, 0);
	
	return 0;
}
