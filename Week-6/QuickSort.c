#include<stdio.h>

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

int Partition(int A[], int low, int high){
    int pivot = A[low], i = low, j = high+1;
    while(i<j){
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[low], &A[j]);
    return j;
}

void QuickSort(int A[], int low, int high){
    if(low<high){
        int s_point = Partition(A, low, high);
        QuickSort(A, low, s_point-1);
        QuickSort(A, s_point+1, high);
    }
}

void main(){
    int n;
    printf("Enter no of elements:");
    scanf("%d",&n);
    int A[n];
    printf("Enter %d elements:",n);
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    int low = 0, high = n-1;
    QuickSort(A,low,high);
    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
}
