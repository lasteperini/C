/*
- Mariacristina Branca
- mariacristina.branca@studenti.unimi.it  e Mariacristina Branca#6416
- L07 - "2  3 Implementazione di code con array circolari"
- L07 - "3 Implementazione di code con liste"
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(void)
{
  Queue my_queue=NULL;

  //new_queue(&my_queue,5); richiamo funzione implementazione array
  new_queue(&my_queue);
  enqueue(my_queue,5);
  enqueue(my_queue,6);
  enqueue(my_queue,3);
  print_queue(my_queue);

  //operatore ternario (alfa > beta) ? alfa : beta;
  printf("\nLa mia coda c vuota?%s", ((is_empty_queue(my_queue)==0)?"NO":"SI"));
  printf("\nIl primo elemento della coda e' %d",frontValue(my_queue) );

  //dequeue
  printf("\nRimuovo elemento dalla coda %d",dequeue(my_queue) );
  printf("\nRimuovo elemento dalla coda %d",dequeue(my_queue) );
  //printf("\nRimuovo elemento dalla coda e' %d",dequeue(my_queue) );
  printf("\nLa mia coda e' vuota?%s\n", ((is_empty_queue(my_queue)==0)?"NO":"SI"));

  enqueue(my_queue,1);
  enqueue(my_queue,2);
  enqueue(my_queue,7);
  enqueue(my_queue,6);
  print_queue(my_queue);

  //dequeue
  printf("\nRimuovo elemento dalla coda %d",dequeue(my_queue) );
  printf("\nRimuovo elemento dalla coda %d",dequeue(my_queue) );
  printf("\nRimuovo elemento dalla coda %d",dequeue(my_queue) );
  printf("\nRimuovo elemento dalla coda %d",dequeue(my_queue) );
  printf("\nRimuovo elemento dalla coda %d",dequeue(my_queue) );
  print_queue(my_queue);

  enqueue(my_queue,33);

  printf("La mia coda e' vuota?%s\n", ((is_empty_queue(my_queue)==0)?"NO":"SI"));

  distroy(my_queue);

  return 0;
}

