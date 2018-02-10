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

void retiraPrimeiroElemento(struct pilha *pilha) {
	
	struct pilha aux;
	int x;
	
	while(!vazia(pilha)) {
		x = pop(pilha);
		push(&aux, x);
	}
	
	pop(&aux);
	printf("\nElementos da Pilha");
	while(!vazia(&aux)) {
		x = pop(&aux);
		push(pilha, x);
		printf("\n %d", x);
	}
	
}

main() {
	struct pilha s;
	inicializa(&s);
	
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	
	retiraPrimeiroelemento(&p);
	
	printf("\nElemento retirado da pilha: %d", pop(&s));
	getch();
}
