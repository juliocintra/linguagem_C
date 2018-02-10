#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define tamanho 6

/*
	ESCREVER UMA FUNCAO PARA COMPARAR AS FILAS. UTILIZAR AS FUNCOES PRIMITIVAS;
*/

struct fila {
	int item[tamanho];
	int inicio;
	int fim;
	int contador;
};

void inicializa(struct fila *f) {
	
	f->inicio = 0;
	f->fim = tamanho -1;
	f->contador = 0;
}
int vazia(struct fila *f) {
	
	if (f->contador == 0)
		return 1;
	else
		return 0;	
}

int cheia(struct fila *f) {
	
	if (f->contador == tamanho)
		return 1;
	else
		return 0;
}

void insere(struct fila *f, int x) {
	
	if (cheia(f)) {
		printf("\nFila Cheia");
		getch();
	}
	else {
		if (f->fim == tamanho - 1) 
			f->fim = 0;
		else
			f->fim = f->fim + 1;
			
		f->item[f->fim]	= x;
		f->contador = f->contador + 1;
	}
}

int retira(struct fila *f) { 
	
	int x;
	
	if (vazia(f)) {
		printf("\nFila vazia");
		getch();
		return -1;
	}
	
	x = f->item[f->inicio];
	
	if (f->inicio == tamanho - 1)
		f->inicio = 0;
	else
		f->inicio = f->inicio + 1;
	
	f->contador = f->contador - 1;
	
	return x;		
}

int quantidadeElementos(struct fila *f) {
		
	struct fila aux;
	int x;
	int cont = 0;
	
	inicializa(&aux);
	
	while(!vazia(f)) {
		x = retira(f);
		insere(&aux, x);
		
		cont++;
	}
	
	while (!vazia(&aux)) {
		x = retira(&aux);
		insere(f, x);
	}
	
	return cont;
}

int comparaFilas(struct fila *a, struct fila *b) {
	
	struct fila aux1;
	struct fila aux2;
	int x, y, retorno;
	
	inicializa(&aux1);
	inicializa(&aux2);
	
	if (quantidadeElementos(a) != quantidadeElementos(b))  
		return 0;
	
	while (!vazia(a)) {
		x = retira(a);
		y = retira(b);
		
		insere(&aux1, x);
		insere(&aux2, y);
	}	
	
	while(!vazia(&aux1)) {
		x = retira(&aux1);
		y = retira(&aux2);
		
		insere(a, x);
		insere(b, y);
		
		if (x != y)
			return 0;		
	}
	
	return 1;
}

main() {
	
	struct fila a;
	struct fila b;
	
	inicializa(&a);
	inicializa(&b);
	
	insere(&a, 1);
	insere(&a, 2);
	insere(&a, 3);
	
	insere(&b, 1);
	insere(&b, 2);
	insere(&b, 3);
	
	if (comparaFilas(&a, &b)) {
		printf("As filas sao IGUAIS");	
		getch();	
	}
	else {
		printf("As filas sao DIFERENTES");
		getch();	
	}
}
