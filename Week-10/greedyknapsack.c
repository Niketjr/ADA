#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
    double ratio;
};

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio=items[i].value/items[i].weight;
    }
    int W;
    struct Item temp;
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(items[i].ratio<items[j].ratio){
                temp=items[j];
                items[j]=items[i];
                items[i]=temp;
            }
        }
    }
    
    int currentWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            int remainingWeight = W - currentWeight;
            finalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }
    printf("Maximum value in knapsack = %.2f\n", finalValue);
    return 0;
}
