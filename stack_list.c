#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode 
{
    int data;
    struct stackNode* next;
}StackNode;

StackNode* createStackNode(int data)
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode)); //8byte
    node->data = data;
    node->next = NULL;
    return node;
}
// padinfg
int isEmpty(StackNode* root)
{
    return !root;
}

void push(StackNode** root, int data)
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    if(isEmpty(*root))
    {
        (*root) = newNode;
    }
    else
    {
        newNode->next = (*root);
        (*root) = newNode;
    }
    printf("%d pushed to stack", data);
    
}

int pop(StackNode** root)
{
    if(isEmpty(*root))
    {
        return -9999;
    }

    int popped;
    popped = (*root)->data;
    (*root) = (*root)->next;

    
    return popped;
}

int peek(StackNode** root)
{
    if(isEmpty(*root))
    return -9999;

    return (*root)->data;

}

int main()
{
    StackNode* root = NULL;


    return 0;
}