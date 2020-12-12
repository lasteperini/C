#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "merge.h"

#define N 15

void mergeSort(int a[], int n);
void mergeSortIter(int a[], int x[], int i, int f);

int main(void) {

	int a[N], c[N],x[N], n;
	
	for (int i =0; i<N; i++) {
		a[i]=0;
	}
	
	int i = 0;
	scanf("%d", &n);
	while (n != 0) {
		a[i] = n;
		c[i] = n;
		scanf("%d", &n);
		i++;
	}
	int L = i;

	mergeSort(a, L);
	printf("Recursive: ");	
	stampa(a, L);
	mergeSortIter(c, x, 0, L);	
	printf("Iteration: ");	
	stampa(c, L);
	
	return 0;
}

void mergeSort(int a[], int n) {
	int c[n/2], b[n/2];
	int z = 0, m;

	if (n > 1) {
		m = n/2;
		for (int j = 0; j < m; j++) 
			b[j] = a[j];
		for (int j = m; j < n; j++) {
			c[z] = a[j];
			z++;
		}
		mergeSort(b,m);
		
		mergeSort(c,n-m);
		
		merge(a, b, c, m, n-m);

	}

}

void mergeSortIter(int a[], int x[], int i, int f) {
	int m;

	if (f-i > 1) {
		m = (i+f)/2;
		mergeSortIter(a, x, i, m);
		
		mergeSortIter(a, x, m, f);
		
		mergeIter(a, i, m, f, x);

	}

}
