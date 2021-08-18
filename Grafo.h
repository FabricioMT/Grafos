#ifndef  GRAFO_H
#define  GRAFO_H

typedef struct cidade Cidade;
typedef struct noLista NoLista;
typedef struct estrada Estrada;

typedef struct estrada{
	int cid1, cid2;
}Estrada;

typedef struct cidade{
	int id;
	NoLista* lista;
}Cidade;

typedef struct noLista{
	NoLista* prox;
	Cidade* cidade;
}NoLista;


void linkEstrada(Cidade* cidade1, Cidade* cidade2);
void checarConexao(Cidade* cidade,Estrada estradaCritica, int* criticityCheck);

#endif /*GRAFO_H*/