#include <stdio.h>
#include <stdlib.h>
#include "support.h"

void stampa(int a[], int lung) {
	int i;
	
	for(i = 0; i < lung; i++) 
		printf("%d ", a[i]);
	
	printf("\n");

}
