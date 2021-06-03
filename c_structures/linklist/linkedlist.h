#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define INTMAX =  2147483647
#define INTMIN = -2147483648

 struct ListNode {
     int val;
     struct ListNode *next;
 };

//remove Nth node from end of linked list
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

//insert element at end of list
void insert(struct ListNode **head, int n);

//build list from int array
void buildList(struct ListNode **head, int * nums, int size);

//function to print list 
void printList(struct ListNode * head);

//merge 2 sorted lists into 1 sorted list
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

//add two numbers digit by digit
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);



#endif