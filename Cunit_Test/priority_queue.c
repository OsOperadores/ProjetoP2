#include "priority_queue.h"

P_Queue* create_priority_queue(){
	P_Queue *new_pq = (P_Queue*) malloc(sizeof(P_Queue));
	new_pq->head = NULL;
	new_pq->size = 0;
	return new_pq;
}

void enqueue(P_Queue *pq, int i, int p)
{
	node *new_node = (node*) malloc(sizeof(node));	// Pointer type "node"
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
	pq->size++;
}

int dequeue(P_Queue *pq)
{
	if (is_empty(pq)) {
		printf("Priority Queue underflow");
		return 0;
	} else {
		int i = pq->head->item;
		node *temp = pq->head;
		pq->head = pq->head->next;
		temp->next = NULL;
		free(temp);
		return i;
	}
}

int maximum (P_Queue *pq)
{
	if (is_empty(pq)) {
		printf("Priority Queue underflow");
		return -1;
	} else {
		return pq->head->item;
	}
}

int is_empty(P_Queue *pq)
{
  return (pq->head == NULL); // Return 1 if is empty or return 0 if isn't empty
}

//Print the list at a new .txt type of file
void print_priority_queue(P_Queue *pq, FILE* priority_queue){ 
  if(!is_empty(pq)){
    fprintf(priority_queue, "Item: %d ", pq->head->item);
    fprintf(priority_queue, "Prioridade: %d ", pq->head->priority);
    fprintf(priority_queue, "\n");
    pq->head = pq->head->next;
    print_priority_queue(pq, priority_queue);
  }
}
