#include <stdio.h>
#include <math.h>
#define PI 3.14

typedef struct {
	float x, y;
} Punto ;

typedef struct {
	Punto p1 ;
	Punto p2 ;
} Rettangolo ;

int main( void ){
	float area, duep, raggio, c1, c2 ;
	Rettangolo r;
	
	/*
	printf("RETTANGOLO :\n" );
	printf("Inserisci le coordinate del punto in basso a sinistra\n" );
	scanf("%f%f", &r.p1.x, &r.p1.y );
	printf("Inserisci le coordinate del punto in alto a destra\n" );
	scanf("%f%f", &r.p2.x, &r.p2.y );

	b = r.p2.x - r.p1.x;
	h = r.p2.y - r.p1.y;
	area = b * h;
	duep = 2 *( b + h );
	printf("L'area del rettangolo vale %.2f, il perimetro vale %.2f\n", area, duep );
	*/
	
	printf("CERCHIO :\n" );
	printf("Inserisci le coordinate del centro\n" );
	scanf("%f%f", &r.p1.x, &r.p1.y );
	
	printf("Inserisci le coordinate di un punto della circonferenza\n" );
	scanf("%f%f", &r.p2.x, &r.p2.y );
	
	c1 = r.p2.x - r.p1.x;
	c2 = r.p2.y - r.p1.y;
	raggio = sqrt((c1 * c1)+(c2 * c2));
	
	duep = 2*PI*raggio;
	area = PI*raggio*raggio;
	printf("L'area del cerchio vale %.2f, il perimetro vale %.2f\n", area, duep );
	

	return 0;
}
