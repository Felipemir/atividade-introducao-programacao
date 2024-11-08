#include <stdio.h>

int main(){
    int i;

    printf("Escreva um numero inteiro qualquer :\n");
    scanf("%d", &i);

    for( i = i; i >= 0; i--){
        printf("%d\n", i);
    }
    
}