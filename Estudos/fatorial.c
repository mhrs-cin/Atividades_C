#include <stdio.h>
#include <math.h>

int main(void){

    long double Y = 0.0;

    long long int X = 16;
    long long int fatorial = 1;

    for(long long int i = 2 ; i<=X; i++){

        fatorial = fatorial * i;

    }

    printf("%lld\n", fatorial);

    return 0;
}