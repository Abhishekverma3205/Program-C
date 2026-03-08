#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    if(front == -1)
        printf("Queue is empty\n");
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d ", queue[i]);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("\n");
    dequeue();

    display();

    return 0;
}