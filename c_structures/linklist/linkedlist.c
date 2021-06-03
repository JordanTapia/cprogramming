#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "linkedlist.h"

//remove Nth node from end of linked list
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int sz = 0;
    struct ListNode * res = head;
    while(res){
        sz++;
        res = res->next;
    }
    struct ListNode* temp = head;
    int node = 1;
    if(sz - n == 0){
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

//insert element at end of list
void insert(struct ListNode **head, int n){
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));/////////
    newNode->val = n;
    newNode->next = NULL;
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

//build list from int array
void buildList(struct ListNode **head, int * nums, int size){
    for(int i = 0; i < size; i++){
        insert(head, nums[i]);
    }
}

//function to print list 
void printList(struct ListNode * head){
    struct ListNode *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("null\n");
}

//merge 2 sorted lists into 1 sorted list
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


//add two lists of single digits
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* dig1 = l1;
    struct ListNode* dig2 = l2;
    struct ListNode* sum = NULL;
    int val = 0;
    int carry = 0;

    while(dig1 || dig2) {
        if(dig1 == NULL){
            val = dig2->val + carry; dig2 = dig2->next;
        } 
        else if(dig2 == NULL){
            val = dig1->val + carry; dig1 = dig1->next;
        }
        else {
            val = dig1->val + dig2->val + carry;
            dig1 = dig1->next; dig2 = dig2->next;
        }
        carry = 0;
        if(val/10 >= 1){
            carry = 1;
            val = val %10;
        }
        insert(&sum, val);
    }
    if(carry){
        insert(&sum, carry);
    }
    return sum;
}























