/*
3 Implementazione di code con liste concatenate
Realizzate un’implementazione alternativa per queue usando le liste concatenate. Potete usare una lista bidirezionale
oppure una lista semplice con in aggiunta un puntatore all’ultimo elemento della lista. In questo secondo caso, valutate
cosa tra front e rear è opportuno collocare all’inizio della lista, in modo da garantire che il costo in tempo di enqueue
e dequeue sia costante.
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node{
  Item key;
  struct node *next;

};
typedef struct node *Node;

struct queue{
  Node front;
  Node rear;
  int n_elementi;
};

// Interface for Queue
void new_queue(Queue *q)
{
  Queue new=malloc(sizeof(struct queue));

  if (new==NULL)
  {
    printf("Coda non allocata!");
    exit(EXIT_FAILURE);
  }

  new->front=NULL;
  new->rear=NULL;
  new->n_elementi=0;
  *q=new;
}

void distroy(Queue q )
{
  //todo distruggere coda e nodi

  if(is_empty_queue(q)!=0) //coda vuota
    {
      free(q);
      return;
   } else{

    for(Node tmp=q->front;tmp!=NULL;tmp=tmp->next)
    {
      printf("\ndistruzione %d" , q->front->key);
      q->front=q->front->next;
      free(q->front);
    }
  }
}

Node new_node(Item key)
{
  Node new=malloc(sizeof(struct node)); //allochiamo lo spazio necessario per il nuovo nodo

  if (new==NULL)
  {
    printf("Creazione nuovo nodo non andata a buon fine!");
    exit(EXIT_FAILURE);
  }
  new->key=key;
  new->next=NULL;
  return new;
}

// Put element on rear
void enqueue( Queue q, Item key )
{
  Node new=new_node(key);
  if(is_empty_queue(q)!=0) //coda vuota
  {
    q->front=new;
    q->rear=new;
  } else{
    //inserimento in coda
    //nodo che era ultimo viene inserito un valore nel next e
    //rear diventa il nuovo nodo creato
    q->rear->next=new;
    q->rear=new;
  }
  q->n_elementi++; //non so se mi serve questo dato
  /*debug*/
  printf("\nN.elem inseriti %d",q->n_elementi);
  printf("\tRear %d",q->rear->key);
  printf("\tFront %d\n",q->front->key);
}
// Remove and return element from front
Item dequeue( Queue q)
{
  Node tmp=q->front;

  Item valore;
  if (is_empty_queue(q)!=0)
  {
    printf("La coda è vuota");
    exit(EXIT_FAILURE);
  } else
  {
    valore=q->front->key;
    q->front=q->front->next;
    q->n_elementi--;
    if (q->front==NULL)
      q->rear=NULL;

    free(tmp); //libero il nodo che è stato preso
    return valore;
  }

}
// Return front element
Item frontValue( Queue q)
{
  return q->front->key;
}

// Check if queue is empty
int is_empty_queue( Queue q)
{

  if (q->front==NULL)
    return -1;
  else
    return 0;

}

// Print queue content
void print_queue( Queue q)
{
  if (is_empty_queue(q)!=0)
    printf("\nLa coda e' vuota");
  else
    {
      printf("\n**** Stampa Lista ****\n");
      for (Node stampa=q->front; stampa!=NULL; stampa=stampa->next)
        printf("|%d|",stampa->key);
    }
}






