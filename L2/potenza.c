#include <stdio.h>

int potenza(int b, int e) {
	if (e > 0)
		return b * potenza(b, e-1);
	else return b;		
}

int main(void) {
	int b, e;
	scanf("%d %d", &b, &e);
	
	printf("%d\n", potenza(b,e));
	
	return 0; 
}
