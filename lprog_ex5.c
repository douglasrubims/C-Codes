#include <stdio.h>

int main() {
    int i;
    printf("Numeros de 1000 a 2000 que divididos por 11 dão resto 5:\n");
    for(i = 1000; i <= 2000; i++) if(i % 11 == 5) printf("%d ", i);
    return 0;
}