#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkChar(char MOVE){

    int VALUE = -1;

    if(MOVE == 'c'){
        VALUE = 0;
    }else if(MOVE == 'e'){
        VALUE = 1;
    }else if(MOVE == 'b'){
        VALUE = 2;
    }else if(MOVE == 'd'){
        VALUE = 3;
    }

    return VALUE;
}


int main(void){

    int Main_arr[4][4] = {0}, Current_pos[2] = {0}, Best_pos[2] = {0}; char MOVE;

    while(scanf("%c", &MOVE) != EOF && MOVE != '\n'){

        int VALUE = -1;
        VALUE = checkChar(MOVE);

        if(VALUE == 0 && (Current_pos[0]-1) >= 0){
            
            Main_arr[Current_pos[0]-1][Current_pos[1]]+=1;
            Current_pos[0]-=1;
            if(Main_arr[Current_pos[0]][Current_pos[1]]>Main_arr[Best_pos[0]][Best_pos[1]]){
                Best_pos[0] = Current_pos[0]; Best_pos[1] = Current_pos[1];
            }

        }else if(VALUE == 1 && (Current_pos[1]-1) >= 0){

            Main_arr[Current_pos[0]][Current_pos[1]-1]+=1;
            Current_pos[1]-=1;
            if(Main_arr[Current_pos[0]][Current_pos[1]]>Main_arr[Best_pos[0]][Best_pos[1]]){
                Best_pos[0] = Current_pos[0]; Best_pos[1] = Current_pos[1];
            }
            
        }else if(VALUE == 2 && (Current_pos[0]+1) <= 3){

            Main_arr[Current_pos[0]+1][Current_pos[1]]+=1;
            Current_pos[0]+=1;
            if(Main_arr[Current_pos[0]][Current_pos[1]]>Main_arr[Best_pos[0]][Best_pos[1]]){
                Best_pos[0] = Current_pos[0]; Best_pos[1] = Current_pos[1];
            }

        }else if(VALUE == 3 && (Current_pos[1]+1) <= 3){

            Main_arr[Current_pos[0]][Current_pos[1]+1]+=1;
            Current_pos[1]+=1;
            if(Main_arr[Current_pos[0]][Current_pos[1]]>Main_arr[Best_pos[0]][Best_pos[1]]){
                Best_pos[0] = Current_pos[0]; Best_pos[1] = Current_pos[1];
            }

        }
    }

    printf("Coordenada X:%d, Y:%d\n", Best_pos[1], Best_pos[0]);

    return 0;
}