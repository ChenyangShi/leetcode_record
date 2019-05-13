#include<stdio.h>

//每次都选择一个数，与前面的数比较，移动位置插入前面已经排好的数中
//从第二个数开始比较到n

void insert(int arr[], int n){
    int key = arr[n];
    int i = n;
    while(arr[i-1] > key) {
        arr[i] = arr[i-1];
        i--;
        if(i == 0){
            break;
        }
    }
    arr[i] = key;
}

void insertSort(int arr[], int n){
    int i;
    for(i=1; i<n; i++){
        insert(arr, i);
    }
}

int main(){
    int arr[] = {6, 5, 1, 2, 3, 9, 8, 4, 7};
    int i;
    insertSort(arr, 9);
    for(i=0; i<9; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}
