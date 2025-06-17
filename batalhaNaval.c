#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

// Função para imprimir o tabuleiro com legenda
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nLegenda: 0 = água, 3 = navio, 5 = habilidade\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Aplica uma matriz de habilidade ao tabuleiro no ponto de origem
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origemLinha, int origemColuna) {
    int offset = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTab = origemLinha - offset + i;
            int colunaTab = origemColuna - offset + j;

            if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] != 3) {
                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

// Gera matriz de cone (↓) dinamicamente
void gerarCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= TAMANHO_HABILIDADE / 2 - i &&
                j <= TAMANHO_HABILIDADE / 2 + i &&
                i <= TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera matriz de cruz (+)
void gerarCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera matriz de octaedro (losango)
void gerarOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona dois navios (horizontal e vertical)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[2][4 + i] = 3; // horizontal
        tabuleiro[5 + i][1] = 3; // vertical
    }

    // Matrizes de habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Gera as áreas de efeito dinamicamente
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica habilidades ao tabuleiro com origens definidas
    aplicarHabilidade(tabuleiro, cone, 1, 5);       // Cone com origem em (1,5)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz com origem em (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 8);   // Octaedro com origem em (7,8)

    // Exibe o resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
