#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define tamanho 100

/*
	ESCREVER UMA FUNCAO PARA RETIRAR UM DETERMINADO ELEMENTO de fila utilizar as primitivas p/ manipulacao de fila
*/

struct fila {
	int item[tamanho];
	int inicio;
	int fim;
	int contador;
};

void filaInicializa(struct fila *f) {
	
	f->inicio = 0;
	f->fim = tamanho - 1;
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
		
		f->item[f->fim] = x;
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
	
	filaInicializa(&aux);
	
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

int verificaFilasIguais(struct fila *f1, struct fila *f2) {
	
	struct fila aux1;
	struct fila aux2;
	int x, y;
	
	filaInicializa(&aux1);
	filaInicializa(&aux2);
	
	if (quantidadeElementos(f1) != quantidadeElementos(f2)) 
		return 0;
	
	while(!vazia(f1)) {
		x = retira(f1);
		y = retira(f2);
		
		insere(&aux1, x);
		insere(&aux2, y);
	}
	
	while(!vazia(&aux1)) {
		x = retira(&aux1);
		y = retira(&aux2);
		
		insere(f1, x);
		insere(f2, y);
		
		if (x != y) 
			return 0;
	}
	
	return 1;
}

int retiraUmElemento(struct fila *f, int px) {
	
	struct fila aux;
	int x;
	
	filaInicializa(&aux);
	
	printf("Fila com o Elemento \n");
	while(!vazia(f)) {
		x = retira(f);
		
		if (x != px)
			insere(&aux, x);
			
		printf("%d  ", x);
	}
	
	printf("\n\nFila sem o Elemento \n");
	while(!vazia(&aux)) {
		x = retira(&aux);
		insere(f, x);
		
		printf("%d  ", x);
	}
}

void mostraFila(struct fila *f) {
	struct fila aux;
	int x;
	
	filaInicializa(&aux);
	
	while(!vazia(f)) {
		x = retira(f);
		insere(&aux, x);
	}
	
	while(!vazia(&aux)) {
		x = retira(&aux);
		insere(f, x);
		
		printf("%d  ", x);
	}
}

void ordenaFila(struct fila *f1, struct fila *f2) {
	
	struct fila filaOrdenada;
	int x, y;
	
	filaInicializa(&filaOrdenada);
	
	while(!vazia(f2)) {
		x = retira(f1);
		y = retira(f2);
		
		
		
		if (x < y) {
			insere(&filaOrdenada, x);
			insere(&filaOrdenada, y);
		}
		else {
			insere(&filaOrdenada, y);
			insere(&filaOrdenada, x);
		}			
	}

	
	printf("Fila em ordem crescente\n");
	mostraFila(&filaOrdenada);
}

main() {
	
	struct fila f1;
	struct fila f2;
	
	filaInicializa(&f1);
	filaInicializa(&f2);
	
	insere(&f1, 1);
	insere(&f1, 5);
	insere(&f1, 6);

	
	insere(&f2, 3);
	insere(&f2, 8);
	insere(&f2, 10);
	
	ordenaFila(&f1, &f2);
	//retiraUmElemento(&f1, 2);
/*	
	if (verificaFilasIguais(&f1, &f2) == 1) {
		printf("Pilhas Iguais");
	}
	else {
		printf("Pilhas Diferentes");
	}
*/
}
