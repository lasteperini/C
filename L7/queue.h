/*
- Mariacristina Branca
- mariacristina.branca@studenti.unimi.it  e Mariacristina Branca#6416
- L07 - "2 Implementazione di code con array circolari"
*/

/*
  per nascondere le informazioni al client test_queue.c, dal momento che tutti i file che includono queue.h potranno usare il tipo Queue
  e i prototipi dichiarati in queue.h, ma non avendo informazioni complete non potranno accedere direttamente alla struttura dati.
  Nell’interfaccia queue.h, diamo una definizione incompleta del tipo Queue e definiamo un Item di tipo intero.
  incompleta -->verrà implenentato in queue_list.c o queue-circular.c
*/

#ifndef QUEUE_H
#define QUEUE_H


typedef struct queue *Queue;
typedef int Item;

// Interface for Queue
  //void new_queue(Queue *, int );
  void new_queue(Queue *);
  void distroy(Queue );

  // Put element on rear
  void enqueue( Queue, Item );

  // Remove and return element from front
  Item dequeue( Queue );

  // Return front element
  Item frontValue( Queue );

  // Check if queue is empty
  int is_empty_queue( Queue );

  // Print queue content
  void print_queue( Queue );


#endif
