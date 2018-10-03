#include <stdio.h>
#include <stdlib.h>

#define Max_Priority_Queue 10000
typedef struct priority_queue P_Queue;
typedef struct node node;


// List
struct node {
	int item;
	int priority;
	struct node *next;	// Pointer type "node"
};

// Priority Queue
struct priority_queue {
    int size;
	int custo;
	node *head;
};

P_Queue* create_priority_queue();
P_Queue* enqueue(P_Queue *pq, int i, int p);
int dequeue(P_Queue *pq);
int maximum(P_Queue *pq);
int is_empty(P_Queue *pq);
void print_priority_queue(P_Queue *pq, FILE* priority_queue, int achei);

