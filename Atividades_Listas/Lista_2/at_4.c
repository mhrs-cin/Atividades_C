#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    int Q, NUM, Espaco_esq = 0, Ponto_atual = 1, Ponto_previo = 1; char W, ante_W = 'a';

    scanf("%d", &Q);
    for(int i = 1; i<=Q; i++){
        scanf("%d %c", &NUM, &W);

        if(W == 'E'){
            if(Ponto_atual-NUM<1){
                printf("\nInformacao invalida\n");
                break;
            }else if(Ponto_atual-NUM>=1){
                Ponto_previo = Ponto_atual;
                Ponto_atual-=NUM;
                if(ante_W == 'D' || ante_W == 'E'){printf("\n");}
                for(int x = 1; x<Ponto_atual; x++){
                    printf(" ");
                }
                for(int x = Ponto_atual; x<Ponto_previo+1; x++){
                    printf(".");
                }
            }
        }else if(W == 'D'){
            if(ante_W == 'D' || ante_W == 'E'){printf("\n");}
            Ponto_previo = Ponto_atual;
            Ponto_atual+= NUM;
            if(ante_W == 'B' || ante_W == 'E'){Ponto_atual+=1;}
            for(int x = 1; x<Ponto_previo; x++){
                printf(" ");
            }
            for(int x = Ponto_previo; x<Ponto_atual; x++){
                printf(".");
            }
            Ponto_atual-=1;
        }else if(W == 'B'){
            if(ante_W != 'D' && ante_W != 'E'){printf(".");}
            if(ante_W == 'B'){NUM-=1;}
            for(int x = 1; x<NUM; x++){
                if(ante_W == 'E' || ante_W == 'D' || ante_W == 'B'){printf("\n");}
                for(int x = 1; x<Ponto_atual; x++){
                    printf(" ");
                }
                printf(".");
            }
            printf("\n");
        }
        ante_W = W;
    }

    return 0;
}