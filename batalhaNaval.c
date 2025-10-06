#include <stdio.h>

/*
    DESAFIO BATALHA NAVAL NÍVEL MESTRE:
    [0 = Água | 3 = Navio | 5 = Impacto Habilidade]
    - Cria Tabuleiro Zerado
    - Imprime Tabuleiro no estágio atual
    - Insere Navios com tamanhos variados [0 à 5]
    - Os navios podem ficar em três posições diferentes [Vertical, Horizontal e Diagonal]
    - Testa se o navio está completamente dentro do tabuleiro
    - Testa sobreposição do navio
    - Usa 3 tipos de Habilidades com impactos diferentes
*/

#define LINHAS 10
#define COLUNAS 10

int imprimeMenu(){
    int n;
    printf("\n MENU DO JOGO BATALHA NAVAL\n");
    printf("\n1. Zera Tabuleiro");
    printf("\n2. Insere Navio Horizontal");
    printf("\n3. Insere Navio Vertical");
    printf("\n4. Insere Navio Diagonal");
    printf("\n5. Imprime Tabuleiro");
    printf("\n6. Habilidade Cone");
    printf("\n7. Habilidade Cruz");
    printf("\n8. Habilidade Octaedro");
    printf("\n9. Sair\n");
    scanf("%d", &n);
    return n;
}

void centroHabilidade(int *linha, int *coluna){
    //Passa Centro Habilidade por ponteiros
    int temp = 0;
    printf("Digite Qual LINHA da Habilidade: ");
    scanf("%d", &temp);
    *linha = temp;
    printf("Digite Qual COLUNA da Habilidade: ");
    scanf("%d", &temp);
    *coluna = temp;
}

void tamanhoEPosicao(int *tamanho, int *linha, int *coluna){
    //Passa Tamanho e Posição por Ponteiros
    int temp = 0;
    printf("\nQual o tamanho do Navio de 1 a 5? ");
    scanf("%d", &temp);
    *tamanho = temp;
    printf("Digite Qual LINHA ele deve estar: ");
    scanf("%d", &temp);
    *linha = temp;
    printf("Digite Qual COLUNA ele deve estar: ");
    scanf("%d", &temp);
    *coluna = temp;
}

int testaTabuleiro(int tamanho, int linha, int coluna){
    if ((tamanho + linha <= LINHAS) && (tamanho + coluna <= COLUNAS)){
        return 1;
    } else {
        return 0;
    }
}

int main (){
    char coluna[LINHAS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[LINHAS][COLUNAS];
    int menu, tamanhoNavio, linhaNavio, colunaNavio;
    int linhaHab, colunaHab;
    int limite; // Usada para testar limite tabuleiro [1] Dentro do limite [0] fora do limite

    do {
        menu = imprimeMenu();
        switch (menu){
        case 1:
            // CRIA TABULEIRO e ZERA VALORES
            for (int i = 0; i < LINHAS; i++){
                for (int j = 0; j < COLUNAS; j++){
                    tabuleiro[i][j] = 0;
                }
            }
            break;

        case 2:
            // Inserir HORIZONTAL
            tamanhoEPosicao(&tamanhoNavio, &linhaNavio, &colunaNavio);
            limite = testaTabuleiro(tamanhoNavio, linhaNavio, colunaNavio);

            for (int j = 0; j < tamanhoNavio; j++){
                if (limite && (tabuleiro[linhaNavio][colunaNavio+j] == 0)){
                    tabuleiro[linhaNavio][colunaNavio+j] = 3;
                } else {
                    printf("Limite do Tabuleiro Atingido ou Sobreposição de Navios\n");
                    for (j = j-1 ; j >= 0; j--){
                        tabuleiro[linhaNavio][colunaNavio+j] = 0;
                    }
                    break;
                }
            }
            break;

        case 3:
            // Inserir VERTICAL
            tamanhoEPosicao(&tamanhoNavio, &linhaNavio, &colunaNavio);
            limite = testaTabuleiro(tamanhoNavio, linhaNavio, colunaNavio);

            for (int i = 0; i < tamanhoNavio; i++){
                if (limite && (tabuleiro[linhaNavio][colunaNavio+i] == 0)){
                    tabuleiro[linhaNavio+i][colunaNavio] = 3;
                } else {
                    printf("Limite do Tabuleiro Atingido ou Sobreposição de Navios\n");
                    for (i = i-1; i >= 0; i--){
                        tabuleiro[linhaNavio+i][colunaNavio] = 0;
                    }
                    break;
                }
            }
            break;
        
        case 4:
            // Inserir DIAGONAL
            tamanhoEPosicao(&tamanhoNavio, &linhaNavio, &colunaNavio);
            limite = testaTabuleiro(tamanhoNavio, linhaNavio, colunaNavio);

            for (int i = 0; i < tamanhoNavio; i++){
                if (limite && (tabuleiro[linhaNavio+i][colunaNavio+i] == 0)){
                    tabuleiro[linhaNavio+i][colunaNavio+i] = 3;
                } else {
                    printf("Limite do Tabuleiro Atingido ou Sobreposição de Navios\n");
                    for (i = i-1; i >= 0; i--){
                        tabuleiro[linhaNavio+i][colunaNavio+i] = 0;
                    }
                    break;
                }
            }
            break;
        
        case 5:
            // IMPRIME TABULEIRO
            printf("    ");  // Espaço antes das letra, para ficar alinhado
            for (int k = 0; k < LINHAS; k++){
                printf("%c ", coluna[k]);
            }
            printf("\n");

            for (int i = 0; i < LINHAS; i++){
                printf("%d - ", i);
                for (int j = 0; j < COLUNAS; j++){
                    printf("%d ", tabuleiro[i][j]);
                }
                printf("\n");
            }
            break;

        case 6:
            // HABILIDADE CONE
            centroHabilidade(&linhaHab, &colunaHab);

            for (int i = 0; i < 3; i++){
                for (int j = -i; j <= i; j++){
                    tabuleiro[linhaHab+i][colunaHab+j] = 5;
                }
            }
            break;

        case 7:
            // HABILIDADE CRUZ
            centroHabilidade(&linhaHab, &colunaHab);

            for (int i = -1; i < 2; i++){
                if (i<0) {
                    tabuleiro[linhaHab+i][colunaHab] = 5;
                } else if (i==0) {
                    for (int j = -2; j <= 2; j++){
                        tabuleiro[linhaHab+i][colunaHab+j] = 5;
                    }
                } else {
                    tabuleiro[linhaHab+i][colunaHab] = 5;
                }
            }
            break;

        case 8:
            // HABILIDADE OCTAEDRO
            centroHabilidade(&linhaHab, &colunaHab);

            for (int i = -1; i < 2; i++){
                if (i<0) {
                    tabuleiro[linhaHab+i][colunaHab] = 5;
                } else if (i==0) {
                    for (int j = -1; j <= 1; j++){
                        tabuleiro[linhaHab+i][colunaHab+j] = 5;
                    }
                } else {
                    tabuleiro[linhaHab+i][colunaHab] = 5;
                }
            }
            break;

        case 9:
            printf("Saindo ...");
            break;
        }
    } while (menu != 9);

    return 0;
}