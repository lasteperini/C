#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 100

void treVolte( char *a[], int n ) {
  char **p, *q; // **p = puntatore ad un puntatore
  int conta = 0;   

  for ( p = a; p < a + n; p++ ) {
  
    int contae = 0;
    char *c;
    c = *p;

    while ( *c ) {
      if ( *c == 'e' )
	contae++;
      if ( contae == 3 ) {
	conta++;
	contae=0;
      }
      c++;
    }
    if ( conta == 3 ) {
        //strcpy( q, *p ); //aggiunto il riferimento * per prendere il contenuto di **p 
	//strcpy( *p, a[0]); //idem
        //strcpy ( a[0], q);
	q = *p;
	*p = a[0];
	a[0] = q;
    	return;
    }
    
  }

}

int main( int argc, char **argv ) {
  treVolte( argv + 1, argc - 1 );
  
  for ( char** p = argv; p < argv + argc; p++  )  
    printf( "%s ", *p );
  printf( "\n" );
  return 0;
}
