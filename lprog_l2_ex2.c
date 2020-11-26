#include <stdio.h>

int main() {
    int x, y, i, resultado = 0;
    printf("Digite o valor de X e Y para calcular X^Y: ");
    scanf("%d %d", &x, &y);
    resultado = x;
    for(i = 0; i < y - 1; i++) resultado *= x;
    printf("X^Y = %d", resultado);
    return 0;
}