#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 10

struct pilha {
	int topo;
	int vetor[tamanho];
};

void inicializa(struct pilha *pilha) {
	
	pilha->topo = -1;
}

int vazia(struct pilha *pilha) {
	
	if (pilha->topo == -1) 
		return 1;
	else
		return 0;
}

int cheia(struct pilha *pilha) {
	
	if (pilha->topo == tamanho - 1)
		return 1;
	else
		return 0;	
}

void push(struct pilha *pilha, int x) {
	
	if (cheia(pilha)) {
		printf("\nPilha Cheia!");
		getch();
	}
	else {
		pilha->topo = pilha->topo + 1;
		pilha->vetor[pilha->topo] = x;
	}
}

int pop(struct pilha *pilha) {
	
	int x;
	
	if (vazia(pilha)) {
		printf("\nPilha vazia");
		getch();
		return -1;
	}
	else{
		x = pilha->vetor[pilha->topo];
		pilha->topo = pilha->topo - 1;
		return x;
	}
}

void retiraPrimeiroElemento(struct pilha *pilha) {
	
	struct pilha aux;
	int x;
	
	inicializa(&aux);
	
	while(!vazia(pilha)) {
		x = pop(pilha);
		push(&aux, x);
	}
	
	x = pop(&aux);
	
	printf("\nElementos da Pilha");
	
	while(!vazia(&aux)) {
		x = pop(&aux);
		push(pilha, x);
		printf("\n %d", x);
	}
	
}

main() {
	
	struct pilha p;
	
	inicializa(&p);
	
	
	push(&p, 23);
	push(&p, 123);
	push(&p, 53);
	
	retiraPrimeiroElemento(&p);
	
	//printf("\nElemento retirado da pilha = %d", pop(&p));
}
