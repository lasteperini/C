#include <stdio.h>

/*
1. Scrivete una funzione che stabilisca se il suo argomento è una parola 
palindroma oppure no, usando due puntatori per scorrere la parola partendo 
dall?inizio e dalla fine.
Nota bene. Come va dichiarato l?argomento della funzione? 
Come vanno dichiarati i due puntatori?
Osservate a che cosa puntano...
2. Scrivete un programma che riceve una parola come argomento da linea di 
comando, quindi invoca la funzione appena scritta per stabilire se si tratta 
di una parola palindroma oppure no.
3. Modificate il programma affinché riceva da linea di comando una 
sequenza di parole e stabilisca, per
ciascuna di esse, se si tratta di una parola palindroma oppure no*/

void palindroma(char *a);
int lun_stringa ( const char * s );

int main(int argc, char **argv) {

	for (int i = 1; i < argc; i++ ) {
		palindroma(argv[i]);
	}
		
	return 0;	

}

void palindroma(char *a) {
	int n = 0, i = 0;
	
	n = lun_stringa(a);
		
	while (*(a+i) == *(a+n-1-i) && i < n/2) {
		i++;
	}
	
	printf("%s ", a);
	
	if (i != 0 && n%i <= 1) 
		printf("palindroma\n");
	else
		printf("non palindroma\n");	
	
}
	
int lun_stringa ( const char *s ) {
	const char *p = s ;
	while ( * s ++ )
	;
	return s - p - 1;
}
