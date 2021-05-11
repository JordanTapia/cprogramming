#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define INTMAX =  2147483647
#define INTMIN = -2147483648

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int sz = 0;
    struct ListNode * res = head;
    while(res){
        sz++;
        res = res->next;
    }
    struct ListNode* temp = head;
    int node = 1;
    if(sz - n == 0){ //remove head
        if(head->next == NULL){
            return NULL;
        } else {
            struct ListNode * newHead = head->next;
            return newHead;
        }
    }
    while(node < sz - n ){
        temp = temp->next;
        node++;
    }
   struct ListNode *temp2 = temp->next;
    temp->next = temp2->next;
    return head;
}


void insert(struct ListNode **head, int n){
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));/////////
    newNode->val = n;
    newNode->next = NULL;
    printf("%d inserted\n", newNode->val);/////////
    if(*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode *lastNode = *head;
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}


void buildList(struct ListNode **head, int * nums, int size){
    for(int i = 0; i < size; i++){
        insert(head, nums[i]);
    }
}


void printList(struct ListNode * head){
    struct ListNode *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("null\n");
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *new = NULL;
    while(l1 || l2){
        if(l1 == NULL){
            insert(&new, l2->val);
            l2 = l2->next;
        } else if (l2 == NULL){
            insert(&new, l1->val);
            l1 = l1->next;
        } else if( l1->val < l2->val){
            insert(&new, l1->val);
            l1 = l1->next;
        } else {
            insert(&new, l2->val);
            l2 = l2->next;
        }
    }
    return new;    
}


int main(){

    int nums[5] = { 1, 3, 10, 11, 13};
    struct ListNode * ptr = NULL;
    buildList(&ptr, nums, 5);
    printList(ptr);

    int nums2[3] = {2, 4, 9};
    struct ListNode * ptr2 = NULL;
    buildList(&ptr2, nums2, 3);
    printList(ptr2);
    

    struct ListNode *ptr3 = mergeTwoLists(ptr, ptr2);
    printList(ptr3);



}



