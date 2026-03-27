#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arrayCheck(int j, int m1, int n1, int m2, int n2, int i, int P_array[m1][n1], char Main_array[m2][n2]){
    int VALUE;

    if(j==0 && P_array[i][0]-1>=0 && P_array[i][1]-1>=0){ // if que checa a diagonal superior esquerda e a parte de cima do P atual
        VALUE = 0;
    }
    if(j==1 && P_array[i][0]-1>=0 && P_array[i][1]+1>=0){ // if que checa a diagonal superior direita e a parte de cima do P atual
        VALUE = 1;
    }
    if(j==2 && P_array[i][0]+1>=0 && P_array[i][1]-1>=0){ // if que checa a diagonal inferior esquerda e a parte de cima do P atual
        VALUE = 2;
    }
    if(j==3 && P_array[i][0]+1>=0 && P_array[i][1]+1>=0){ // if que checa a diagonal inferior direita e a parte de cima do P atual
        VALUE = 3;
    }

    return VALUE;
}


int main(void){

    int m, n;

    scanf("%d %d\n", &m, &n);

    char Main_array[m][n+1], tempchar; int P_array[m*n][2], P_amount = 0;

    for(int i = 0; i<m; i++){

        for(int j = 0; j<n; j++){

            scanf("%c", &tempchar);
            if(tempchar == 'P'){
                P_array[P_amount][0] = i; P_array[P_amount][1] = j;
                P_amount+=1;
            }
            Main_array[i][j] = tempchar;

        }
        scanf("%c", &tempchar);
    }

    for(int i = 0; i<P_amount; i++){

        for(int j = 0; j<4; j++){
            int VALUE = arrayCheck(j, m*n, 2, m, n+1, i, P_array, Main_array);

            if(VALUE == 0){ // if que checa a diagonal superior esquerda e a parte de cima do P atual
                if(Main_array[P_array[i][0]-1][P_array[i][1]-1] != 'P'){if(Main_array[P_array[i][0]-1][P_array[i][1]-1] == '-'){Main_array[P_array[i][0]-1][P_array[i][1]-1] = 'x';}}
                if(Main_array[P_array[i][0]][P_array[i][1]-1] != 'P'){Main_array[P_array[i][0]][P_array[i][1]-1] = '+';}
                if(Main_array[P_array[i][0]-1][P_array[i][1]] != 'P'){Main_array[P_array[i][0]-1][P_array[i][1]] = '+';}
            }
            if(VALUE == 1){ // if que checa a diagonal superior direita e a parte de cima do P atual
                if(Main_array[P_array[i][0]-1][P_array[i][1]+1] != 'P'){if(Main_array[P_array[i][0]-1][P_array[i][1]+1] == '-'){Main_array[P_array[i][0]-1][P_array[i][1]+1] = 'x';}}
                if(Main_array[P_array[i][0]][P_array[i][1]+1] != 'P'){Main_array[P_array[i][0]][P_array[i][1]+1] = '+';}
                if(Main_array[P_array[i][0]-1][P_array[i][1]] != 'P'){Main_array[P_array[i][0]-1][P_array[i][1]] = '+';}
            }
            if(VALUE == 2){ // if que checa a diagonal inferior esquerda e a parte de cima do P atual
                if(Main_array[P_array[i][0]+1][P_array[i][1]-1] != 'P'){if(Main_array[P_array[i][0]+1][P_array[i][1]-1] == '-'){Main_array[P_array[i][0]+1][P_array[i][1]-1] = 'x';}}
                if(Main_array[P_array[i][0]][P_array[i][1]-1] != 'P'){Main_array[P_array[i][0]][P_array[i][1]-1] = '+';}
                if(Main_array[P_array[i][0]+1][P_array[i][1]] != 'P'){Main_array[P_array[i][0]+1][P_array[i][1]] = '+';}
            }
            if(VALUE == 3){ // if que checa a diagonal inferior direita e a parte de cima do P atual
                if(Main_array[P_array[i][0]+1][P_array[i][1]+1] != 'P'){if(Main_array[P_array[i][0]+1][P_array[i][1]+1] == '-'){Main_array[P_array[i][0]+1][P_array[i][1]+1] = 'x';}}
                if(Main_array[P_array[i][0]][P_array[i][1]+1] != 'P'){Main_array[P_array[i][0]][P_array[i][1]+1] = '+';}
                if(Main_array[P_array[i][0]+1][P_array[i][1]] != 'P'){Main_array[P_array[i][0]+1][P_array[i][1]] = '+';}
            }
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("%c", Main_array[i][j]);
        }
        printf("\n");
    }

    return 0;
}