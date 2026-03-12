#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if((rear + 1) % SIZE == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = x;
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display()
{
    int i = front;

    if(front == -1)
    {
        printf("Queue empty\n");
        return;
    }

    while(i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }

    printf("%d", queue[rear]);
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