#include <stdio.h>
#include<stdlib.h>
#include "albero.h"

int main(void) {

	Item a[] = {12, 27, 7, 42, -1, 8, 9, 73, 21, 17, -1, 42, 0, 9, -1};
	
	Bit_node root = bit_arr2tree(a, 16, 0);
		
	bit_preorder(root, 0);
	
	return 0;
}
