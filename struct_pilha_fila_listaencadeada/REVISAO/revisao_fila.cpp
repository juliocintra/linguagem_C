#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define tamanho 100

/*
	ESCREVER UMA FUNCAO PARA RETORNAR A QUANTIDADE DE ELEMENTOS DE UMA FILA. UTILIZAR AS FUNCOES PRIMITIVAS;
*/

struct fila {
	int item[tamanho];
	int inicio;
	int fim;
	int contador;
};

void inicializa(struct fila *f) {
	f->inicio = 0;
	f->fim = tamanho - 1;
	f->contador = 0;
}

int filaCheia(struct fila *f) {
	if (f->contador == tamanho)
		return 1;
	else
		return 0;	
}

int filaVazia(struct fila *f) {
	if (f->contador == 0) 
		return 1;
	else
		return 0;	
}

void insere(struct fila *f, int x) {
	if (filaCheia(f)) {
		printf("Fila Cheia");
		getch();
	}
	else {
		if (f->fim == tamanho - 1) 
			f->fim = 0;
		else
			f->fim = f->fim + 1;	
			
		f->item[f->fim] = x;
		f->contador++;
	}
}

int retira(struct fila *f) {
	
	int x;
	
	if (filaVazia(f)) {
		printf("Fila Vazia");
		getch();
	}
	else {
		x = f->item[f->inicio];
		
		if (f->inicio == tamanho - 1)
			f->inicio = 0;
		else
			f->inicio = f->inicio + 1;	
			
		f->contador = f->contador - 1;
		
		return x;	
	}
}

int qtdeElementos(struct fila *f) {
	
	struct fila aux;
	int x;
	int qtde = 0;
	
	inicializa(&aux);
	
	if (filaVazia(f)) {
		printf("Fila Vazia!");
		getch();
	}
	else {
		while(!filaVazia(f)) {
			x = retira(f);
			insere(&aux, x);
		}
		
		while(!filaVazia(&aux)) {
			x = retira(&aux);
			insere(f, x);
			
			qtde++;
		}
	}
	
	return qtde;
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
	
	struct fila f;
	
	inicializa(&f);
	
	insere(&f, 1);
	insere(&f, 2);
	insere(&f, 3);
	
	printf("Quantidade Elementos = %d", qtdeElementos(&f));
	
	/*
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
	*/
}
