#include <stdlib.h>
#include <stdio.h>

void *my_realloc( void *p, size_t n ) {
  void *r;
  r = realloc( p, n );
  if ( r == NULL ) {
      printf( ".....\n" );
      exit( EXIT_FAILURE );
  } 
  
  return r;
}

int main(void) {
	return 0;
}

