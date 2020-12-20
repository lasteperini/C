#ifndef ALBERO_H
#define ALBERO_H

typedef int Item;
typedef struct bit_node *Bit_node ;


Bit_node bit_new(Item item);
void bit_inorder(Bit_node p, int j);
void bit_printassummary(Bit_node p, int j);
void bit_postorder(Bit_node p, int j);
Bit_node bit_arr2tree(Item a[], int size, int j);
void bit_printnode(Bit_node p, int j);

#endif
