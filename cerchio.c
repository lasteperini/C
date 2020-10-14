#include <stdio.h>
#include <math.h>

#define pi_greco 3.14f

float main (void) {
	float r;
	printf("ampiezza raggio: ");
	scanf("%f", &r);
	printf("il raggio e' %.2f\n", r);
	printf("l'area e' %.2f\n", r*r*pi_greco);
}
