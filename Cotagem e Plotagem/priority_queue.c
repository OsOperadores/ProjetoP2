#include "priority_queue.h"

// List
struct node {
	int item;
	int priority;
	node *next;	// Pointer type "node"
};

// Priority Queue
struct priority_queue {
	node *head;
};

void enqueue(priority_queue *pq, int i, int p)
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
}

node* dequeue(priority_queue *pq)
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

int maximum (priority_queue *pq)
{
	if (is_empty(pq)) {
		printf("Priority Queue underflow");
		return -1;
	} else {
		return pq->head->i;
	}
}

int is_empty(priority_queue *pq)
{

}

void print_priority_queue(priority_queue *pq);