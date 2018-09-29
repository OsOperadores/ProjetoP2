#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "priority_queue.h"

P_Queue * pq;

int initial(){
    pq = create_priority_queue();
    if(pq == NULL) return -1;
    else return 0;
}

int clean_initial(){
    while(!is_empty(pq)){
        dequeue(pq);
    }
    free(pq);
    return 0;
}

void test_enqueue_dequeue(){
    pq = enqueue(pq,9,30);
    pq = enqueue(pq, 70,20);
    pq = enqueue(pq,222,312);
    pq = enqueue(pq, 22,33);
    CU_ASSERT_EQUAL(dequeue(pq),22);
    CU_ASSERT_EQUAL(dequeue(pq),222);
    CU_ASSERT_EQUAL(dequeue(pq),70);
    CU_ASSERT_EQUAL(dequeue(pq),9);
}

void test_empty(){
    CU_ASSERT_EQUAL(is_empty(pq),1);
    CU_ASSERT_EQUAL(pq->size,0);
}

int main()
{
    CU_pSuite pSuite = NULL;

   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   pSuite = CU_add_suite("initial", initial, clean_initial);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "test test_enqueue_dequeue", testEnqueue_Dequeue)) ||
       (NULL == CU_add_test(pSuite, "test test_empty", testEmpty)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
    return 0;
}
