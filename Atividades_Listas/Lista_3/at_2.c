#include <stdio.h>
#include <stdlib.h>

int main(void){

    char Start_time[] = "07:03"; // tempo inicial
    int days = 0; // vari?vel desnecess?ria para contar dias
    int Current_client = 1, Client_amount = 0, MULT = 0, Greedy_clients = 0, Bought_cans = 0;
    
    scanf("%d %d %d\n", &Client_amount, &MULT, &Greedy_clients);

    char Greedy_array[(Greedy_clients*5)+1]; int Array_greedy[Greedy_clients];
    
    for(int i = 0; i<Greedy_clients; i++){
        for(int j = 0+(i*5); j<6+(i*5); j++){
            char tempchar;
            int tempint;
            if(j<5+(i*5)){scanf("%c", &tempchar); Greedy_array[j] = tempchar;}else{scanf(" %d\n", &tempint); Array_greedy[i] = tempint;}
        }
    }
    
    while(Current_client<=Client_amount){

        int Equal_num = -1;

        for(int i = 0; i<Greedy_clients; i++){
            int Is_equal = 1;
            int cont = 0;

            for(int j = 0+(i*5); j<5+(i*5); j++){
                if(Greedy_array[j] != Start_time[cont]){
                    Is_equal = 0;
                }
                cont++;
            }
            if(Is_equal==1){
                Equal_num = i;
            }
        }
        
        if(Equal_num>=0){
            Bought_cans+=Array_greedy[Equal_num];
        }else{
            if(MULT>0 && Current_client%MULT==0){
                Bought_cans+=1;
            }
        }

        if(Bought_cans>=50){

            if(Equal_num>=0){
                printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %c%c:%c%c. Que comprou %d latas.", Current_client, Start_time[0],Start_time[1],Start_time[3],Start_time[4], Array_greedy[Equal_num]);
            }else{
                printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %c%c:%c%c. Que comprou 1 lata.", Current_client, Start_time[0],Start_time[1],Start_time[3],Start_time[4]);
            }

            break;
        }

        Start_time[4] = Start_time[4]+3;

        while(Start_time[4]>'9' || Start_time[4]<'0'){ //sequ?ncia de while loops que corrigem o hor?rio;
            Start_time[4] = Start_time[4]-10;
            Start_time[3] = Start_time[3]+1;
        }
        while(Start_time[3]>'5' || Start_time[3]<'0'){
            Start_time[3] = Start_time[3]-6;
            Start_time[1] = Start_time[1]+1;
        }
        while(Start_time[0]>'2' || (Start_time[0]>='2' && Start_time[1]>='4') || Start_time[0]<'0' || Start_time[1]>'9' || Start_time[1]<'0'){
            if(Start_time[0]=='2' && Start_time[1]=='4'){
                Start_time[0] = '0';
                Start_time[1] = '0';
                days++;
            }
            while((Start_time[0]>='2' && Start_time[1]>=4) || (Start_time[0]>='2' && Start_time[1]<'0')){
                Start_time[1] = Start_time[1]-5;
                Start_time[0] = Start_time[0]-2;
                days++;
            }
            while(Start_time[1]>'9' || Start_time[1]<'0'){
                Start_time[1] = Start_time[1]-10;
                Start_time[0] = Start_time[0]+1;
            }
            while(Start_time[0]>'2' || Start_time[0]<'0'){
                Start_time[0] = Start_time[0]-3;
                Start_time[1] = Start_time[1]+6;
                days++;
            }
        }

        Current_client++;
    }

    if(Bought_cans==49){
        printf("Ainda nao foram vendidas latas suficientes. Falta %d lata.", 50-Bought_cans);
    }else if(Bought_cans<50){
        printf("Ainda nao foram vendidas latas suficientes. Faltam %d latas.", 50-Bought_cans);
    }

    return 0;
}