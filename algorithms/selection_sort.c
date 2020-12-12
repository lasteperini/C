#include <stdio.h>
#include <stdlib.h>
#include "support.h"

#define N 15

void selectionsort(int a[], int n, int L);

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
	selectionsort(a, L, L);
	
	return 0;

}

void selectionsort(int a[], int n, int L) {
	int max = a[0], tag = 0;

	if (n > 1) {
		for (int i = 1; i < n; i++) {
			if (a[i] > max) {
				tag = i;
				max = a[i];
			}
		}
		scambia(a, tag, n-1);
		stampa(a,L);
		selectionsort(a, n-1, L);
	}
}
