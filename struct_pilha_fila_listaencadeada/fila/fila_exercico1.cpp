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

main() {
	
	struct fila f;
	
	filaInicializa(&f);
	
	insere(&f, 1);
	insere(&f, 2);
	insere(&f, 3);
	insere(&f, 3);
	insere(&f, 3);
	insere(&f, 3);
	
	printf("Quantidade de elementos = %d", quantidadeElementos(&f));
}
