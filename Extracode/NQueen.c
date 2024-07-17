#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int place(int x[], int k) {
    for (int i = 1; i < k; i++) {
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k)) {
            return 0;
        }
    }
    return 1;
}

void nqueens(int n) {
    int x[MAX];
    int k = 1;
    x[k] = 0;

    while (k > 0) {
        x[k] = x[k] + 1;

        while (x[k] <= n && !place(x, k)) {
            x[k] = x[k] + 1;
        }

        if (x[k] <= n) {
            if (k == n) {
                for (int i = 1; i <= n; i++) {
                    printf("%d ", x[i]);
                }
                printf("\n");
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of queens. Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    printf("The solutions are:\n");
    nqueens(n);

    return 0;
}
