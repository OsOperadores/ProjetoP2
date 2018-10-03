#include <stdio.h>
#include <stdlib.h>


#define MAX_HEAP_SIZE 10000  //Size of Heap
#define INFINITY_NEGATIVO -100

struct heap {
    int size;
    int custo;
    int data [MAX_HEAP_SIZE];
};

typedef struct heap HEAP;

HEAP* create_heap();
void enqueue_heap(HEAP *heap, int item);
int dequeue_heap(HEAP *heap);
int get_parent_index(HEAP *heap, int i);
int get_left_index(HEAP *heap, int i);
int get_right_index(HEAP *heap, int i);
void max_heapify(HEAP *heap, int i);
int item_of(HEAP *heap, int i);
void heapsort(HEAP *heap);
void swap(int *pa, int *pb);
int is_empty_heap(HEAP *pq);
void print_heap_queue(HEAP *pq, FILE* Heap, int inicial);
void print_terminal_array(HEAP *pq);
