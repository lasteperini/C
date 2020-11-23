#include <stdio.h>

int nextCollatz(int n) {
	if (n%2 == 0) 
		return n/2;
	else return (3 * n)+1;
}

int main(void) {
	int n, counter = 1;
	
	scanf("%d", &n);
		
	do {		
		printf("%d ", n);
		n = nextCollatz(n);
		counter++;
	} while (n != 1);

	printf("%d ", n);

	printf("\nLunghezza: %d\n", counter);
	return 0;
}
