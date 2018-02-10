#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define tamanho 3

struct pilha{
	int topo1;
	int topo2;
	int item[tamanho];
};

void inicializa(struct pilha *pilha) {
	
	pilha->topo1 = -1;
	pilha->topo2 = tamanho;
}

int vazia1(struct pilha *pilha) {
	
	if (pilha->topo1 == -1) 
		return 1;
	else
		return 0;	
}

int vazia2(struct pilha *pilha) {
	
	if (pilha->topo2 == tamanho)
		return 1;
	else
		return 0;	
}

int cheia(struct pilha *pilha) {
	
	if (pilha->topo1 + 1 == pilha->topo2) 
		return 1;
	else
		return 0;	
	
}

void push1(struct pilha *pilha, int x) {
	
	if (cheia(pilha)) {
		printf("\nPilha Cheia");
		getch();
	}
	else {
		pilha->topo1 = pilha->topo1 + 1;
		pilha->item[pilha->topo1] = x;
	}
}

void push2(struct pilha *pilha, int x) {
	
	if (cheia(pilha)) {
		printf("\nPilha Cheia");
		getch();
	}
	else {
		pilha->topo2 = pilha->topo2 - 1;
		pilha->item[pilha->topo2] = x;
	}
}

int pop1(struct pilha *pilha) {
	
	int x;
	
	if (vazia1(pilha)) {
		printf("\nPilha Vazia");
		getch();
		return -1;
	}
	else {
		x = pilha->item[pilha->topo1];
		pilha->topo1 = pilha->topo1 - 1;
		return x;
	}
}

int pop2(struct pilha *pilha) {
	
	int x;
	
	if (vazia2(pilha)) {
		printf("\nPilha Vazia");
		getch();
		return -1;
	}
	else {
		x = pilha->item[pilha->topo2];
		pilha->topo2 = pilha->topo2 + 1;
		return x;
	}
}

main() {
	
	struct pilha s;
	struct pilha t;
	
	inicializa(&s);
	inicializa(&t);
	
	push1(&s, 1);
	push1(&s, 2);
	push1(&s, 3);

	push2(&t, 1);
	push2(&t, 2);
	push2(&t, 3);
}



