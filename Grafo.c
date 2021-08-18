#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(int argc, char *argv[]) {
	FILE *arq = fopen(argv[1], "r");
	int nMaxCidades, nMaxEstradas;
	fscanf(arq, "%d %d", &nMaxCidades, &nMaxEstradas);
	
	int cityID1, cityID2;
	int criticityCheck[nMaxCidades];
	int qtdEstradasCriticas = 0;
	Cidade cidades[nMaxCidades];
	Estrada estradas[nMaxEstradas];
	
	for (int i = 0; i < nMaxCidades; i++) {
		cidades[i].id = i+1;
		cidades[i].lista = NULL;
	}

	for (int i = 0; i < nMaxEstradas; i++) {
		fscanf(arq, "%d %d", &cityID1, &cityID2);
		estradas[i].cid1 = cityID1;
		estradas[i].cid2 = cityID2;
		linkEstrada(&cidades[cityID1 - 1], &cidades[cityID2 - 1]);
		linkEstrada(&cidades[cityID2 - 1], &cidades[cityID1 - 1]);
	}

	for (int i = 0; i < nMaxEstradas; i++) {
		for (int j = 0; j < nMaxCidades; j++) criticityCheck[j] = 0;
		checarConexao(&cidades[0],estradas[i], criticityCheck);
		for (int j = 0; j < nMaxCidades; j++) {
			if (criticityCheck[j] == 0) {
				qtdEstradasCriticas++;
				break;
			}
		}
	}

	printf("Estradas críticas:%d\n", qtdEstradasCriticas);

	return 0;
}

void linkEstrada(Cidade* cidade1, Cidade* cidade2) {
	NoLista* novoNo;
	if (cidade1->lista == NULL) {
		cidade1->lista = (NoLista*)malloc(sizeof(NoLista));
		novoNo = cidade1->lista;
	} else {
		NoLista* aux;
		for (aux = cidade1->lista; aux->prox != NULL; aux = aux->prox);
		aux->prox = (NoLista*)malloc(sizeof(NoLista));
		novoNo = aux->prox;
	}
	novoNo->cidade = cidade2;
	novoNo->prox = NULL;
}

void checarConexao(Cidade* cidade,Estrada estradaCritica, int* criticityCheck) {
	NoLista* aux;
	criticityCheck[cidade->id - 1] = 1;
	for (aux = cidade->lista; aux != NULL; aux = aux->prox) {
		if (!criticityCheck[aux->cidade->id - 1] 
			&& !(cidade->id == estradaCritica.cid1 && aux->cidade->id == estradaCritica.cid2) 
			&& !(cidade->id == estradaCritica.cid2 && aux->cidade->id == estradaCritica.cid1)) {
			checarConexao(aux->cidade,estradaCritica, criticityCheck);
		}
	}
}