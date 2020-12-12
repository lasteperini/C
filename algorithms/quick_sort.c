#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "merge.h"

#define N 15

void quickSort(int a[], int i, int f);
int partiziona(int a[], int i, int f);

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
	
	quickSort(a, 0 , L);
	stampa(a, L);
	
	return 0;
}

void quickSort(int a[], int i, int f) {
	if (f-i > 1) {
		// scegli un elemento di A come perno
		int perno = partiziona(a, i, f);
		int b[perno-i], c[f-perno+1];
		for (int j = 0; j < perno+1; j++)
			b[j] = a[j];
		int k = 0;
		for (int j = perno+1; j < f; j++) {
			c[k] = a[j];
			k++;
		}
		quickSort(b, 0, perno+1);
		quickSort(c, 0, f-perno-1);
		for (int j = 0; j < perno+1; j++)
			a[j] = b[j];
		k = 0;
		for (int j = perno+1; j < f; j++) {
			a[j] = c[k];
			k++;
		}
		//stampa(a, f-i);
	}
}

int partiziona(int a[], int i, int f) {
/* Riorganizza gli elementi all'interno di A[i..f ? 1] e restituisce un
indice j in modo tale che tutti gli elementi di A[i..j ? 1] siano minori o
uguali ad A[j] e tutti gli elementi di A[j + 1..f ? 1] siano maggiori
di A[j] */
	int perno = a[i]; // scelgo il primo elemento come perno
	int sx = i;
	int dx = f;
	while (sx < dx) {
		// se l'elemento dopo il perno e' maggiore del perno, sposto l'indice di dx verso sx
		do {dx--;} while (a[dx] > perno);
		// se l'elemento prima del perno e' minore o uguale al perno, sposto l'indice di sx verso dx
		do {sx++;} while (sx < dx && a[sx] <= perno);
		if (sx < dx) 
			scambia(a, sx, dx);
	}	
	scambia(a, i, dx);
	
	return dx;
}
