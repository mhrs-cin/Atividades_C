#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    int Ponto_atual = 1, Ponto_previo = 1, NUM, Num_inicial, NUM_depois; char W, ante_W = 'a', W_depois;



    scanf("%d", &Num_inicial);

    scanf("%d %c", &NUM_depois, &W_depois);

    for(int N = 0; N<Num_inicial; N++){

        NUM = NUM_depois; W = W_depois;

        if(W == 'E' && Ponto_atual-NUM<1){
            printf("Informacao invalida");
            break;
        }
        if(W == 'E' && ante_W != 'D'){

            scanf("%d %c", &NUM_depois, &W_depois);
            
            Ponto_previo = Ponto_atual;
            Ponto_atual-=NUM;
            Ponto_previo+=1;

            for(int X = 1; X<Ponto_atual; X++){
                printf(" ");
            }
            for(int X = Ponto_atual; X<Ponto_previo; X++){
                if(ante_W=='B'){
                    if(X<Ponto_previo-1){printf(".");}else if(X==Ponto_previo-1){printf("X");}
                }else{
                    printf(".");
                }
            }
        }else if(W == 'D' && ante_W != 'E'){

            scanf("%d %c", &NUM_depois, &W_depois);

            Ponto_previo = Ponto_atual;
            Ponto_atual+=NUM+1;

            if(W_depois == 'E' && Ponto_atual-NUM_depois<1){
                printf("Informacao invalida");
                break;
            }
        

            for(int X = 1; X<Ponto_previo; X++){
                printf(" ");
            }
            for(int X = Ponto_previo; X<Ponto_atual; X++){
                if(ante_W == 'B'){
                    if(X==Ponto_previo){printf("X");}else if(X>=Ponto_previo){printf(".");}
                }else{
                    printf(".");
                }
            }
            Ponto_atual-=1;

        }else if(W == 'B'){

            scanf("%d %c", &NUM_depois, &W_depois);
            if(W_depois == 'E' && Ponto_atual-NUM_depois<1){
                printf("Informacao invalida");
                break;
            }

            if(ante_W == 'D' || ante_W == 'E'){printf("\n");}
            for(int X = 0; X<NUM; X++){
                for(int X = 1; X<Ponto_atual; X++){
                    printf(" ");
                }
                printf(".\n");
            }
        }

        ante_W = W;
    }

    if(ante_W == 'B'){
        for(int X = 0; X<1; X++){
            for(int X = 1; X<Ponto_atual; X++){
                printf(" ");
            }
            printf(".\n");
        }
    }

    return 0;

}