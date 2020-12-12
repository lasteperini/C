#include <stdio.h>
#include <stdlib.h>
#include "support.h"

void stampa(int a[], int lung) {
	int i;
	
	for(i = 0; i < lung; i++) 
		printf("%d ", a[i]);
	
	printf("\n");

}

void scambia(int a[],int i,int j) {
	int x;
	x = a[i];
	a[i] = a[j];
	a[j] = x;
	
}

int max(int x, int y) {
	if (x > y) 
		return x;
	
	return y;
}
