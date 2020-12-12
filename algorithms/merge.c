#include <stdio.h>
#include <stdlib.h>
#include "support.h"


void merge( int a[], int b[], int c[], int L1, int L2) {
	int i1 = 0, i2 = 0, k = 0;
		
	while (i1 < L1 && i2 < L2) {
		if (b[i1] < c[i2]) {
			a[k] = b[i1];
			i1++;
		} else {
			a[k] = c[i2];
			i2++;
		}
		k++;			
	}
	if (i1 < L1) {
		for (int j = i1; j < L1; j++) {
			a[k] = b[j];
			k++;
		}
	} else {
		for (int j = i2; j < L2; j++) {
			a[k] = c[j];
			k++;
		}
	}
	
}
