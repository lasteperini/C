#include  <stdio.h>
#include <stdlib.h>
#include  <math.h>

int  main( int argc, char* argv[]) {
	
	
	float a =  atoi(argv[1]);
	float b =  atoi(argv[2]);
	float c =  atoi(argv[3]);
	
	float num = -b + sqrt((b*b)-4*a*c);
	float den = 2*a;
	
	float sol = num/den;
	
	printf("Soluzione:%.2f\n", sol);
	return 0;

	
}
