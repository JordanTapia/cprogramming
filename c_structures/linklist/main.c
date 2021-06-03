#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "linkedlist.h"

int main(){

    int nums[7] = { 9,9,9,9,9,9,9};
    struct ListNode * ptr = NULL;
    buildList(&ptr, nums, 7);
    printList(ptr);

    int nums2[4] = {9, 9, 9, 9};
    struct ListNode * ptr2 = NULL;
    buildList(&ptr2, nums2, 4);
    printList(ptr2);

    struct ListNode *ptr3 = NULL;
    ptr3 = addTwoNumbers(ptr, ptr2);
    printList(ptr3);

}