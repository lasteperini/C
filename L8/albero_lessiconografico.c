#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "albero_lessiconografico.h"


struct Bit_node {
	Item item;
	struct Bit_node *l, *r;
};


struct Item {
	Key word;
	int n;
};

Bit_node bit_new(Item item) {
	Bit_node node = malloc(sizeof(struct Bit_node));
	node -> item = item;
	node -> l = malloc(sizeof(struct Bit_node));
	node -> r = malloc(sizeof(struct Bit_node));
	return node;

}

Item create_item(Key key) {
	Item item = malloc(sizeof(struct Item));
	item -> word = key;
	item -> n = 1;
}

void bit_destroy(Bit_node p) {
	free(p -> l);
	free(p -> r);
	free(p);
}

void bist_orderprint(Bit_node p) {
	if (p) {
		bist_orderprint(p -> l);
		bist_printnode(p);
		bist_orderprint(p -> r);
	}
}

void bist_invorderprint(Bit_node p) {
	if (p) {
		bist_invorderprint(p -> r);
		bist_printnode(p);
		bist_invorderprint(p -> l);
	}
}


void bist_printnode(Bit_node p)  {
	printf("%s\n", key(p -> item) );
}


int cmp(Key k1, Key k2) {
	return strcmp(k1, k2);
}

Key key(Item item) {
	Key s = malloc(sizeof(Key));
	s = item -> word;
	return s;
}

Item bist_search( Bit_node p , Key k ) {
	if ( !p )
		return NULLitem ;
	int res = cmp ( k , key ( p -> item ) );
	printf ( " ho confrontato k %d con p -> item %d e ho trovto %d\n" , k , key (p -> item ), res );
	if ( res == 0 )
		return p -> item ;
	if ( res < 0 )
		return bist_search ( p ->l , k );
	return bist_search ( p ->r , k );
}


Item bist_search_it(Bit_node p, Key k) {
	int res;
	while (p && (res = cmp(k, key(p -> item))) != 0)
		p = res < 0 ? p -> l : p -> r;
		if (p == NULL)
			return NULLitem;
		else
			return p -> item;
}


int bist_searchparent(Bit_node r, Key k, Bit_node *parent, Bit_node *p) {
	int res;
	*parent = NULL;
	*p = r;
	if(!r) {
		printf("not r");
		return -1;
	}
	while (*p &&(res = cmp(k, key((*p) -> item))) != 0) {
		*parent = *p;
		*p = res < 0 ? (*p) -> l :(*p) -> r;
	}
	if (*p == NULL) {
		printf("*p == NULL");
		return -1;
	}
	return 0;
}


void bist_insert(Bit_node *r, Item item) {
	Bit_node parent, q = *r, new = bit_new(item);
	Key k = key(item);
	/*se l'albero e' vuoto: */
	if(q == NULL) {
		*r = new;
		return;
	}
	/*se la chiave c'e' gia', non inserisco niente: */
	if(bist_searchparent(*r, k, &parent, &q) == 0) {
		printf("c'e' gia' \n");
		return;
	}
	/*altrimenti inserisco il nuovo nodo come figlio di parent: */
	if(cmp(k, key(parent -> item)) < 0)
		parent -> l = new;
	else
		parent -> r = new;
}



Item bist_search2(Bit_node r, Key k) {
	Bit_node parent = NULL, p = NULL;
	if(bist_searchparent(r, k, &parent, &p) == 0)
		return p -> item;
	else
		return NULLitem;
}

int bist_delete(Bit_node *r, Key k) {
	Bit_node x, xp, s = NULL;
	
	if(bist_searchparent(*r, k, &xp, &x) == -1)
		/*non ci sono nodi con chiave k, non faccio niente! */
		return -1;
	
	/*cerco il nodo s che deve sostituire x */
	if(x -> l == NULL &&x -> r == NULL) /*x non ha figli */
		s = NULL;
	else 	if(x -> l == NULL || x -> r == NULL) /*x ha un solo figlio */
			s = x -> l != NULL ? x -> l : x -> r;
		else {
			/*x ha due figli;
			cerco s, il massimo del sottoalbero di sinistra di x */
			Bit_node sp = x;
			s = x -> l;
			while(s -> r) {
				sp = s;
				s = s -> r;
			}
			/*s non ha figlio destro:
			avra' come nuovo figlio destro il figlio destro di x */
			s -> r = x -> r;
			/*se s e' figlio destro di sp, allora sp non e' x */
			if(sp -> r == s) {
				sp -> r = s -> l;
				s -> l = x -> l;
			}
		}
	
	/*sostituisco x con s. Se x e' la radice, diventa la nuova radice */
	if(x == *r) // x e' la radice
		*r = s; // nuova radice
	else if(xp -> l == x) // x e' figlio sinistro
		xp -> l = s;
	else // x e' figlio destro
		xp -> r = s;
	
	bit_destroy(x);
	return 0;
}
