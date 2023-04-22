#include <stdio.h>
#define MAX_SIZE 100

int getArrayLength(int arr[]){
    return sizeof(arr)/sizeof(*arr);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = getArrayLength(arr);
    printf("Array length: %d\n", n);
    return 0;
}
