#include <stdio.h>

#define MAX_OBJECTS 100
int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int W, int weights[], int profits[]) {
    int i, w;
    int K[MAX_OBJECTS + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (weights[i-1] <= j)
                K[i][j] = max(profits[i - 1] + K[i - 1][j - weights[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i-1][j];
        }
    }

    for (i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            printf("%d\t",K[i][j]);
        }
        printf("\n");
    }

    int maxProfit = K[n][W];
    printf("Maximum profit: %d\n", maxProfit);

    printf("Objects selected in the knapsack:\n");
    int res = maxProfit;
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;
        else {
            printf("Object %d (weight = %d, profit = %d)\n", i, weights[i - 1], profits[i - 1]);
            res -= profits[i - 1];
            w -= weights[i - 1];
        }
    }
}

int main() {
    int n, W;
    int weights[MAX_OBJECTS], profits[MAX_OBJECTS];
    int i;
    printf("Enter number of objects (max %d): ", MAX_OBJECTS);
    scanf("%d", &n);
    printf("Enter the weights of the objects:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter the profits of the objects:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    knapsack(n, W, weights, profits);

    return 0;
}
