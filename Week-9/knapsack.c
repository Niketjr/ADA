#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

void main(){
    int n;
    printf("Enter number of weights: ");
    scanf("%d", &n);
    int w[n], c[n];
    printf("Enter weights: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);
    }
    printf("Enter coins in weights: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
    }
    int bag;
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &bag);
    int dp[n + 1][bag + 1];
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < bag + 1; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < bag + 1; j++){
            if(j - w[i - 1] >= 0){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + c[i - 1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i = 0; i < n + 1; i++){
        if(i == 0){
            printf("-\t-\t%d\t", i);
        }
        else{
            printf("%d\t%d\t%d\t", w[i-1], c[i-1], i);
        }
        for(int j = 0; j < bag + 1; j++){
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    printf("Maximum possible: %d", dp[n][bag]);
}
