#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 表示num[] 数组*/
int majorityElement(int* nums, int numsSize) {
    int* stack = malloc(sizeof(int) * numsSize); /*stack数组*/
    int top = -1;

    int i;
    for (i=0; i<numsSize; i++) {
        if(top == -1){  /*栈空*/
            stack[++top] = nums[i]; /*入栈*/
        }
        else if (stack[top] == nums[i]) { /*栈顶元素等于即将入栈的元素*/
            stack[++top] = nums[i];
        }
        else {
            top--;
        }
    }
    return stack[0];
}

int main(){
    int nums[] = {1,2,1,1,2,3,1}; /* 要占有1/2数组的长度以上*/
    int result = majorityElement(nums, 7);
    printf("result = %d\n", result);

    return 0;
}
