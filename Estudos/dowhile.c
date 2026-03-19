#include <stdio.h>

int main(void){

    int x = 1;

    while(x == 0){
        printf("While\n");
        x = 1;
    }

    do{
        printf("DO while\n");
        x = 1;
    } while(x == 0);


    return 0;
}