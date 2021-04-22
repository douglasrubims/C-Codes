#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

stack<int> inverter_pilha(stack<int> p) {
	stack<int> p_aux;
	while(!p.empty()) {
		p_aux.push(p.top());
		p.pop();
	}
	return p_aux;
};

stack<int> concatenar_pilhas(stack<int> p1, stack<int> p2) {
	stack<int> p;
	p1 = inverter_pilha(p1);
	p2 = inverter_pilha(p2);
	while(!(p1.empty() && p2.empty())) {
		if(!p1.empty() && !p2.empty()) {
			if(p1.top() < p2.top()) {
				p.push(p1.top());
				p1.pop();
			} else {
				p.push(p2.top());
				p2.pop();
			}
		} else if(!p1.empty()) {
			p.push(p1.top());
			p1.pop();
		} else if(!p2.empty()) {
			p.push(p2.top());
			p2.pop();
		}
	}
	return p;
}

void imprimir_pilha(stack<int> p) {
	while(!p.empty()) {
		printf("%d ", p.top());
		p.pop();
	}
	printf("\n");
}

int main() {
	stack<int> p1, p2, p3;
	for(int i = 1; i <= 10; i++) {
		p1.push(i);
		p2.push(i * 2);
	}
	p3 = concatenar_pilhas(p1, p2);
	imprimir_pilha(p1);
	imprimir_pilha(p2);
	imprimir_pilha(p3);
	return 0;
}