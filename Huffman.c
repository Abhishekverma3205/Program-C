#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char data, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void printCodes(struct Node* root, int code[], int top) {
    int i;
    if(root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }
    if(root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }
    if(!root->left && !root->right) {
        printf("%c: ", root->data);
        for(i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    struct Node *A = createNode('A', 5);
    struct Node *B = createNode('B', 9);
    struct Node *C = createNode('C', 12);
    struct Node *D = createNode('D', 13);
    struct Node *E = createNode('E', 16);
    struct Node *F = createNode('F', 45);

    struct Node *n1 = createNode('#', A->freq + B->freq);
    n1->left = A; n1->right = B;

    struct Node *n2 = createNode('#', C->freq + D->freq);
    n2->left = C; n2->right = D;

    struct Node *n3 = createNode('#', n1->freq + E->freq);
    n3->left = n1; n3->right = E;

    struct Node *n4 = createNode('#', n2->freq + n3->freq);
    n4->left = n2; n4->right = n3;

    struct Node *root = createNode('#', F->freq + n4->freq);
    root->left = F; root->right = n4;

    int code[10];
    printCodes(root, code, 0);

    return 0;
}