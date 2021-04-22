#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef struct abb {
	unsigned int info;
	int indice_esq;
	int indice_dir;
} abb;

void criar_arv(vector<abb> &v1, int dado);
bool definir_dir(vector<abb> &v1, int indice_atual, int dado);
bool definir_esq(vector<abb> &v1, int indice_atual, int dado);
void em_ordem(vector<abb> &v1, unsigned int idx);
bool inserir(vector<abb> &v1, int dado);
void pre_ordem(vector<abb> &v1, unsigned int idx);
void pos_ordem(vector<abb> &v1, unsigned int idx);
void em_largura(vector<abb> &v1);

int main() {
	vector<abb> v1;
	unsigned int valores[] = {25, 35, 10, 30, 9, 18, 75};
	criar_arv(v1, valores[0]);
	for(int i = 1; i < 7; i++) inserir(v1, valores[i]);
	pre_ordem(v1,0);
	cout << endl;
	em_ordem(v1, 0);
	cout << endl;
	pos_ordem(v1,0);
	cout << endl;
	em_largura(v1);
	cout << endl;
	return 0;
}

void criar_arv(vector<abb> &v1, int dado) {
	abb b1 = {dado, -1, -1};
	v1.push_back(b1);
}

bool definir_dir(vector<abb> &v1, int indice_atual, int dado) {
	if(v1.size() == 0) return false;
	unsigned int idx_dir = v1.size();
	v1[indice_atual].indice_dir = idx_dir;
	abb b1 = {dado, -1, -1};
	v1.push_back(b1);
	return true;
}

bool definir_esq(vector<abb> &v1, int indice_atual, int dado) {
	if(v1.size() == 0) return false;
	unsigned int idx_esq = v1.size();
	v1[indice_atual].indice_esq = idx_esq;
	abb b1 = {dado, -1, -1};
	v1.push_back(b1);
	return true;
}

void em_ordem(vector<abb> &v1, unsigned int idx) {
	if(v1[idx].indice_esq != -1) em_ordem(v1, v1[idx].indice_esq);
	cout << v1[idx].info << " ";
	if(v1[idx].indice_dir != -1) em_ordem(v1, v1[idx].indice_dir);
}

bool inserir(vector<abb> &v1, int dado) {
	if(v1.size() == 0) return false;
	unsigned int idx_atual = 0;
	while(idx_atual < v1.size()) {
		if(dado <= v1[idx_atual].info) {
			if(v1[idx_atual].indice_esq == -1) {
				definir_esq(v1, idx_atual, dado);
				break;
			} else idx_atual = v1[idx_atual].indice_esq;
		} else {
			if(v1[idx_atual].indice_dir == -1) {
				definir_dir(v1, idx_atual, dado);
				break;
			} else idx_atual = v1[idx_atual].indice_dir;
		}
	}
	return true;
}

void pre_ordem(vector<abb> &v1, unsigned int idx) {
	cout << v1[idx].info << " ";
	if(v1[idx].indice_esq != -1) pre_ordem(v1, v1[idx].indice_esq );
	if(v1[idx].indice_dir != -1) pre_ordem(v1, v1[idx].indice_dir);
}

void pos_ordem(vector<abb> &v1, unsigned int idx) {
	if(v1[idx].indice_esq != -1) pos_ordem(v1, v1[idx].indice_esq );
	if(v1[idx].indice_dir != -1) pos_ordem(v1, v1[idx].indice_dir);
	cout << v1[idx].info << " ";
}

void em_largura(vector<abb> &v1) {
	queue<abb> fila;
	fila.push(v1[0]);
	while(!fila.empty()) {
		abb no = fila.front();
		fila.pop();
		if(no.indice_esq != -1) fila.push(v1[no.indice_esq]);
		if(no.indice_dir != -1) fila.push(v1[no.indice_dir]);
		cout << no.info << " ";
	}
}