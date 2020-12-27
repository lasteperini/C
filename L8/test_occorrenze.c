#include <stdio.h>
#include <string.h>
#include "albero_lessiconografico.h"


int main(void) {
	
	char word[32];
	
	Bit_node root = NULL;
	scanf("%s", word);
	while (strcmp("STOP", word) != 0) {
		scanf("%s", word);
		Item item = create_item(word);
		bist_insert(&root, item);
	}
	bist_orderprint(root);	
		
	return 0;
}
