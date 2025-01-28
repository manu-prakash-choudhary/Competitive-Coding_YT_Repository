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
                // printf("%d <-- Value inserted succsesfully\n", value);
                return;
            }
            temp = temp->left;
        }
        else if(value > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                // printf("%d <-- Value inserted succsesfully\n", value);
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

void inorder_traversal(struct node* curr){
    // base condition
    if(curr == NULL){
        return;
    }
    inorder_traversal(curr->left);
    printf("%d ",curr->data);
    inorder_traversal(curr->right);
}


void preorder_traversal(struct node* curr){
    if(curr == NULL){
        return;
    }

    printf("%d ", curr->data);
    preorder_traversal(curr->left);
    preorder_traversal(curr->right);
}

void postorder_traversal(struct node* curr){
    if(curr == NULL){
        return;
    }
    postorder_traversal(curr->left);
    postorder_traversal(curr->right);
    printf("%d ", curr->data);
}

int search(struct node* root, int key){
    if(root == NULL){
        return 0;
    }
    struct node *curr = root;
    while(curr!=NULL){
        if(curr->data == key){
            return 1;
        }
        else if(key > curr->data){
            curr = curr->right;
        }
        else if(key < curr->data){
            curr = curr->left;
        }
    }

    return 0;
}

void BFS(struct node* root){
    if(root == NULL){
        return;
    }
    
    struct node* que[100];
    int front = 0;
    int rear = 0;
    que[rear] = root;

    while(front<=rear){
        struct node *curr = que[front++];
        printf("%d ", curr->data);
        if(curr->left != NULL){
            que[++rear] = curr->left;
        }
        if(curr->right != NULL){
            que[++rear] = curr->right;
        }
    }

}


int main()
{
    int arr[7] = {60, 40, 55, 75, 80, 70, 35,};

    for (int i = 0; i < 7;i++){
        insert_value(arr[i]);
    }

    printf("Breadth_first_traversal of the given tree is: ");
    BFS(Root);
    printf("\n");

    // searching a particular value in our BST
    int key = 28;
    int res = search(Root, key);
    if (res == 1)
    {
        printf("Key %d Found in the BST\n", key);
    }
    else
    {
        printf("Key %d not Found in the BST\n", key);
    }



    //Inorder Traversal
    inorder_traversal(Root);
    printf("<--Inorder Traversal\n");

    preorder_traversal(Root);
    printf("<--preorder Traversal\n");

    postorder_traversal(Root);
    printf("<--postorder Traversal\n");
}