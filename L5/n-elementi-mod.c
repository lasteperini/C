#include <stdio.h>
#include "my-malloc.c"

int *read_n( int *num);

int main(void) {
	int n;
	int *p;
	
	p = read_n(&n);
	
	for (int i =0; i < n; i++) {
		printf("%d*%d == %d \n",p[i], p[i], p[i] * p[i]);
	}
	
	return 0;
	
	
}



int *read_n( int *num ) {
  int *a, i;
  scanf( "%d", num );
    
  a = my_malloc( *num * sizeof(int) );
  while ( i < *num) {
    scanf( "%d", (a+i++) );
  }

  return a;
}
