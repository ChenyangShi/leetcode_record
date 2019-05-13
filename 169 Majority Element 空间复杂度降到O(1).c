#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ��ʾnum[] ����*/
int majorityElement(int* nums, int numsSize) {
    int cand = 0; /*��ʾ������Ҫ��ջ��Ԫ��ֵ*/
    int count = 0; /*��ʾ��ջ�ͳ�ջ*/

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
    int nums[] = {1,2,3,2,2,2,5,4,2}; /* Ҫռ��1/2����ĳ�������*/
    int result = majorityElement(nums, 10);
    printf("result = %d\n", result);
    printf("%d\n", length());

    return 0;
}
