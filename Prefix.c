#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int evaluatePrefix(char prefix[])
{
    int i;
    int len = strlen(prefix);

    for(i = len - 1; i >= 0; i--)
    {
        if(isdigit(prefix[i]))
        {
            push(prefix[i] - '0');
        }
        else
        {
            int op1 = pop();
            int op2 = pop();

            switch(prefix[i])
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': push(pow(op1, op2)); break;
            }
        }
    }

    return pop();
}

int main()
{
    char prefix[MAX];

    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);

    printf("Result = %d", result);

    return 0;
}