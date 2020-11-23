/*Scrivete un programma che legga tre coefficienti a,b, c e calcoli 
le soluzioni (complesse) dell?equazione ax2 +
bx+c. Può essere utile includere il file di intestazione math.h della 
libreria standard, contenente la funzione
sqrt per il calcolo della radice quadrata. 
Quando compilate, usate l?opzione -lm.#include <stdio.h>
*/


#include <stdio.h>
#include <math.h>

#define pi_greco 3.14f

float main (void) {
	float a,b,c;
	printf("fornisci i valori dei coefficienti a, b e c: ");
	scanf("%f %f %f", &a, &b, &c);
	float val1 = sqrt(abs(b*b-4*a*c));
	float pippo = b*b-4*a*c;
	printf("pippo vale: %.2f\n", pippo);
	printf("abs(pippo) vale: %.2f\n", abs(pippo));
	printf("sqr(abs(pippo)) vale: %.2f\n", sqrt(abs(pippo)));
	printf("x2 vale: %.2f\n", (-b-sqrt(abs(b*b-4*a*c)))/(2*a));
	printf("x1 vale: %.2f\n", (-b+sqrt(abs(b*b-4*a*c)))/(2*a));
}
