#include <stdio.h>
#include <ctype.h>
#define N_MAX 100

int main(void) {
	int c , numeri[N_MAX] = {0};

	c = getchar ();
	while ( c != '.' ) {
		if ( isdigit ( c ) )
			numeri[ c - '0']++;
		c = getchar ();
	}
	
	for (int i = 0; i < N_MAX; i++) {
		if (numeri[i] > 1) 
			printf("%d ==> ripetuto %d volte\n",i, numeri[i]);
	}
	
}
