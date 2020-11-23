#include <stdio.h>

int main(void) {
	// usiamo un algoritmo di ordinamento
	int n, j;
	scanf("%d", &n);
	
	int A[n];
	
	for (int i=0;i<n;i++) {
		scanf("%d",&j);
		A[i] = j;
	}
	
	int sx = 0, dx = n-1;
	
	while (sx < dx) {
		// a ogni ciclo rimuovo le parti da non toccare
		int j = sx;
		while (A[j] == 0) {
			j++;// non fare nulla
		}
		sx = j;
		int z = dx;
		while (A[z] == 1) {
			z--; // non fare nulla
		}
		dx = z;
		// rimane la parte dell'array centrale da riordinare
		// del tipo: 1 0 0 1 1 0
		// se esiste, inizia per forza con un 1 e finisce con uno 0
		// allora scambio il primo con l'ultimo!
		while (sx < dx) {
			// essendo valori biari non mi serve neppure la variabile di appoggio...
			A[sx] = 0;
			A[dx] = 1;
			sx++;
			dx--;			
		}
		
	}
	
	for (int i=0;i<n;i++) {
		printf("%d ",A[i]);
	}
	printf("\n");
	
	return 0;
	
}
