#include <stdio.h>
#include <ctype.h>

int main(void) {
	int memo[26];
	char c;
	
	for (int i = 0; i < 26; i++) {
		memo[i] = 0;
	}
	
	do {
		scanf("%c", &c);
		if (isalpha(c)) {
			memo[toupper(c)-'A'] += 1;
		}
	} while ( c != '.');

	for (int i = 0; i < 26; i++) {
		if (memo[i] != 0) {
			printf("%c ", 'A'+i);
			for (int j =0; j< memo[i]; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
		
	
}

/*

*/
