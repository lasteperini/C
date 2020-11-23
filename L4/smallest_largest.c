#include <stdio.h>
#include <string.h>

void smallest_largest( char *s[], int n, char **smallest, char **largest );

/*
che, dato un array s lungo n di stringhe, trovi gli elementi minimo e massimo nell?array 
(secondo l?ordine
alfabetico) e memorizzi i loro indirizzi negli indirizzi di memoria puntati 
rispettivamente da smallest e da
largest.
Suggerimenti: vedete somiglianze con la funzione max_secondmax? Prima di cominciare 
rappresentate graficamente quale deve essere lo stato della memoria subito dopo 
l?invocazionedella funzione e subito prima del
return.
*/


int main(int argc, char **argv) {
	char **q, **p;
	
	if (argc > 2) {
		// dereferenzio
		// non possono avere lo stesso indirizzo!!!
		q = argv+1;
		p = argv+2;

		smallest_largest(argv+1, argc-1, q, p);
	} else {
		q = argv+1;
		p = q;
	}
	printf("smallest: %s\n",*q);
	printf("largest: %s\n",*p);
	
	return 0;
}

void smallest_largest(char *s[], int n, char **smallest, char **largest ) {
	char **p;
		
	
	// ciclo su tutti i puntatori
	for (p = s; p < s + n; p++) {
		if (strcmp(*p, *smallest) < 0) {
			*smallest = *p;
		}
		if (strcmp(*p, *largest) > 0) {
			*largest = *p;
		}
	} 

}
