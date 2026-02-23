#include <stdio.h>

// Function to solve Tower of Hanoi
void Hanoi(int n, char src, char aux, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", src, dest);
        return;
    }
    Hanoi(n - 1, src, dest, aux);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    Hanoi(n - 1, aux, src, dest);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Hanoi(n, 'A', 'B', 'C'); // A = source, B = auxiliary, C = destination

    return 0;
}
