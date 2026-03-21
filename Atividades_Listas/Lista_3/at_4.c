#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    int Test_cases = 0, cont = 0;
    scanf("%d\n", &Test_cases);
    char Main_arr[(60*Test_cases)+Test_cases+1], Current_char = '.'; // Array principal, e Variavel para manter o char atual
    int Start_arr[Test_cases], End_arr[Test_cases], Start_bool = 1, i = 0, Bound_to_change = 1, continue_bool = 0; // variaveis de controle para saber o começo e fim de cada "Luz", tambem para saber se a posição atual é o começo de uma nova luz, e outras variaveis de controle dos loops

    if(Test_cases>0){
        while(scanf("%c", &Current_char) != EOF && continue_bool<Test_cases){ // Loop que vai até o fim dos inputs

            if(Current_char == ' ' || Current_char == '\n'){ // If statement que checa se o input foi 'O', 'X' ou um número

                End_arr[i] =  cont-1;

                int Flash_amount; // Quantidades de mudanças de luz mais a esquerda

                scanf("%d\n", &Flash_amount);

                for(int j = 0; j<Flash_amount; j++){

                    Bound_to_change = 1; // variavel que define se a luz atual deve mudar ou não, baseado se a luz anterior desligou ou não

                    for(int k = Start_arr[i]; k<End_arr[i]+1; k++){

                        if(Bound_to_change == 1){

                            if(Main_arr[k] == 'O'){

                                Main_arr[k] = 'X';
                        
                            }else if(Main_arr[k] == 'X'){
                                Main_arr[k] = 'O';
                                Bound_to_change = 0;
                                break;
                            }

                        }

                    }

                }


                for(int j = Start_arr[i]; j<End_arr[i]+1; j++){ // Loop que printa a luz atual

                    printf("%c", Main_arr[j]);

                }
                printf("\n");

                int Arr_size = (End_arr[i-1]-Start_arr[0])+1; // define o tamanho atual das luzes juntas
                
                if(i>0){ // If statements que atualizam os simbolos entre as "luzes"
                    if(Arr_size%2==0){
                        if(Main_arr[Start_arr[i]]==Main_arr[End_arr[i-1]]){
                            Main_arr[End_arr[i-1]+1] = '@';
                        }else if(Main_arr[Start_arr[i]]!=Main_arr[End_arr[i-1]]){
                            Main_arr[End_arr[i-1]+1] = '$';
                        }
                    }else if(Arr_size%2!=0){
                        if(Main_arr[Start_arr[i]]==Main_arr[End_arr[i-1]]){
                            Main_arr[End_arr[i-1]+1] = '#';
                        }else if(Main_arr[Start_arr[i]]!=Main_arr[End_arr[i-1]]){
                            Main_arr[End_arr[i-1]+1] = '%';
                        }
                    }
                }

                Start_bool = 1;
                i++;
                Main_arr[cont] = -1;
                continue_bool++;

            }else{

                if(Start_bool == 1){Start_arr[i] = cont; Start_bool = 0;}
                Main_arr[cont] = Current_char;

            }

            cont++;

        }

        cont = 0;
        while(Main_arr[cont] != -1){ // Print no conjunto inteiro, até o char -1 que defini como final
            printf("%c", Main_arr[cont]);
            cont++;
        }
        printf("\n");
    }

    return 0;
}