#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define arraySize(X) (sizeof(X)/sizeof(X[0]))
#define stringSize(X) ((sizeof(X)/sizeof(X[0]))-1)

int main(void){

    int Input_amount;

    scanf("%d", &Input_amount);

    for(int X = 0; X<Input_amount; X++){

        int Seq_amount = 0;
        scanf("%d", &Seq_amount);

        int VTOR_principal[Seq_amount], Seq_size = 1, Best_size = 0, Seq_position = 0, Best_position = 0;
        
        for (int Y = 0; Y < Seq_amount; Y++) {
            scanf("%d", &VTOR_principal[Y]);
        }

        for(int Y = 1; Y<Seq_amount; Y++){
            if(VTOR_principal[Y-1]>VTOR_principal[Y]){
                Seq_size++;
            }else{
                if(Seq_size>1 && Seq_size>Best_size){
                    Best_size = Seq_size;
                    Best_position = Seq_position;
                }
                Seq_size = 1;
                Seq_position = Y;
            }
        }

        if(Seq_size>1 && Seq_size>Best_size){
            Best_size = Seq_size;
            Best_position = Seq_position;
        }

        if(Best_size == 0){
            printf("0\n");
        }else{
            printf("%d\n", Best_size);
            for(int Y = 0; Y<Best_size; Y++){
                printf("%d ", VTOR_principal[Y+Best_position]);
            }
            printf("\n");
        }
    }

    return 0;
}