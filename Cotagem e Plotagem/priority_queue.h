#ifndef PRIORITY_QUEUE_H_ // Keep the Header and preclude cyclical inclusion
#define PRIORITY_QUEUE_H_

priority_queue* create_priority_queue();
void enqueue(priority_queue *pq, int i, int p);
node* dequeue(priority_queue *pq);
int maximum(priority_queue *pq);
int is_empty(priority_queue *pq);
void print_priority_queue(priority_queue *pq);


#endif /* PRIORITY_QUEUE_H_ */
