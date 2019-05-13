#include<stdio.h>

void quickSort(int arr[], int L, int R){
    int i = L;
    int j = R;
    int pivot = arr[(L + R) / 2];
    while(i <= j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;

        if(i <= j){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    //i、j错开之后，下一次的subset的L与j也已经错开，就在L到j之间找不到了。
    //说明已经排完一次了。
    if (L < j){
        quickSort(arr, L, j);
    }
    if(i < R){
        quickSort(arr, i, R);
    }
}

int main(){
        int arr[] = {2, 8, 9, 10, 4, 5, 6, 7};
    int L = 0;
    int R = 7;
    quickSort(arr, L, R);

    int i;
    for (i=0; i <= R; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
