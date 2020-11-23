
/*
1.6 Da minuscolo a maiuscolo
1. Scrivete una funzione con prototipo char *maiuscolo( char *stringa ) 
che trasformi da minuscolo
in maiuscolo tutte le lettere del suo argomento stringa e ne restituisca un 
puntatore al primo carattere.
Potete assumere che stringa sia dato da una stringa terminata da '\0' 
contenente caratteri ASCII (non
solo lettere). Potete usare la funzione toupper della libreria ctype.h.
2. Testate la funzione inserendola in un programma che legga da standard 
input una frase terminata da a-capo,
la memorizzi in una stringa s, invochi la funzione, quindi ristampi la 
frase tutta in maiuscolo.
3. Come avete dichiarato s? Spiegate perché.
4. Spiegate se c?è differenza, e se sì quale, tra le seguenti dichiarazioni 
per la funzione maiuscolo:
char *maiuscolo( char *stringa )
char *maiuscolo( char stringa[] )
*/


#include <stdio.h>
#include <ctype.h>

#define N 100

char *maiuscolo( char *a );

int main(void) {
	char s[N], *p;
	s[0] = ' ';
	int i = 0;
	
	fgets(s, N, stdin);
		 
	p = maiuscolo(s);
	while (*p) {
		printf("%c",*p);
		*p++;
	}
	printf("\n");
	return 0 ;
}

char *maiuscolo( char *a ) {
	char *p = a;
	while (*a) {
		*a = toupper(*a);
		*a++;
	}
	return p;

}
