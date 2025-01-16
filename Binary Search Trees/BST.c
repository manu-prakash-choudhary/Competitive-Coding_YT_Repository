#include <stdio.h>
#include <stdlib.h>

// Write a fucntion named insert_value to Insert give values into a Binary Search Tree.
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* Root=NULL;

struct node* createNode(int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert_value(int value){
    struct node* newNode = createNode(value);
    if(Root == NULL){
        Root = newNode;
        return;
    }
    struct node* temp = Root;
    while(1){
        if (value < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                printf("%d <-- Value inserted succsesfully\n", value);
                return;
            }
            temp = temp->left;
        }
        else if(value > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                printf("%d <-- Value inserted succsesfully\n", value);
                return;
            }
            temp = temp->right;
        }
        else{
            printf("Duplicate values are not allowed");
            return;
        }
    }
    


    
}




int main()
{
    int arr[7] = {60, 40, 55, 75, 80, 70, 35, };
    // create a node with the value passed by user -> insert that node into BST
    insert_value(60);
    insert_value(40);
    insert_value(55);
    insert_value(75);
    insert_value(80);
    insert_value(70);
    insert_value(35);
}