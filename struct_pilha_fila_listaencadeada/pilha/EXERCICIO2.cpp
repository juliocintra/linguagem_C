/*
	VERIFICA PILHAS IGUAIS OU DIFERENTES
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define tamanho 100

struct pilha{
	int topo;
	int item[tamanho];
};

void inicializa(struct pilha *ps) {
	ps->topo = -1;
}

int vazia(struct pilha *ps) {
	
	if (ps->topo == -1)
		return 1;
	else
		return 0;	
}

int cheia(struct pilha *ps) {
	
	if (ps->topo == tamanho - 1) {
		return 1;
	}
	else
		return 0;		
}

void push(struct pilha *ps, int x) {
	
	if (cheia(ps)) {
		printf("\nPilha cheia");
		getch();
	}
	else {
		ps->topo = ps->topo + 1;
		ps->item[ps->topo] = x;
	}
}

int pop(struct pilha *ps) {
	
	int x;
	
	if (vazia(ps)) {
		printf("\nPilha vazia");
		getch();
		return -1;
	}
	else {
		x = ps->item[ps->topo];
		ps->topo = ps->topo -1;
		return x;
	}
}

int quantidadeElementos(struct pilha *ps) {
	
	struct pilha aux;
	int contador = 0;
	int x;
	
	if (vazia(ps)) {
		return 0;
	}
	
	inicializa(&aux);
	
	while(!vazia(ps)) {
		x = pop(ps);
		contador++;
		push(&aux, x);
	}
	
	while(!vazia(&aux)) {
		x = pop(&aux);
		push(ps, x);
	}
	
	return contador;
}

void mostraPilha(struct pilha *ps) {
	
	struct pilha aux;
	int x;
	
	inicializa(&aux);
	
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	
	printf("\nElementos da pilha");
	
	while (!vazia(&aux)) {
		x = pop(&aux);
		printf("\n %d", x);
		push(ps, x);
	}
	
}

void retiraPrimeiroElemento(struct pilha *ps) {
	printf("\n\n");
	struct pilha aux;
	int x;
	
	inicializa(&aux);
	
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	
	x = pop(&aux);
	
	while (!vazia(&aux)) {
		x = pop(&aux);
		push(ps, x);
		printf("\n %d", x);
	}
}

void pilhaParImpar(struct pilha *ps, struct pilha *ppar, struct pilha *pimpar) {
	
	int x;
	struct pilha aux;
	struct pilha auxpar;
	struct pilha auximpar;
	
	inicializa(&aux);
	
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	
	while (!vazia(&aux)) {
		x = pop(&aux);
		
		if (x % 2 == 0) {
			push(ppar, x);
		}
		else {
			push(pimpar, x);
		}
		
		push(ps, x);
	}
}

int comparaPilhas(struct pilha *p1, struct pilha *p2) {
	
	int x, y;
	struct pilha aux1;
	struct pilha aux2;
	
	inicializa(&aux1);
	inicializa(&aux2);
	
	if (quantidadeElementos(p1) != quantidadeElementos(p2)) {
			return 0;
		}
	
	while(!vazia(p1)) {
		x = pop(p1);	
		push(&aux1, x);
		
		y = pop(p2);
		push(&aux2, x);
		
		if (x != y) {
			return 0;
		}
	}
	
	while(!vazia(&aux1)) {
		x = pop(&aux1);
		push(p1, x);
		
		y = pop(&aux2);
		push(p2, y);
		
		printf("\n %d", x);
	}
	
	return 1;		
}

void preencheVetorPilha(struct pilha *p1, struct pilha *p2) {
	
	
}

main() {
	
	struct pilha s;
	struct pilha par;
	struct pilha impar;
	struct pilha t;
	
	inicializa(&s);
	inicializa(&t);
	inicializa(&par);
	inicializa(&impar);
	
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	
	push(&t, 1);
	push(&t, 2);
	push(&t, 3);
	
	preencheVetorPilha(&s, &t);
	
	if (comparaPilhas(&s, &t) == 0) {
		printf("\nPilhas Diferentes");
		getch();
	}
	else {
		printf("\nPilhas Iguais");
		getch();
	}
	//mostraPilha(&s);
	
	//retiraPrimeiroElemento(&s);
	
	//pilhaParImpar(&s, &par, &impar);
	
	//printf("\nQuantidade de elementos na pilha: %d", quantidadeElementos(&s));
	
	//printf("\nElemento retirado da pilha: %d", pop(&s));
	//getch();
}
