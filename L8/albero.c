#include <stdio.h>
#include<stdlib.h>
#include "albero.h"

struct bit_node {
	Item item ;
	struct bit_node *l , *r ;
};



Bit_node bit_arr2tree(Item a[], int size, int j) {
	if ( j >= size || a[j] == -1) {
		return NULL;
	}
	Bit_node root;
	root = malloc ( sizeof ( struct bit_node ) );
	root -> item = a[j];
	root -> l = malloc ( sizeof ( struct bit_node ) );
	root -> r = malloc ( sizeof ( struct bit_node ) );
	root -> l = bit_arr2tree(a, size, (j+j+1));
	root -> r = bit_arr2tree(a, size, (j+j+2));
	return root;
	
}

void bit_inorder(Bit_node p, int j) {
	if (p) {
		if (p -> l || p -> r) 
			bit_inorder( p -> l, j+1  );
		bit_printnode( p, j  );
		if (p -> l || p -> r) 
			bit_inorder( p -> r, j+1  );
	} else {
		for (int i = 0; i < j; i++) 
			printf("  ");
		printf("+X\n");
	}
}


void bit_preorder(Bit_node p, int j)  {
	if ( p ) {
		bit_printnode(p, j );
		if (p -> l || p -> r) {
			bit_preorder(p -> l, j+1 );
			bit_preorder(p -> r, j+1  );
		}
	} else {
		for (int i = 0; i < j; i++) 
			printf("  ");
		printf("+X\n");
	}
}


void bit_postorder(Bit_node p, int j)  {
	if ( p ) {
		if (p -> l || p -> r) {
			bit_postorder(p -> l, j+1  );
			bit_postorder(p -> r, j+1 );
		}
		bit_printnode(p , j );
	} else {
		for (int i = 0; i < j; i++) 
			printf("  ");
		printf("+X\n");
	}
}

void bit_printnode(Bit_node p, int j)  {
	for (int i = 0; i < j; i++) 
		printf("  ");
	printf("+%d \n", p -> item);
}
