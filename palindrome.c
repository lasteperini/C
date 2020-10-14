#include <stdio.h>
#define N_MAX 100

int main(void) {
	char c;
	int i =0, medio;
	char array[N_MAX];
	
	
	
	while (c != '.') {
		scanf("%c", &c);
		array[i] = c;
		i++;
	} 
	
	i--;
	
	if (i%2==0) 
		medio = i/2;
	else
		medio = (i-1)/2;
	
	for (int z = 0; z < medio+1; z++) {
		if (array[z] != array[i-z-1]) {
			printf("Non e' palindroma\n");
			return 0;
		}
		
	}
	
	printf("E' palindroma\n");
	
	return 0;
}
