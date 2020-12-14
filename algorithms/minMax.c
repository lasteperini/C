#include <stdio.h>
#include <stdlib.h>

#define N 15

struct minMaxItem {   
  int min;   
  int max;
};

struct minMaxItem *minMax(int a[], int n);
struct minMaxItem *minMaxRec(int a[], int i, int f);

int main(void) {

	int a[N], c[N],x[N], n;
	struct minMaxItem *p, *q;
	
	for (int i =0; i<N; i++) {
		a[i]=0;
	}
	
	int i = 0;
	scanf("%d", &n);
	while (n != 0) {
		a[i] = n;
		c[i] = n;
		scanf("%d", &n);
		i++;
	}
	int L = i;
	
	p = minMax(a, L);	
	printf("min: %d, max: %d\n", p -> min, p -> max);

	q = minMaxRec(a, 0, L);
	printf("minRec: %d, maxRec: %d\n", q -> min, q -> max);
		
	return 0;
}

struct minMaxItem *minMax(int a[], int n) {
	struct minMaxItem *p = malloc( sizeof (struct minMaxItem));
	p -> min = a[0];
	p -> max = a[0];
	
	for (int i = 0; i < n; i++) {
		if (a[i] < p -> min) 
			p -> min = a[i];
		if (a[i] > p -> max) 
			p -> max = a[i];
	}
	
	return p;
}

struct minMaxItem *minMaxRec(int a[], int i, int f) {
	struct minMaxItem *p = malloc( sizeof (struct minMaxItem));
	
	if (f-i==1) {
		p -> min = a[0];
		p -> max = a[0];
		return p;
	}

	if (f-i==2) {
		if (a[i] < a[i+1]) {
			p -> min = a[i];
		} else {
			p -> min = a[i+1];
		}
		if (a[i] > a[i+1]) {
			p -> max = a[i];
		} else {
			p -> max = a[i+1];
		}
		return p;
	}
	
	int m = (f+i)/2;
	struct minMaxItem *first = malloc( sizeof (struct minMaxItem));
	struct minMaxItem *second = malloc( sizeof (struct minMaxItem));
	
	first = minMaxRec(a, i, m);
	second = minMaxRec(a, m, f);
	
	if (first -> min < second -> min) {
		p -> min = first -> min;
	} else {
		p -> min = second -> min;
	}
	
	if (first -> max > second -> max) {
		p -> max = first -> max;
	} else {
		p -> max = second -> max;
	}
	
	return p;
}
