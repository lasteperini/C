#include <stdio.h>
#define N 100

int main (void) {
	char testo[N] = {' '};
	int i = 0;

	scanf ( "%d %d" , &divisore , &dividendo );

	do {
		c[resto++] = divisore % dividendo; 
		printf("( divisore /= dividendo ) vale %d\n", ( divisore /= dividendo ));
		printf("resto vale %d\n", c[resto-1]);		
	} while ( ( divisore /= dividendo ) > 0 );

	while ( resto > 0 )
		printf ( "%d" , c[--resto] );
		printf ( "\n" );

	return 0;
}
