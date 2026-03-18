#include <stdio.h>

#define INFINITY 9999

void dij(int n, int v, int cost[10][10], int dist[10]) {
    int i, u, count, w, flag[10], min;

    // Initialize
    for (i = 1; i <= n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }

    count = 2;

    while (count <= n) {
        min = INFINITY;

        for (w = 1; w <= n; w++) {
            if (dist[w] < min && !flag[w]) {
                min = dist[w];
                u = w;   // FIX: was u=v (wrong)
            }
        }

        flag[u] = 1;
        count++;

        for (w = 1; w <= n; w++) {
            if ((dist[u] + cost[u][w] < dist[w]) && !flag[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int n, v, i, j;
    int cost[10][10], dist[10];

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Cost[%d][%d]: ", i, j);
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INFINITY;
            }
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    dij(n, v, cost, dist);

    printf("\nShortest paths from vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        if (i != v) {
            printf("To %d = %d\n", i, dist[i]);
        }
    }

    return 0;
}