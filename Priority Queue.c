#include <stdio.h>

int pq[100];
int n = 0;

void insert(int x)
{
    int i = n-1;

    while(i >= 0 && pq[i] > x)
    {
        pq[i+1] = pq[i];
        i--;
    }

    pq[i+1] = x;
    n++;
}

void display()
{
    for(int i=0;i<n;i++)
        printf("%d ", pq[i]);
}

int main()
{
    insert(30);
    insert(10);
    insert(20);

    display();

    return 0;
}