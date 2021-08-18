gcc -o Grafo Grafo.c
./Grafo [nome do arquivo.txt]
./Grafo EntradadeDados1.txt

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

Conecta Cidade1 com Cidade2 na lista. 

void checarConexao(Cidade* cidade,Estrada estradaCritica, int* criticityCheck);

Percorre a Lista recursivamente checando as conexões da Cidade1 com Cidade2 e Cidade2 com Cidade1.
