#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "priority_queue.h"

int main()
{
    FILE *priority_queue = NULL;
    int i;
    P_Queue *pq = create_priority_queue();
    for(i=0; i < 100; i++){
        enqueue(pq, i, i+5);
    }
	priority_queue = fopen("PriorityQueueList.txt", "w+");
    print_priority_queue( pq, priority_queue);

    fclose(priority_queue);
    return 0;
}
