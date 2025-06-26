#include <stdio.h>
//Declaração da variável tabuleiro
// O tabuleiro é uma matriz 10x10, onde cada célula pode conter um valor
char * tabuleiro[10][10];

//Função para iniciar o tabuleiro com valores padrão
void inicializaTabuleiro(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = "0";
        }
    }
}

//Função para posicionar um navio no tabuleiro
void posicionaNavio(int linha, int coluna){
    if(linha >= 0 && linha <= 10 && coluna >= 0 && coluna <= 10){
        tabuleiro[linha][coluna] = "3";
    }else{
        printf("Posição fora do tabuleiro!\n");
    }
}
//Função para imprimir o tabuleiro
void imprimeTabuleiro(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%s ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


int main(){

    inicializaTabuleiro();
     printf("Tabuleiro:\n");

    // Posiciona navio1
        for(int i = 0; i < 3; i++){
            posicionaNavio(9, 2 + i);
        }
     
    // Posiciona navio2
     for(int i = 0; i < 3; i++){
         posicionaNavio(3 + i, 5);
     }

     //imprime o tabuleiro
    imprimeTabuleiro();

    return 0;
}