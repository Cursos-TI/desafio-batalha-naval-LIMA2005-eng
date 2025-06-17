#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para verificar se há sobreposição nas posições fornecidas
int verificarSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posicoes[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        if (tabuleiro[linha][coluna] == 3) {
            return 1; // sobreposição encontrada
        }
    }
    return 0; // sem sobreposição
}

// Função para posicionar um navio nas posições fornecidas
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posicoes[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        tabuleiro[linha][coluna] = 3;
    }
}

int main() {
    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // ==========================
    // Navio 1 - Horizontal
    // ==========================
    int linha1 = 2, coluna1 = 4;
    int navio1[TAMANHO_NAVIO][2];
    if (coluna1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio 1 fora dos limites.\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        navio1[i][0] = linha1;
        navio1[i][1] = coluna1 + i;
    }
    if (verificarSobreposicao(tabuleiro, navio1, TAMANHO_NAVIO)) {
        printf("Erro: sobreposição no navio 1.\n");
        return 1;
    }
    posicionarNavio(tabuleiro, navio1, TAMANHO_NAVIO);

    // ==========================
    // Navio 2 - Vertical
    // ==========================
    int linha2 = 5, coluna2 = 1;
    int navio2[TAMANHO_NAVIO][2];
    if (linha2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio 2 fora dos limites.\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        navio2[i][0] = linha2 + i;
        navio2[i][1] = coluna2;
    }
    if (verificarSobreposicao(tabuleiro, navio2, TAMANHO_NAVIO)) {
        printf("Erro: sobreposição no navio 2.\n");
        return 1;
    }
    posicionarNavio(tabuleiro, navio2, TAMANHO_NAVIO);

    // ==========================
    // Navio 3 - Diagonal principal (↘)
    // ==========================
    int linha3 = 0, coluna3 = 0;
    int navio3[TAMANHO_NAVIO][2];
    if (linha3 + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna3 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio 3 fora dos limites.\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        navio3[i][0] = linha3 + i;
        navio3[i][1] = coluna3 + i;
    }
    if (verificarSobreposicao(tabuleiro, navio3, TAMANHO_NAVIO)) {
        printf("Erro: sobreposição no navio 3.\n");
        return 1;
    }
    posicionarNavio(tabuleiro, navio3, TAMANHO_NAVIO);

    // ==========================
    // Navio 4 - Diagonal secundária (↙)
    // ==========================
    int linha4 = 0, coluna4 = 9;
    int navio4[TAMANHO_NAVIO][2];
    if (linha4 + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna4 - TAMANHO_NAVIO + 1 < 0) {
        printf("Erro: navio 4 fora dos limites.\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        navio4[i][0] = linha4 + i;
        navio4[i][1] = coluna4 - i;
    }
    if (verificarSobreposicao(tabuleiro, navio4, TAMANHO_NAVIO)) {
        printf("Erro: sobreposição no navio 4.\n");
        return 1;
    }
    posicionarNavio(tabuleiro, navio4, TAMANHO_NAVIO);

    // ==========================
    // Exibe o tabuleiro final
    // ==========================
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
