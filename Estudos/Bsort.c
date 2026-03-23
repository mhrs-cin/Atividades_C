#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define arrayLength(x) (sizeof(x)/sizeof(x[0]))
#define stringLength(x) ((sizeof(x)/sizeof(x[0]))-1)

int main(void){

    char arr[6] = {'e', 'd', 'c', 'b', 'a'}, N = stringLength(arr);

    for(int i = 0; i< N - 1; i++){
        for(int j = 0; j< N - 1 - i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("%s\n", arr);

    return 0;
}