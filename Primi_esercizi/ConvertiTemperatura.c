#include  <stdio.h>
#include <stdlib.h>

int  main( int argc, char* argv[]) {
	printf("Farenhait=%s\n",argv[1]);
	
	int far =  atoi(argv[1]);;
	
	int sub = far - 32;
	int div = sub/1.8;
	
	printf("Celsius=%d\n",div);
	return 0;
	
return  0;
}
