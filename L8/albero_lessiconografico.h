#ifndef ALBEROLESSICONOGRAFICO_H
#define ALBEROLESSICONOGRAFICO_H

#define N 10
#define NULLitem NULL

typedef struct Item *Item;
typedef struct Bit_node *Bit_node;
typedef char *Key;

Bit_node bit_new(Item item);
Item create_item(Key key);
void bit_destroy(Bit_node p);

void bist_orderprint(Bit_node p);
void bist_invorderprint(Bit_node p);
void bist_printnode(Bit_node p);

Item bist_search( Bit_node p , Key k );
Item bist_search_it(Bit_node p, Key k);

int cmp(Key k1, Key k2);
Key key(Item item);
Item bist_search_it(Bit_node p, Key k);
int bist_searchparent(Bit_node r, Key k, Bit_node *parent, Bit_node *p);
void bist_insert(Bit_node *r, Item item);
Item bist_search2(Bit_node r, Key k);
int bist_delete(Bit_node *r, Key k);

#endif
