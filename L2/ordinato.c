#include <stdio.h>
#define N_MAX 10

int main(void) {
	int x, store, j;
	int vector[N_MAX] = {0};
	
	
	scanf("%d", &x);
	
	while (x != 0) {
		for (int j = 0; j < N_MAX; j++) {
			if (x < vector[j] || vector[j] == 0) {
				for (int z =  N_MAX-1; z > j; z--) {
					vector[z]=vector[z-1];
				}
				vector[j]=x;
				break;
			}
		}

		printf("Nuovo array: ");
		for (int i = 0; i < N_MAX; i++) {
			printf("%d ", vector[i]);
		}
		printf("\n");
		scanf("%d",&x);
	}
	
	return 0;
}
