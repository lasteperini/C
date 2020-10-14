#include <stdio.h>
#define MAX 10

int main(void) {
	int max = MAX, min = 0, n;
	char parola;
	
	for (;;) {
		n = min + (max-min)/2;
		printf("\nil numero e' %d? " , n);
		scanf( " %c" , &parola);
		switch (parola) {
			case '>': min = n+1; break;
			case '<': max = n-1; break;
			case '=': return 0;
		}
	}
	return 1;

}
