#include <stdio.h>
#include <math.h>

int main(){
    unsigned int N, A, B, SOMA = 0;

    scanf("%u", &N);
    scanf("%u %u", &A, &B);

    for(unsigned int C = 1; C<=10; C++){
        if(C%A!=0 && C%B!=0){
            SOMA+=C;
        }
    }

    printf("%u\n", SOMA);
    if(SOMA%2==0){
        printf("Lá ele!!!");
    }else{
        printf("Opa xupenio AULAS...");
    }

    return 0;
}