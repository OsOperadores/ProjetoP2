#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "priority_queue.h"
#include "QueueHeap.h"

int main()
{
    FILE *sort = NULL;
    FILE *priority_queuecusto = NULL;
    FILE *Heap_Queuecusto = NULL;
    int i,x,y = 1000;

    P_Queue *pq = create_priority_queue();
    HEAP *Q_Heap = create_heap();
    for(i=0; i < Max_Priority_Queue/2; i++){
        enqueue(pq, i, i);

    }
    for(i=1; i < MAX_HEAP_SIZE/2; i++){
        enqueue_heap(Q_Heap, i);
    }
    for(i=MAX_HEAP_SIZE/2; i > 0 ; i--){
        max_heapify(Q_Heap, i);
    
    }
    sort = fopen("Sort.txt", "w+");
    priority_queuecusto = fopen("PriorityQueuecusto.txt", "w+");
    Heap_Queuecusto = fopen("Heap_Queuecusto.txt", "w+");
    srand( (unsigned)time(NULL) );
    while(y--){
        x = rand()%(Max_Priority_Queue);
        pq->custo = 0;
        printf("\nNúmero sorteado = %d\n", x);
        enqueue(pq,x,x);
        printf("\nCusto para inserir na Priority Queue = %d\n", pq->custo);
        Q_Heap->custo = 0;
        enqueue_heap(Q_Heap,x);
        printf("\nCusto para inserir na Heap = %d\n", Q_Heap->custo);
        fprintf(sort, "%d,", x);
        fprintf(priority_queuecusto, "%d,", pq->custo);
        fprintf(Heap_Queuecusto, "%d,", Q_Heap->custo);
        dequeue_heap(Q_Heap);
        dequeue(pq);
    }
    fclose(sort);
    fclose(priority_queuecusto);
    fclose(Heap_Queuecusto);
    return 0;
}
