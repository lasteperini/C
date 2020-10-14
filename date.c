#include <stdio.h>
#include <ctype.h>
#define N_MAX 10
#define TRUE 1
#define FALSE 0

int main(void) {
	char ld1, ld2, lm1, lm2, la1, la2, la3, la4;
	int i = 0, gain=N_MAX;
	
	typedef struct {char d1; char d2;} Giorno;
	typedef struct {char m1; char m2;} Mese;
	typedef struct {char a1; char a2; char a3; char a4;} Anno;
	typedef int bool; 
	bool flag = FALSE;
	
	typedef struct {
		Giorno giorno;
		Mese mese;
		Anno anno;
	} Data;
	
	Data leggidata[N_MAX];
	
	while ( i < N_MAX) {
		flag == FALSE;
		scanf("%c%c/%c%c/%c%c%c%c", &ld1,&ld2,&lm1,&lm2,&la1,&la2,&la3,&la4);
		if (ld1 != '0' || ld2 != '0' || lm1 != '0' || lm2 != '0') {
			flag = TRUE;
		}
		if (la1 != '0' || la2 != '0' || la3 != '0' || la4 != '0') {
			flag = TRUE;
		}
		if (flag == TRUE) {
			printf("ok per i=%d " , i);
			leggidata[i].giorno.d1 = ld1;
			leggidata[i].giorno.d2 = ld2;
			leggidata[i].mese.m1 = lm1;
			leggidata[i].mese.m2 = lm2;
			leggidata[i].anno.a1 = la1;
			leggidata[i].anno.a2 = la2;
			leggidata[i].anno.a3 = la3;
			leggidata[i].anno.a4 = la4;


			i++;
		}
		
		if  (flag == FALSE) {
			printf("Fine a i = %d\n", i);
			int gain = i-1;
			i = N_MAX-1;
		}
		
		
		
	} ;
	
	for (int j = 0; j < gain-1; j++) {
		printf("%c%c/%c%c/%c%c%c%c\n",
			leggidata[j].giorno.d1,
			leggidata[j].giorno.d2,
			leggidata[j].mese.m1,
			leggidata[j].mese.m2,
			leggidata[j].anno.a1,
			leggidata[j].anno.a2,
			leggidata[j].anno.a3,
			leggidata[j].anno.a4 );		
	}
			
	return '0';
	
}

/*

*/
