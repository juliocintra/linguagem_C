#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define tamanho 100

/*
	1) utilizando apenas a funcoes primitivas para manipulacao de pilha,
	escreva uma funcao em C que retorna a quantidade de elementos da pilha.
	Apos a execucao da funcao a pilha deve manter seus valores originais;
*/

/*
	2) Utilizando apenas a funcoes primitivas p/ manipulacao de pilha,
	escreva uma funcao em C para mostrar os elementos da pilha na ordem
	de inclusao. Apos o termino da funcao, a pilha deve manter seus valores originais;
*/

/*
	3) Utilizando apenas as funcoes primarias para manipulacao de pilha,
	escreva uma funcao em C para retirar da pilha o primeiro elemento incluido.
	Apos o termino da funcao a pilha deve manter os elementos restantes na ordem
	que foram incluidos
*/

struct pilha {
	int topo;
	int item[tamanho];
};

void inicializa(struct pilha *p) {
	p->topo = -1;
}

int cheia(struct pilha *p) {
	if (p->topo == tamanho - 1)
		return 1;
	else
		return 0;
}

int vazia(struct pilha *p) {
	if (p->topo == -1) 
		return 1;
	else return 0;	
}

void push(struct pilha *p, int x) {
	if (cheia(p)) {
		printf("Pilha Cheia!");
		getch();
	}
	else {
		p->topo = p->topo + 1;
		p->item[p->topo] = x;
	}
}

int pop(struct pilha *p) {
	
	int x;
	
	if (vazia(p)) {
		printf("Pilha Vazia");
		getch();
	}
	else {
		x = p->item[p->topo];
		p->topo = p->topo - 1;
	}
	
	return x;
}

int qtdeElementos(struct pilha *p) {
	struct pilha aux;
	int x;
	int qtde = 0;
	
	inicializa(&aux);
	
	while(!vazia(p)) {
		x = pop(p);
		push(&aux, x);
	}
	
	while(!vazia(&aux)) {
		x = pop(&aux);
		push(p, x);
		
		qtde++;
	}
	
	return qtde;
}

int verificaPilhasIguais(struct pilha *p1, struct pilha *p2) {
	
	int x, y;
	struct pilha aux1;
	struct pilha aux2;
	int retorno = 1;
	
	inicializa(&aux1);
	inicializa(&aux2);
	
	if (qtdeElementos(p1) != qtdeElementos(p2)) 
		return 0;
		
	while (!vazia(p1)) {
		x = pop(p1);
		y = pop(p2);
		
		push(&aux1, x);
		push(&aux2, y);
	}	
	
	while (!vazia(&aux1)) {
		x = pop(&aux1);
		y = pop(&aux2);
		
		push(p1, x);
		push(p2, y);
		
		if (x != y)
			retorno = 0;
	}
	
	return retorno;
}

main() {
	
	struct pilha p1;
	struct pilha p2;
	
	inicializa(&p1);
	inicializa(&p2);
	
	push(&p1, 1);
	push(&p1, 2);
	push(&p1, 3);
	
	push(&p2, 1);
	push(&p2, 2);
	push(&p2, 3);
	
	if (verificaPilhasIguais(&p1, &p2)) {
		printf("Pilhas Iguais");
		getch();
	}
	else {
		printf("Pilhas Diferentes");
		getch();
	}
}
