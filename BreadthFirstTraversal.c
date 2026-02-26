#define SIZE 100
#include<stdio.h>

struct Node* queue[SIZE];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == SIZE - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear)
        return NULL;
    return queue[front++];
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    enqueue(root);
    while (front <= rear) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(temp->left);
        if (temp->right)
            enqueue(temp->right);
    }
}