#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bsort(char **nums, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j<n; j++){
            int x = atoi(nums[i]);
            int y = atoi(nums[j]);
            if(x > y){
                char *temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

char* kthLargestNumber(char** nums, int numsSize, int k) {
    bsort(nums, numsSize);
    return nums[numsSize - k];
}
