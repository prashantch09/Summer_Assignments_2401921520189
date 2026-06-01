#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int j=0;
    int i=1;
    int k;
    while(i<numsSize){
        if(nums[i]!=nums[j]){
            nums[j+1]=nums[i];
            j++;
            i++;
        }
        else{
            i++;
        }
    }
    k=j+1;
    return k;
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, numsSize);

    printf("Number of unique elements: %d\n", k);

    printf("Modified array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}