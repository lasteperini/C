#include <stdio.h>

void scambia( int *p, int *q );

int main(void) {
	int a = 6, b = 12;
	int *p, *q;
	
	printf("a = %d, b = %d\n", a, b);
	
	scambia(&a, &b);
	
	printf("a = %d, b = %d\n", a, b);
	
	return 0;
}

void scambia(int *p, int *q) {
	int x;
	x = *p;
	*p = *q;
	*q = x;
	
}
