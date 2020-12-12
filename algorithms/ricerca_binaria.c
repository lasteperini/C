#include <stdio.h>
#include <stdlib.h>
#include "support.h"

#define N 15

int ricBin(int a[], int n, int x);

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
	
	scanf("%d", &n);
	int index = ricBin(a, L, n);
	
	printf("indice: %d\n", index);
	
	return 0;

}

int ricBin(int a[], int n, int x) {
	int sx = 0, dx = n, pos = -1, m;
	
	while (sx < dx && pos == -1) {
		m = (sx+dx)/2;
		if ( x == a[m]) 
			pos = m;
		else if (x < a[m]) 
			dx = m;
		else 
			sx = m;
	
	}
	
	return pos;

}
