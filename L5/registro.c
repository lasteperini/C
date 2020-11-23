#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 10

/*
newBook (n)
Crea un nuovo registro che permetta la prenotazione di n posti, da 0 a n - 1. 
Se esiste già un registro di
prenotazione, quest?ultimo deve essere cancellato.

book(k,name)
Se il posto k è libero, prenota il posto k per il cliente identificato da name. 
Altrimenti, stampa un messaggio di
errore.

cancel(k)
Se il posto k è occupato, cancella la prenotazione di k. Altrimenti, stampa un messaggio di errore.

move(from,to)
Sposta il cliente dal posto from al posto to se ciò è possibile (ossia, from è occupato e to libero). Altrimenti,
stampa un messaggio di errore.

printBook()
Stampa il contenuto del registro (posti prenotati).
*/

typedef struct {
	int place;
	char *name;
} Cliente;

typedef struct {
	Cliente cliente;
} Book;


Book *newBook(int n, Book *b);
void book(int k,char *name, Book *b);
void cancel(int k, Book *b);
void stampa(Book *b, int n);

int main(void) {
	Book *b;
	
	printf("creo puntatore (ad uno spazio di memoria vuoto)..\n");
	b = malloc(sizeof(Cliente));
	
	printf("Creo il Book vuoto..\n");
	b = newBook(N, b);
	printf("Done\n");
	
	printf("Assegno da 0 a 5..\n");
	book(0, "pippo", b);
	book(1, "pluto", b);
	book(2, "paperino", b);
	book(3, "basettoni", b);
	book(4, "gastone", b);
	book(5, "amelia", b);
	
	printf("Provo a riassegnare 4..\n");
	book(4, "pippo", b);
	
	printf("Cancello 4..\n");
	cancel(4, b);

	printf("Cancello di nuovo 4..\n");
	cancel(4, b);
	
	stampa(b, N);

	return 0;
}

Book *newBook(int n, Book *b) {
	Book newbook;
	Book *p;
	free(b);

	p = realloc(b, n * sizeof(Cliente) );
		
	if (p == NULL) {
		exit(EXIT_FAILURE);
	}
	
	*p = newbook;

	for (int i = 0; i < n; i++) { 
		p[i].cliente.place = 0;
		p[i].cliente.name = "";
	}
	
	return p;	
}

void book(int k,char *name, Book *b) {
	if (b[k].cliente.place == 0) {
		b[k].cliente.place = 1;
		b[k].cliente.name = name;
	} else {
		printf("Il posto %d e' gia' prenotato!\n",k);
	}
	 
}

void cancel(int k, Book *b) {
	if (b[k].cliente.place != 0) {
		b[k].cliente.place = 0;
		b[k].cliente.name = "";
	} else {
		printf("Il posto %d e' gia' libero!\n",k);
	}
	 
}

void stampa(Book *b, int n) {
	for (int i = 0; i < n; i++) {
		if (b[i].cliente.place != 0) {
			printf("Cliente %s nel posto %d\n", b[i].cliente.name, i);
		}
	}
			 
}
