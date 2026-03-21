#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define properLetter(x) ((x>=97 && x<=122)||(x>=65 && x<=90)) // Define que facilita a leitura do código

int main(void){

    char w = 111, x = 108, y = 'A', z = 'Z', WORD;
    char Array_words[100], Array_start[100]; 
    int cont = 0, wordcont = 0, previous_wordcont = -1, New_word = 1, Ana_gram = 0, Word_end, Anagram_quant = 0, Array_wordsize[100];

    while(scanf("%c", &WORD) != EOF && WORD != '\n'){ // Loop que pega os inputs

        if(previous_wordcont != wordcont){
            Array_wordsize[wordcont] = 0;
            previous_wordcont = wordcont;
        }
        if(properLetter(WORD)){

            if(New_word == 1){Array_start[wordcont] = cont; New_word = 0;}
            Array_words[cont] = WORD;

            if(WORD>=65 && WORD<=90){
                WORD = WORD + 32;
            }

            Array_wordsize[wordcont] = Array_wordsize[wordcont]+WORD; // Array de ints que somam os valores numericos dos chars para comparação de anagrama. (Pode gerar problemas quando as somas são identicas, ex: "az ol", mas isso apenas ocorre em palavras extremamente pequenas)


        }else{
            Array_words[cont] = WORD;
            New_word = 1;
            if((cont>0) && (properLetter(Array_words[cont-1]))){
                wordcont++;
                Word_end = cont;
            }
        }

        cont++;
    }

    Array_words[cont] = WORD;
    New_word = 1;
    if((cont>0) && (properLetter(Array_words[cont-1]))){ // If statement que indica se teve ou não uma nova palavra e o final desta palavra
        wordcont++;
        Word_end = cont;
    }

    for(int i = 0; i<wordcont; i++){ // Bubble sort que analiza e compara as palavras para identificar anagramas, e também da printf nas palavras corretas.
        for(int j = i+1; j<wordcont; j++){
            if(Array_wordsize[i]==Array_wordsize[j]){

                if(Ana_gram == 0){
                    Ana_gram = 1;
                    printf("Pares de anagramas encontrados:\n");
                }

                cont = Array_start[i];
                while(properLetter(Array_words[cont])){
                    printf("%c", Array_words[cont]);
                    cont++;
                }
                printf(" e ");
                cont = Array_start[j];
                while(properLetter(Array_words[cont]) && cont<Word_end){
                    printf("%c", Array_words[cont]);
                    cont++;
                }
                printf("\n");
                Anagram_quant++;

            }
        }
    }

    if(Ana_gram == 0){
        printf("Nao existem anagramas na frase.");
    }else if (Ana_gram == 1)
    {
        printf("\nTotal de pares: %d\n", Anagram_quant);
    }
    

    return 0;
}