#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int missingNumber(int* nums, int numsSize) {
    bool* arr = malloc(sizeof(int) * (numsSize + 1));
    int i;
    for (i=0; i < numsSize+1; i++) {
        arr[i] = false;
    }
    for (i=0; i < numsSize+1; i++) {
        int id = nums[i];
        arr[id] = true;
    }
    for (i=0; i < numsSize+1; i++) {
        if(arr[i] == false){
            return i;
        }
    }

}

int main(){
    int nums[] = {0,2,3,4}; 
    int result = missingNumber(nums, 4);
    printf("%d\n", result);

    return 0;
}
