#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define tamanho 6

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

void mostraFila(struct fila *f) {
	
	struct fila aux;
	int x;
	
	inicializa(&aux);
	
	while(!vazia(f)) {
		x = retira(f);
		insere(&aux, x);
	}	
	
	while (!vazia(&aux)) {
		x = retira(&aux);
		insere(f, x);
		
		printf("%d ", x);
	}
}

void retiraTalElemento(struct fila *f, int pn) {
	
	struct fila aux;
	int x;
	
	inicializa(&aux);
	
	printf("\n\nPilha atual\n");
	while (!vazia(f)) {
		x = retira(f);
		
		if (x != pn) 
			insere(&aux, x);
			
		printf("%d  ", x);					
	}
	
	printf("\nPilha retirada\n");
	while (!vazia(&aux)) {
		x = retira(&aux);
		insere(f, x);
		
		printf("%d  ", x);
	}
}

main() {
	
	struct fila f;
	
	inicializa(&f);
	
	insere(&f, 11);
	insere(&f, 2);
	insere(&f, 3);
	
	mostraFila(&f);
	printf("\n\nQuantidade de elementos da fila = %d", quantidadeElementos(&f));
	
	
	
	retiraTalElemento(&f, 2);
		
	getch();
}
