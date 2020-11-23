#include <stdio.h>

int main(void) {
	int n, j;
	
	scanf("%d", &n);
	
	int input[n];
	
	for (int i=0; i < n; i++) {
		scanf("%d", &j);
		input[i] = j;
	}
	
	int sx = 0, dx = n, m ;
	
	m = n/2;
		
	while (sx < dx ) {
		if (input[m] == input[0]+m) {
			sx = m+1;
		} else {		
			dx = m;
		}
		m = (dx+sx)/2;					
	}
	printf("valore mancante: %d\n",input[0]+m);
	return 0;


}
