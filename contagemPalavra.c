#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    int contador = 0;

    printf("Digite palavras (digite 'sair' para encerrar):\n");

    while (1) {
        printf("Digite uma palavra: ");
        scanf("%s", palavra);

        if (strcmp(palavra, "sair") == 0) {
            break;
        }

        contador++;
    }

    printf("Número total de palavras digitadas: %d\n", contador);

    return 0;
}