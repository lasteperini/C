#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

typedef struct {
	float x, y;
} Punto ;

typedef struct {
	Punto p1 ;
	Punto p2 ;
} Rettangolo ;

Rettangolo *creaRettangolo();
void stampa( Rettangolo *r );

int main( void ){
	Rettangolo *r;
	
	r = creaRettangolo();
	
	stampa(r);
	
	return 0;
}

Rettangolo *creaRettangolo() {
	float x1, x2, y1, y2;
	Rettangolo *p;
	Rettangolo r;
	
	printf("RETTANGOLO :\n" );
	printf("Inserisci le coordinate del punto in basso a sinistra\n" );
	scanf("%f%f", &x1, &y1 );
	printf("Inserisci le coordinate del punto in alto a destra\n" );
	scanf("%f%f", &x2, &y2 );
	

	p = malloc( sizeof(Rettangolo *));
		
	r.p1.x = x1;
	r.p1.y = y1;
	r.p2.x = x2;
	r.p2.y = y2;
	
	*p = r;
	
	return p;

}

void stampa( Rettangolo *r ) {
	printf ( "Rett di vertici (%f, %f) e (%f, %f).\n",
		r ->p1.x , r -> p1.y ,
		r -> p2.x , r -> p2.y );
}
