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

        int VTOR_principal[Seq_amount], Seq_size = 0, Best_size = 0, Seq_position = 0, Best_position = 0, Current_bool = 0;
        
        for(int Y = 0; Y<Seq_amount; Y++){

            int NUM;
            scanf("%d", &NUM);

            VTOR_principal[Y] = NUM;

            if(Y>0){
                if(VTOR_principal[Y-1]>VTOR_principal[Y]){
                    if(Current_bool == 0){
                        Seq_position = Y-1;
                    }
                    Current_bool = 1;
                    Seq_size++;
                    if(Y==Seq_amount-1){Best_size = Seq_size+1; Best_position = Seq_position;}
                }else{
                    if(Seq_size>Best_size){Best_size = Seq_size+1; Best_position = Seq_position;}
                    if(Current_bool == 1){
                        Current_bool = 0;
                        Seq_size = 0;
                    }
                }
            }
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