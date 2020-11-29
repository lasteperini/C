#include <stdio.h>
#include <stdlib.h>


int main() {
	printf("init...\n");
	create_stack();
	is_empty();
	push(3);
	push(5);
	top();
	print_stack();
	pop();
	print_stack();
	printf("end...\n");
	
	return 0;
}



