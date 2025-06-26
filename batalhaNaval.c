#include <stdio.h>
//Declaração da variável tabuleiro
// O tabuleiro é uma matriz 10x10, onde cada célula pode conter um valor
#define LINHA 10
#define COLUNA 10

char tabuleiro[LINHA][COLUNA];

//Função para iniciar o tabuleiro com valores padrão
void inicializaTabuleiro(){
    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            tabuleiro[i][j] = '0';
        }
    }
}

//Função para posicionar um navio na horizontal
void NavioHorizontal(int linha, int coluna){
       //Deixa as coordenadas de 1 - 10, em vez de 0 - 9
    linha = linha - 1;
    coluna = coluna - 1;

    //Variável para verificar se o navio pode ser posicionado
    int podePosicionar = 1;
    // Verifica se tem espaço para o navio na horizontal
    for(int i = 0; i < 3; i++){
        if(linha >= LINHA || (coluna + i) >= COLUNA || tabuleiro[linha][coluna + i] != '0'){
            podePosicionar = 0;
            break;
        }
    }
    

    if(podePosicionar){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha][coluna + i] = '3';
        }
    } else {
        printf("Navio na horizontal está em colisão com outro navio ou fora do tabuleiro.\n");
    }
    
}


//Função para posicionar um navio na vertical
void NavioVertical(int linha, int coluna){
    //Deixa as coordenadas de 1 - 10, em vez de 0 - 9
    linha = linha - 1;
    coluna = coluna - 1;

    //Variável para verificar se o navio pode ser posicionado
    int podePosicionar = 1;
    // Verifica se tem espaço para o navio na vertical
    for(int i = 0; i < 3; i++){
        if((linha + i) >= LINHA || coluna >= COLUNA || tabuleiro[linha + i][coluna] != '0'){
            podePosicionar = 0;
            break;
        }
    }


    if(podePosicionar){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha + i][coluna] = '3';
        }
    } else {
        printf("Navio na vertical está em colisão com outro navio ou fora do tabuleiro.\n");
    }
}

//Função para posicionar um navio na diagonal
void NavioDiagonal(int linha, int coluna){
    //Deixa as coordenadas de 1 - 10, em vez de 0 - 9
    linha = linha - 1;
    coluna = coluna - 1;

    //Variável para verificar se o navio pode ser posicionado
    int podePosicionar = 1;
    // Verifica se tem espaço para o navio na diagonal
    for(int i = 0; i < 3; i++){
        if((linha + i) >= LINHA || (coluna + i) >= COLUNA || tabuleiro[linha + i][coluna + i] != '0'){
            podePosicionar = 0;
            break;
        }
    }
    

    if(podePosicionar){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha + i][coluna + i] = '3';
        }
    } else {
        printf("Navio na diagonal está em colisão com outro navio ou fora do tabuleiro.\n");
    }
    
}

//Função para imprimir o tabuleiro
void imprimeTabuleiro(){
    for(int i = 0; i < LINHA; i++){
        printf("%2d ", i + 1); // Imprime o número da linha
        for(int j = 0; j < COLUNA; j++){
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
// A B C D E F G H I J
void imprimeColunas(){
    char coordenadas[COLUNA] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    for(int i = 0; i< 1; i++){
        printf("   "); // Espaço para o número da linha
    for(int i = 0; i < COLUNA; i++){
        printf("%c ", coordenadas[i]); // Imprime as letras das colunas
    }
    }
    printf("\n");
}


int main(){

    printf("Tabuleiro:\n");

    

    // Inicializa o tabuleiro
    inicializaTabuleiro();
    
    // Posiciona navio1
    NavioHorizontal(1, 8);
    
    // Posiciona navio2
    NavioVertical(8, 1);


    // Posiciona navio3
    NavioDiagonal(5, 5);

    // Posiciona navio4
    NavioDiagonal(7, 3);

    // Imprime as colunas
    imprimeColunas();

    //imprime o tabuleiro
    imprimeTabuleiro();

    return 0;
}