#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

double soma_recursiva(int n) {
	if(n <= 0) return 0;
	if(n % 2 == 0) return soma_recursiva(n - 1);
	return (1.0 / n) + soma_recursiva(n - 2);
}

int main() {
	printf("%.2f", soma_recursiva(6));
	return 0;
}