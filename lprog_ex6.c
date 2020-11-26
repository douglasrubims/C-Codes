#include <stdio.h>
#define TAM 100

int main() {
	char string[TAM];
	int i;
	printf("Digite uma frase: ");
	scanf("%99[^\n]s", string);
	puts(string);
	for(i = 0; string[i] != '\0'; i++) {
		if(string[i] == 65 || string[i] == 69 || string[i] == 73 || string[i] == 79 || string[i] == 85 || string[i] == 97 || string[i] == 101 || string[i] == 105 || string[i] == 111 || string[i] == 117) string[i] = '*';
		printf("%c", string[i]);
	}
	puts("");
}