#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TENTATIVAS 6

void escolher_palavra(char *palavra_secreta) {
    const char *palavras[] = {"programacao", "computador", "teclado", "monitor", "mouse"};
    int num_palavras = sizeof(palavras) / sizeof(palavras[0]);
    srand(time(NULL));
    strcpy(palavra_secreta, palavras[rand() % num_palavras]);
}

void inicializar_palavra_adivinhada(char *palavra_adivinhada, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        palavra_adivinhada[i] = '_';
    }
    palavra_adivinhada[tamanho] = '\0';
}

int letra_ja_adivinhada(char letra, char *letras_adivinhadas, int num_letras_adivinhadas) {
    for (int i = 0; i < num_letras_adivinhadas; i++) {
        if (letras_adivinhadas[i] == letra) {
            return 1;
        }
    }
    return 0;
}

void atualizar_palavra_adivinhada(char letra, char *palavra_secreta, char *palavra_adivinhada) {
    int tamanho = strlen(palavra_secreta);
    for (int i = 0; i < tamanho; i++) {
        if (palavra_secreta[i] == letra) {
            palavra_adivinhada[i] = letra;
        }
    }
}

void desenhar_boneco(int tentativas_restantes) {
    switch (tentativas_restantes) {
        case 6:
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 5:
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 4:
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |       |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 3:
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |      /|\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 2:
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |      /|\\\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 1:
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |      /|\\\n");
            printf(" |      /\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 0:
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |      /|\\\n");
            printf(" |      / \\\n");
            printf(" |\n");
            printf("_|_\n");
            break;
    }
}

int main() {
    char palavra_secreta[50];
    escolher_palavra(palavra_secreta);

    int tamanho_palavra = strlen(palavra_secreta);
    char palavra_adivinhada[50];
    inicializar_palavra_adivinhada(palavra_adivinhada, tamanho_palavra);

    char letras_adivinhadas[26];
    int num_letras_adivinhadas = 0;
    int tentativas_restantes = MAX_TENTATIVAS;

    while (tentativas_restantes > 0) {
        printf("Palavra: %s\n", palavra_adivinhada);
        printf("Tentativas restantes: %d\n", tentativas_restantes);
        desenhar_boneco(tentativas_restantes);
        printf("Digite uma letra: ");

        char letra;
        scanf(" %c", &letra);

        if (letra_ja_adivinhada(letra, letras_adivinhadas, num_letras_adivinhadas)) {
            printf("Você já adivinhou essa letra!\n");
            continue;
        }

        letras_adivinhadas[num_letras_adivinhadas++] = letra;

        if (strchr(palavra_secreta, letra)) {
            atualizar_palavra_adivinhada(letra, palavra_secreta, palavra_adivinhada);
            if (strcmp(palavra_secreta, palavra_adivinhada) == 0) {
                printf("Parabéns! Você adivinhou a palavra: %s\n", palavra_secreta);
                break;
            }
        } else {
            tentativas_restantes--;
        }
    }

    if (tentativas_restantes == 0) {
        desenhar_boneco(tentativas_restantes);
        printf("Você perdeu! A palavra era: %s\n", palavra_secreta);
    }

    return 0;
}