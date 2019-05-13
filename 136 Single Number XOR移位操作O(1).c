#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int singleNumber(int* nums, int numsSize) {
    int k = nums[0];
    int i;
    for (i=1; i<numsSize; i++) {
        k = (k ^ nums[i]);
    }
    return k;
}

int main(){
    int nums[] = {5, 8, 5, 6, 8, 7, 6};
    int result = singleNumber(nums, 7);
    printf("%d\n", result);

    return 0;
}
