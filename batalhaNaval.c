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

void posicionaCone(int centro){
    int altura = 2; // Altura do cone

   for(int i = 0; i < altura; i++){ //Incrementa a altura do cone do baixo para o alto
   
        int inicio = centro - i; // Início da linha do cone
        int fim = centro + i; // Fim da linha do cone
        if(inicio < 0) inicio = 0; // Garante que o início não seja menor que 0
        if(fim >= COLUNA) fim = COLUNA - 1; // Garante que o fim não seja maior que o tamanho do tabuleiro

        for(int j = inicio; j <= fim; j++){
            // a posição do cone inicio até o fim, é marcada com 5
            tabuleiro[centro + i][j] = '5'; // Marca a posição do cone
        }
    }

}

void posicionaCruz(int centro) {
    int tamanho = 3; // Tamanho da cruz (3 para cada lado do centro)
    for(int i = 0; i < tamanho; i++){
        int inicio = centro - i; // Início da linha da cruz
        int fim = centro + i; // Fim da linha da cruz
        if(inicio < 0) inicio = 0; // Garante que o início não seja menor que 0
        if(fim >= COLUNA) fim = COLUNA - 1; // Garante que o fim não seja maior que o tamanho do tabuleiro
        for(int j = inicio; j <= fim; j++){
            // a posição da cruz inicio até o fim, é marcada com 5
            tabuleiro[centro][j] = '5'; // Marca a linha horizontal da cruz
            tabuleiro[j][centro] = '5'; // Marca a linha vertical da cruz
        }
    }
}
void posicionaOctaedro(int centro) {
    int altura = 1; // "raio" do losango (do centro até o topo/base)
    
    for(int i = 1; i <= altura; i++) {
        int inicio = centro + i; // Início da linha do octaedro
        int fim = centro - i; // Fim da linha do octaedro
        if(inicio >= LINHA) inicio = LINHA - 1; // Garante que o início não seja maior que o tamanho do tabuleiro
        if(fim < 0) fim = 0; // Garante que o fim não seja menor que 0
        for(int j = fim; j <= inicio; j++){
            // a posição do octaedro inicio até o fim, é marcada com 5
            tabuleiro[j][centro] = '5'; // Marca a posição do octaedro
            if(i == altura) {
                // Marca a base do octaedro
                tabuleiro[centro][j] = '5'; // Marca a base do octaedro
            }
        }

        }
    }


int main(){

    printf("Tabuleiro:\n");

    
    // Inicializa o tabuleiro
    inicializaTabuleiro();
    
    // Posiciona navio1
    NavioHorizontal(1, 1); // Exemplo de posicionamento do navio horizontal na linha 1, coluna 1
    
    // Posiciona navio2
    NavioVertical(4, 2); // Exemplo de posicionamento do navio vertical na linha 4, coluna 2


    // Posiciona navio3
    NavioDiagonal(7, 3); // Exemplo de posicionamento do navio diagonal na linha 7, coluna 3

    // Posiciona navio4
    NavioDiagonal(8,6); // Exemplo de posicionamento do navio diagonal na linha 8, coluna 6

    // Habilidade em cone
    posicionaCone(4); // Exemplo de posicionamento do cone no centro do índice 4

    // Habilidade em cruz
    posicionaCruz(2); // Exemplo de posicionamento da cruz no centro do índice 2

    // Habilidade em octaedro
    posicionaOctaedro(7); // Exemplo de posicionamento do octaedro no centro do índice 7

    // Imprime as colunas
    imprimeColunas();

    //imprime o tabuleiro
    imprimeTabuleiro();

    return 0;
}