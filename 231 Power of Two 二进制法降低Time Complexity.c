#include<stdio.h>
#include<stdbool.h>

bool isPowerOfTwo(int n) {
/*    if( n == 0)
        return false;
    while(n % 2 == 0) {
        n = n / 2;
    }
    if(n == 1)
        return true;
    else
        return false;
*/
    if(n <= 0) //避免二进制负数
        return false;
    else if(n == 1)
        return true;
    else {
        if((n & n-1) == 0)
            return true;
        else
            return false;
    }
}

int main(){
    printf("%d\n", isPowerOfTwo(4));

    return 0;
}
