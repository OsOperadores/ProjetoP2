#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
  int item;
  int priority;
  struct node *next;
}node;

typedef struct priority_queue {
  node *head;
}priority_queue;


//FUNCOES
void* create_priority_queue();
void enqueue(priority_queue *pq, int i, int p);
void* dequeue(priority_queue *pq);
//int maximum(priority_queue *pq);
void* is_empty(priority_queue *pq);
void print_priority_queue(priority_queue *pq);

int main() {
  int a,b=0,k;
  priority_queue *pq = (priority_queue*) malloc(sizeof(priority_queue));
  pq = create_priority_queue();
  while(1){
    printf("Qual é o item?\n");
    scanf("%d", &a);
    if(a==-1) break;
    enqueue(pq,a,b);
    b++;
  }
  print_priority_queue(pq);
  return 0;
}

// Colocar item na fila
void enqueue(priority_queue *pq, int i, int p)
{
  node *new_node = (node*) malloc(sizeof(node));
  new_node->item = i;
  new_node->priority = p;
    if ((is_empty(pq)) || (p > pq->head->priority)) {
      new_node->next = pq->head;
      pq->head = new_node;
  } else {
      node *current = pq->head;
    while ((current->next != NULL) &&
     (current->next->priority > p)) {
      current = current->next;
    }
      new_node->next = current->next;
      current->next = new_node;
  }
}

//retirar o ultimo da fila
void* dequeue(priority_queue *pq)
{
  if (is_empty(pq)) {
    printf("Priority Queue underflow");
    return NULL;
  } else {
    node *node = pq->head;
    pq->head = pq->head->next;
    node->next = NULL;
    return node;
  }
}

/*int maximum(priority_queue *pq)
{
  if (is_empty(pq)) {
      printf("Priority Queue underflow");
      return -1;
  } else {
      return pq->head->i;
  }
}*/
//criando somente uma fila nova
void* create_priority_queue()
{
  priority_queue *new_queue = (priority_queue*) malloc(sizeof(priority_queue));
  new_queue->head = NULL;
  return (priority_queue*) new_queue;
}

//Verificando se a fila está vazia
void* is_empty(priority_queue *pq){
  if (pq->head == NULL) return (int*) 1;
  else return (int*) 0;
}

// printando a fila do último item adicionado até o primeiro
void print_priority_queue(priority_queue *pq){
  if(!is_empty(pq)){
    printf("item: %d ", pq->head->item);
    printf("prioridade: %d ", pq->head->priority);
    printf("\n");
    pq->head = pq->head->next;
    print_priority_queue(pq);
  }
}
