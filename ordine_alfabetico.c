/*Scrivete un programma che legga tre coefficienti a,b, c e calcoli 
le soluzioni (complesse) dell?equazione ax2 +
bx+c. Può essere utile includere il file di intestazione math.h della 
libreria standard, contenente la funzione
sqrt per il calcolo della radice quadrata. 
Quando compilate, usate l?opzione -lm.#include <stdio.h>
*/


#include <stdio.h>


float main (void) {
	char char1, char2;
	printf("Calcola la distanza tra: ");
	scanf("%c %c", &char1, &char2);
	if ('A' <= char1 <= 'Z' && 'A' <= char2 <= 'Z')
		printf("La loro distanza e' %d: \n", char1-char2);
	else 
		printf("Non sono 2 caratteri maiuscoli\n");
	
}
