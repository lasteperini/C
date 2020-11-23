#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define R 10
#define C 10

int main (void) {
	char pa[R][C];
	int row=0, col=0, uscita=0;
	char valprossimo = 'A';
	enum direction { up, down, right, left};
	enum state { continua, stop} todo = continua;
	for(int r=0;r<R;r++) {
		for (int c=0;c<C;c++)
			pa[r][c]='.';
	}


	pa[row][col]=valprossimo;
	valprossimo++;
	srand(time(NULL));

	while (todo==continua && valprossimo<='Z'){
		enum direction random = rand()%4;
		switch (random) {
			case up: //SU
				if (row == 0) {continue;} // se sono nella righa zero non posso salire
				else {// Controllo se le caselle sono libere
					if(pa[row-1][col]=='.') { //vuol dire che è libera
						pa[row-1][col]=valprossimo++;
						row--;
                			} 
            			}
            			break;
          		case down://GIU
            			if (row==9) {continue;}
				else {
              				if(pa[row+1][col]=='.') {
                  				pa[row+1][col]=valprossimo++;
                  				row++;
                			}
				}
				break;
          		case right ://DX
            			if(col==9) {continue;}
            			else {
              				if(pa[row][col+1]=='.') {
                  				pa[row][col+1]=valprossimo++;
                  				col++;
                			}
				}
            			break;
          		case left ://SX
            			if(col==0) {continue;}
            			else {
              				if(pa[row][col-1]=='.') {
                  				pa[row][col-1]=valprossimo++;
                  				col--;
                			}
				}
            			break;
			default:
            			break;
		}
		if ((pa[row-1][col]!='.' || row==0) && (pa[row+1][col]!='.'|| row==9)
		&& (pa[row][col+1]!='.'|| col==9) && (pa[row][col-1]!='.'|| col==0)) {
			todo=stop;
		}

	}

	printf("\n");
	for (int r=0;r<R;r++) {
		for (int c=0;c<C;c++) {
			printf("|%c|",pa[r][c]);
		}
    		printf("\n");
	}
	return 0;
}
