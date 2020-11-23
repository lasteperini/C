#include <stdio.h>
#include "libpsgraph.h"


int curva(int x, int i) {

	if (i == 0) 
		draw(x);
	else 
		if (i == 1) {
			draw(x/3);
			turn(300);
			draw(x/3);
			turn(120);
			draw(x/3);
			turn(120);
			draw(-x/3);
		}
	else { // i =2, 3 ,...,n 
		curva(x/3,i-1);
		turn(120);
		curva(x/3,i-1);
		turn(300);
		curva(x/3,i-1);
		turn(120);
		curva(x/3,i-1);
	}
	
	return 0;
	

}

int main(void) {
	int x = 100, i=4;
	
	//scanf("%d %d", &x, &i);
	
	start("curvaDiKoch.ps");
	
	curva(x,i);
	
	end();
		
	return 0;
}
