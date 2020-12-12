#include <stdio.h>
#include <stdlib.h>
#include "support.h"

#define N 15

void bubblesort(int a[], int n);

int main(void) {
	int a[N], n;
	
	for (int i =0; i<N; i++) {
		a[i]=0;
	}
	
	int i = 0;
	scanf("%d", &n);
	while (n != 0) {
		a[i] = n;
		scanf("%d", &n);
		i++;
	}
	int L = i;
	bubblesort(a, L);
	
	return 0;

}

void bubblesort(int a[], int n) {
	typedef int bool;
	bool flag = TRUE;
	int i = 1;
	
	while (flag == TRUE && i < n) {
		flag = FALSE;
		for (int j=1;j < n-i; j++) {
			if (a[j] < a[j-1]) {
				scambia(a, j, j-1);
				flag = TRUE;
			}
		}
		i++;
		stampa(a, n);
	} 
}
