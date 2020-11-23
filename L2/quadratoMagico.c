#include <stdio.h>
#include <math.h>

int main( void ){
	int nn, n;
	int k = 1;
	int i, j, inew, jnew;
	
	printf("Insert n value: ");
	scanf(" %d", &n);
	
	int quadrato[n][n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			quadrato[i][j] = 0;
		}
	}
	
	i = 0; j = n /2;
	nn = n * n;
	
	for( k = 1; k <= nn; k ++ ) {
		quadrato[i ][ j] = k;
		inew =( i == 0 ) ? n - 1 : i - 1;
		jnew =( j == n - 1 ) ? 0 : j + 1;
		if( quadrato[ inew ][ jnew ] == 0 ) {
			i = inew;
			j = jnew;
		} else {
			i ++;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", quadrato[i][j]);
		}
		printf("\n");
	}

	return 0;
}
