#include <stdio.h>
#include <math.h>

void calcularAreaCirculo() {
    float raio, area;
    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);
    area = M_PI * raio * raio;
    printf("A área do círculo é: %.2f\n", area);
}

void somarDoisNumeros() {
    float num1, num2, soma;
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    soma = num1 + num2;
    printf("A soma dos dois números é: %.2f\n", soma);
}

int main() {
    int opcao;

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Calcular a área de um círculo\n");
        printf("2. Somar dois números\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                calcularAreaCirculo();
                break;
            case 2:
                somarDoisNumeros();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}