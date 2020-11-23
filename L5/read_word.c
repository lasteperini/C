#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char *read_line( char c ); //deve leggere una riga terminata dal carattere c;
char **read_word( void ); 

/*deve leggere una parola di caratteri alfanumerici (la lettura deve 
interrompersi al primo carattere non alfanumerico; se il primo carattere 
letto non è alfanumerico, la stringa restituita sarà la stringa
vuota).
*/

int main(int argc, char **argv) {
	char c;
	char *p, *w;
	char **q;
	
	c = **(argv+1);
		
	p = read_line(c);
	
	printf("riga letta:\n");
	
	while (*(p+1)) {
		printf("%c",*p++);
	}
	
	printf("\n");
	
	// la parte read_word legge in realta'
	// lo stdin successivo alla read_line
	
	q = read_word();
	
	while (**q) {
		w = *q;
		printf("parola letta:\n");
		while (*w) {
			printf("%c",*w++);
		}
		printf("\n");
		q++;
	}
	return 0;
	
}

char *read_line(char c) {
	char *p, *tmp;
	char a;
	int size = 2, i = 1;
	
	p = malloc(size * sizeof( char));
	
	if (p == NULL) {
		exit(EXIT_FAILURE);
	}
	
	scanf("%c", p);
	while (*(p+i-1) != c) {
		if (i >= size) {
			size = 2 * size;
			tmp = realloc(p, size * sizeof(char));
			if (tmp == NULL) {
				exit(EXIT_FAILURE);
			}
			p = tmp;
		}
		scanf("%c",(p+i));
		i++;		
	}
	scanf("\0",(p+i));

	return p;
}

char **read_word(void) {
	char *tmp;
	char **m, **tmpnum;
	int  num = 2, size = 2, j = 0;
	
	printf("leggo le parole\n");
	
	// creo un array di puntatori
	m = malloc(num * sizeof(char *));	
	// array per la prima parola
	*m = malloc(size * sizeof( char));
	
	if (*m == NULL || m == NULL) {
		exit(EXIT_FAILURE);
	}
	
	
	while ( j < 5) {
		printf("j == %d\n", j);
		*(m+j) = malloc(size * sizeof( char));
		if (j >= num) {
			num = 2 * num;
			tmpnum = realloc(m, num * sizeof(char *));
			if (tmpnum == NULL) {
				exit(EXIT_FAILURE);
			}
			m = tmpnum;
		}
		scanf("%c",*(m+j));
		int i = 0;
		while(isalpha(*(*(m+j)+i)) && *(*(m+j)+i) != ' ') {
			i++;
			if (i >= size) {
				size = 2 * size;
				tmp = realloc(*(m+j), size * sizeof(char));
				if (tmp == NULL) {
					exit(EXIT_FAILURE);
				}
				*(m+j) = tmp;
			}
			scanf("%c",(*(m+j)+i));
		}	
		*(*(m+j)+i) = '\0';
		j++;	
	}
	return m;
	
}
