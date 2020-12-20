/*
- Mariacristina Branca
- mariacristina.branca@studenti.unimi.it  e Mariacristina Branca#6416
- L07 - "2 Implementazione di code con array circolari"
*/


#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

// implementazione delle funzioni della coda
/* FIFO - prima che entra è la prima che esce
  -> se faccio enqueue(5), enqueue(6),enqueue(1)la mia coda sarà |5|6|1|
  -> nella pila sarebbe stato |1|6|5|
  -> uso array circolari
*/
  struct queue{
    int front; //primo elemnto della coda
    int rear;  //ultimo elemnto della coda
    int n_elementi;
    int n_max;
    Item *array;
  };

void new_queue(Queue *q, int n)
{
  Queue new=malloc(sizeof(struct queue));

  if (new==NULL)
  {
    printf("Allocazione non andata a buon fine!!");
    exit(EXIT_FAILURE);
  }
  new->front=0;
  new->rear=-1;
  new->n_elementi=0;
  new->n_max=n;
  new->array=malloc(n*sizeof(int));

  *q=new;

  //return new;
}

void distroy(Queue q)
{
  free(q->array);
  free(q);
}
// Put element on rear  - accoda un elemento in fondo
void enqueue(Queue q, Item e )
  {
    //coda piena

    if (q->n_elementi==q->n_max)
      {
        printf("\nLa coda e' piena! Non posso inserire altro.\n");
        return;
        //exit(EXIT_FAILURE);
      }
    q->rear++;
    if (q->rear>(q->n_max)-1) //devo mettere l'indice rear=0
        q->rear=0;

    q->array[q->rear]=e;//inserisco il valore in coda
    q->n_elementi++; //incremento il numero degli elementi
    printf("N.elem inseriti %d",q->n_elementi);
    printf("\tRear %d in posizione %d",q->array[q->rear],q->rear);
    printf("\tFront %d in posizione %d\n",q->array[q->front],q->front);

  }

  // Remove and return element from front
Item dequeue( Queue q )
  {
    Item primo_elemento;

    primo_elemento= q->array[q->front];
    if(q->front==(q->n_max)-1)
      q->front=0;
    else
      q->front++;

    q->n_elementi--;//decremento il numero degli elementi
    return primo_elemento;

  }
 // Return front element
Item frontValue( Queue q)
  {
    //resituisco il primo elemento senza toglierlo
    return q->array[q->front];
  }

// Check if queue is empty
int is_empty_queue( Queue q)
{
  if (q->n_elementi==0)
    return -1;//vero
  else
    return 0; //falso
}

  // Print queue content
void print_queue(Queue q)
  {
    if(is_empty_queue)
      {
        printf("\nLista di %d valori circolare:\t",q->n_elementi);
        for (int i =0; i<=(q->n_elementi-1);i++)
          printf("|%d|", q->array[((q->front+i)%(q->n_max))]);

        printf("\nLista di %d valori in base a i:\t",q->n_elementi);
        for (int i =0; i<=(q->n_elementi-1);i++)
          printf("|%d|", q->array[i]);

      }
     printf("\n");
  }

