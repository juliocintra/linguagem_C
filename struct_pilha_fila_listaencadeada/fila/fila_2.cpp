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

main() {
	
}
