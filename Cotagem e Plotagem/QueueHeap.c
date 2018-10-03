#include "QueueHeap.h"


void swap(int *pa, int *pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int is_empty_heap(HEAP *pq)
{
  return (pq == NULL); // Return 1 if is empty or return 0 if isn't empty
}

HEAP* create_heap(){
    HEAP *new_pq = (HEAP*) malloc(sizeof(HEAP));
	new_pq->size = 0;
    new_pq->custo = 0;
    //new_pq->data[0] = INFINITY_NEGATIVO;
	return new_pq;
}

int get_parent_index(HEAP *heap, int i)
{
    return i/2;
}
int get_left_index(HEAP *heap, int i)
{
    return 2*i;
}
int get_right_index(HEAP *heap, int i)
{
    return 2*i + 1;
}
int item_of(HEAP *heap, int i)
{
    return heap->data[i];
}

void enqueue_heap(HEAP *heap, int item)
{
    if (heap->size >= MAX_HEAP_SIZE) {
        printf("Heap overflow");
    } else {
        heap->custo++;
        heap->data[++heap->size] = item;
        int key_index = heap->size;
        int parent_index = get_parent_index(heap, heap->size);
       
        while (parent_index >= 1 && heap->data[key_index] > heap->data[parent_index]) {
            heap->custo++;
            swap(&heap->data[key_index], &heap->data[parent_index]);
            key_index = parent_index;
            parent_index = get_parent_index(heap, key_index);
        }
    }
}

int dequeue_heap(HEAP *heap)
{
    if (is_empty_heap(heap)) {
    printf("Heap underflow");
        return -1;
    } else {
        int item = heap->data[1];
        heap->data[1] = heap->data[heap->size];
        heap->size--;
        max_heapify(heap, 1);
        return item;
    }
}

void max_heapify(HEAP *heap, int i)
{
    int largest;
    int left_index = get_left_index(heap, i);
    int right_index = get_right_index(heap, i);
    if (left_index <= heap->size && heap->data[left_index] > heap->data[i]) {
        largest = left_index;
    } else {
        largest = i;
    }
    if (right_index <= heap->size && heap->data[right_index] > heap->data[largest]) {
        largest = right_index;
    }
    if (heap->data[i] != heap->data[largest]) {
        swap(&heap->data[i], &heap->data[largest]);
        max_heapify(heap, largest);
    }
}

void heapsort(HEAP *heap)
{
    int i;
    
    for (i = heap->size; i >= 2; i--) {
        swap(&heap->data[1], &heap->data[i]);   
        heap->size--;
        max_heapify(heap, 1);
    }
}

void print_heap_queue(HEAP *pq, FILE* Heap, int inicial){ 
  if(inicial < MAX_HEAP_SIZE){
      fprintf(Heap, "Data: %d ", pq->data[inicial]);
      print_heap_queue(pq,Heap,get_left_index(pq,inicial));
      print_heap_queue(pq,Heap,get_right_index(pq,inicial));
  }
}

void print_terminal_array(HEAP *pq){
    int i;
    for (i = 1; i <= MAX_HEAP_SIZE; i++){
        printf("%d ", pq->data[i]);
    }
    printf("\n");
}