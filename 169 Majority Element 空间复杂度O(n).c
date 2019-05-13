#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ��ʾnum[] ����*/
int majorityElement(int* nums, int numsSize) {
    int* stack = malloc(sizeof(int) * numsSize); /*stack����*/
    int top = -1;

    int i;
    for (i=0; i<numsSize; i++) {
        if(top == -1){  /*ջ��*/
            stack[++top] = nums[i]; /*��ջ*/
        }
        else if (stack[top] == nums[i]) { /*ջ��Ԫ�ص��ڼ�����ջ��Ԫ��*/
            stack[++top] = nums[i];
        }
        else {
            top--;
        }
    }
    return stack[0];
}

int main(){
    int nums[] = {1,2,1,1,2,3,1}; /* Ҫռ��1/2����ĳ�������*/
    int result = majorityElement(nums, 7);
    printf("result = %d\n", result);

    return 0;
}
