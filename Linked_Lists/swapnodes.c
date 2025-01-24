// Problem : Program to swapNodes pairwise in Linked List;

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *createNode(int value)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void swapnodes(struct ListNode* head){

    struct ListNode* curr = head;
    struct ListNode *prev = NULL;
    struct ListNode *Next = curr->next;

    head = head->next;

    while(curr!=NULL && curr->next != NULL){

        // responsible for swapping nodes curr and Next
        curr->next = Next->next;
        Next->next = curr;
        if(prev!=NULL){
            prev->next = Next;
        }

        // responsible for selecting next pair
        prev = curr;
        curr = curr->next;
        if(curr!=NULL){
            Next = curr->next;
        }
        
    }


    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }



}
int main()
{
    struct ListNode *LL;
    LL = createNode(1);
    LL->next = createNode(2);
    LL->next->next = createNode(3);
    LL->next->next->next = createNode(4);
    LL->next->next->next->next = createNode(5);
    swapnodes(LL);

    return 0;
}