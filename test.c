#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}
Queue;

Queue *rear = NULL;
Queue *front = NULL;

void enQueue(int data)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    queue->data = data;
    queue->next = NULL;

    if(rear ==NULL && front == NULL)
    {
        front = queue;
        rear = queue;
        
    }

    rear->next = queue;
    rear = queue;
    printf("%d\n", data);
}

int deQueue(Queue* queue)
{
    int dequeued;
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if(front == NULL && rear == NULL)
    {
        printf("queue is Empty");
        exit(1);
    }
    newQueue = front;
    front = front->next;
    dequeued = newQueue->data;
    free(newQueue);
    return dequeued;
}

int main()
{
    Queue* queue = NULL;

    
    enQueue(12);
    enQueue(13);
    enQueue(5);
    enQueue(6);
    printf("%d dequeued fron queue\n\n", deQueue(queue));
    printf("%d dequeued fron queue\n\n", deQueue(queue));
    

}