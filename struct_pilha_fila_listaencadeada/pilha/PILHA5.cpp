/*
	4) Utilizando apenas as funcoes primitivas para manipulacao de pilha,
	escreva uma função em C que recebe como parametros tres pilhas (pilhas, ps, ppar, pimpar).
	A funcao deve copiar os elementos pares de ps para a pilha ppar e os elementos impares
	de ps para a pilha pimpar. Os elementos em ppar e em pimpar devem estar na mesma orde da pilha ps
*/

/*
	3) Utilizando apenas as funcoes primarias para manipulacao de pilha,
	escreva uma funcao em C para retirar da pilha o primeiro elemento incluido.
	Apos o termino da funcao a pilha deve manter os elementos restantes na ordem
	que foram incluidos
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

main() {
	
	struct pilha s;
	struct pilha par;
	struct pilha impar;
	
	inicializa(&s);
	inicializa(&par);
	inicializa(&impar);
	
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	push(&s, 6);
	
	mostraPilha(&s);
	
	retiraPrimeiroElemento(&s);
	
	pilhaParImpar(&s, &par, &impar);
	
	printf("\nQuantidade de elementos na pilha: %d", quantidadeElementos(&s));
	
	printf("\nElemento retirado da pilha: %d", pop(&s));
	getch();
}
