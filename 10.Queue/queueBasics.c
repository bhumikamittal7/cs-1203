//build queue - enqueue and dequeue

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *ptr)
{
    if (ptr->rear == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *ptr)
{
    if (ptr->front == ptr->rear)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Queue Overflow! Cannot enqueue %d to the queue, queue is full  ", val);
    }
    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = val;
    }
}

int dequeue(struct queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow! Cannot dequeue from the queue, queue is empty  ");
        return -1;
    }
    else
    {
        ptr->front++;
        int val = ptr->arr[ptr->front];
        return val;
    }
}

int queueFront(struct queue *ptr)
{
    return ptr->arr[ptr->front + 1];
}

int queueRear(struct queue *ptr)
{
    return ptr->arr[ptr->rear];
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 3;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 42);
    enqueue(q, 43);
    enqueue(q, 44);


    return 0;
}

