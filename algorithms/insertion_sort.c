#include <stdio.h>
#include <stdlib.h>
#include "support.h"

#define N 15

void insertionsort(int a[], int n);

int main(void) {
	int a[N], n;
	
	for (int i =0; i<N; i++) {
		a[i]=0;
	}
	
	int i = 0;
	scanf("%d", &n);
	while (n != 0) {
		a[i] = n;
		scanf("%d", &n);
		i++;
	}
	int L = i;
	insertionsort(a, L);
	
	return 0;

}

void insertionsort(int a[], int n) {
	int x, j = n;
	for (int k = 0; k < n; k++) {
		x = a[k];
		j = k-1;
		while (j >= 0 && a[j] > x) { // finche' j > 0 e il record e' maggiore di x
			a[j+1] = a[j]; // sposto tutti i record
			j--;
		}
		a[j+1] = x; // inserisco x al posto giusto
		stampa(a,n);
	}
}
