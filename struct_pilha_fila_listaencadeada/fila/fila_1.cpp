/*
	1) USANDO AS FUNCOES PRIMITIAVS PARA MANIPULACAO DE FILA, 
	ESCREVER UMA FUNCAO PARA MOSTRAR O CONTEUDO DE UMA FILA
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define tamanho 100

struct fila {
	int item[tamanho];
	int inicio, fim;
};

void inicializa(struct fila *f) {
	
	f->inicio = 0;
	f->fim = -1;
}

int vazia(struct fila *f) {
	
	if (f->fim < f->inicio)
		return 1;
	else
		return 0;	
}

int cheia(struct fila *f) {
	
	if(f->fim == tamanho - 1)
		return 1;
	else
		return 0;	
}

void insere(struct fila *p, int x) {
	
	if (cheia(p)) {
		printf("\nFila cheia");
		getch();
	}
	else {
		p->fim = p->fim + 1;
		p->item[p->fim] = x;
	}
}

int retira(struct fila *p) {
	
	int x;
	
	if (vazia(p)) {
		printf("\nFila vazia");
		return -1;
	}
	else {
		x = p->item[p->inicio];
		p->inicio = p->inicio + 1;
		return x;
	}
}

int retira2(struct fila *f) {
	int x;
	
	if (vazia(f)) {
		printf("\nFila vazia");
		return -1;
	}
	else {
		x = f->item[f->inicio];
		
		for (int i = 0; i < f->fim; ++i) {
			f->item[i] = f->item[i + 1];
		}
		
		f->fim = f->fim - 1;
		
		return x;
	}
}

void mostra(struct fila *f) {
	
	struct fila aux;
	int x;
	
	inicializa(&aux);
	
	while(!vazia(f)) {
		x = retira(f);
		printf("\n %d", x);
		insere(&aux, x);
	}	
	
	while(!vazia(&aux)) {
		x = retira(&aux);
		insere(f, x);
	}
}

main() {
	
}
