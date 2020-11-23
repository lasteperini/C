#include <stdio.h>
#include <ctype.h>

int main(void) {
	int memo[26], anagramma[26];
	char c;
	
	for (int i = 0; i < 26; i++) {
		memo[i] = 0;
	}

	for (int i = 0; i < 26; i++) {
		anagramma[i] = 0;
	}
	
	do {
		scanf("%c", &c);
		if (isalpha(c)) {
			memo[toupper(c)-'A'] += 1;
		}
	} while ( c != ' ');

	do {
		scanf("%c", &c);
		if (isalpha(c)) {
			anagramma[toupper(c)-'A'] += 1;
		}
	} while ( c != '.');

	for (int i = 0; i < 26; i++) {
		if (memo[i] != anagramma[i]) {
			printf("Non e' un anagramma\n");
			return 0;
		}
	}
	printf("E' un anagramma\n");
	return 0;
		
	
}

/*

*/
