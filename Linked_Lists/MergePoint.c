// Program 8 - Write a program to find the merge point of two linked lists. The merge point is the node at which both linked lists merge and become common.

// Example
// Input
// List 1: 3 -> 6 -> 9
//                    \                    
//                     15 -> 20 -> NULL
//                    /
//         List 2:  10

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node* createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
struct node* mergePoint(struct node* LL1, struct node* LL2){

    int lenLL1 = 0;
    int lenLL2 = 0;

    struct node *temp = LL1;
    while (temp!=NULL){
        temp = temp->next;
        lenLL1++;
    }

    temp = LL2;
    while(temp!=NULL){
        temp = temp->next;
        lenLL2++;
    }

    if(lenLL1>lenLL2){
        int diff;
        diff = lenLL1 - lenLL2;
        while(diff>0){
            LL1 = LL1->next;
            diff--;
        }
    }
    else{
        int diff;
        diff = lenLL2 - lenLL1;
        while (diff > 0)
        {
            LL2 = LL2->next;
            diff--;
        }
    }


    while(LL1 != NULL && LL2!=NULL){
        if(LL1 == LL2){
            return LL1;
        }

        LL1 = LL1->next;
        LL2 = LL2->next;
    }

    return NULL;
}

int main(){
    struct node* LL1;
    LL1 = createNode(1);
    LL1->next = createNode(2);
    LL1->next->next = createNode(3);
    LL1->next->next->next = createNode(4);

    struct node *LL2;
    LL2 = createNode(5);
    LL2->next = createNode(6);

    struct node *common;
    common = createNode(8);
    common->next = createNode(9);
    common->next->next = createNode(11);

    LL1->next->next->next->next = common;
    LL2->next->next = common;

    struct node *ans;
    ans = mergePoint(LL1, LL2);
    printf("common node of ll1 and ll2 is %d", ans->data);

    return 0;
}