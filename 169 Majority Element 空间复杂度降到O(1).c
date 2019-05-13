#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 表示num[] 数组*/
int majorityElement(int* nums, int numsSize) {
    int cand = 0; /*表示数组中要入栈的元素值*/
    int count = 0; /*表示入栈和出栈*/

    int i;
    for (i=0; i<numsSize; i++) {
        if (count == 0){
            cand = nums[i];
            count++;
        }
        else if (cand == nums[i]) {
            count++;
        }
        else{
            count--;
        }
    }
    return cand;
}

int main(){
    int nums[] = {1,2,3,2,2,2,5,4,2}; /* 要占有1/2数组的长度以上*/
    int result = majorityElement(nums, 10);
    printf("result = %d\n", result);
    printf("%d\n", length());

    return 0;
}
