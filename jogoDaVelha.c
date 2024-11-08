#include <stdio.h>

char tabuleiro[3][3];
char jogadorAtual = 'X';

void inicializarTabuleiro() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirTabuleiro() {
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

int verificarVitoria() {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogadorAtual && tabuleiro[i][1] == jogadorAtual && tabuleiro[i][2] == jogadorAtual) {
            return 1;
        }
    }
    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == jogadorAtual && tabuleiro[1][i] == jogadorAtual && tabuleiro[2][i] == jogadorAtual) {
            return 1;
        }
    }
    // Verificar diagonais
    if (tabuleiro[0][0] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][2] == jogadorAtual) {
        return 1;
    }
    if (tabuleiro[0][2] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][0] == jogadorAtual) {
        return 1;
    }
    return 0;
}

int verificarEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void alternarJogador() {
    if (jogadorAtual == 'X') {
        jogadorAtual = 'O';
    } else {
        jogadorAtual = 'X';
    }
}

void jogar() {
    int linha, coluna;
    while (1) {
        imprimirTabuleiro();
        printf("Jogador %c, digite a linha e a coluna (0, 1 ou 2) para jogar: ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        if (verificarVitoria()) {
            imprimirTabuleiro();
            printf("Jogador %c venceu!\n", jogadorAtual);
            break;
        }

        if (verificarEmpate()) {
            imprimirTabuleiro();
            printf("O jogo empatou!\n");
            break;
        }

        alternarJogador();
    }
}

int main() {
    inicializarTabuleiro();
    jogar();
    return 0;
}