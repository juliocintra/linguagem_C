#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define tamanho 100

struct veiculo {
	int placa;
	int manobra;
};

struct pilha {
	struct veiculo item[tamanho];
	int topo;
};

void inicializa(struct pilha *p) {
	
	p->topo == -1;
}

int vazia(struct pilha *p) {
	
	if (p->topo == -1) 
		return 1;	
	else 
		return 0;	
}

int cheia(struct pilha *p) {
	
	if (p->topo == tamanho - 1) 
		return 1;	
	else 
		return 0;
}

void push(struct pilha *p, struct veiculo x) {
	
	if (cheia(p)) {
		printf("\nPilha cheia!");
		getch();
		return;
	}
	else {
		p->topo = p->topo + 1;
		p->item[p->topo] = x;	
	}		
}

struct veiculo pop(struct pilha *p) {
	
	struct veiculo x;
	
	if (vazia(p)) {
		x.placa = -1;
		printf("\nPilha vazia");
		getch();
		return x;
	}
	else {
		x = p->item[p->topo];
		p->topo = p->topo - 1;
		return x;
	}
}

void entradaVeiculo(struct pilha *p, struct veiculo x) {
	
	if (cheia(p)) {
		printf("\nEstacionamento lotado");
		getch();
		return;
	}
	else {
		push(p, x);
		printf("\nVeiculo entrou no estacionamento");
		getch();
	}
}

struct veiculo saidaVeiculo(struct pilha *p, int placa) {
	
	struct veiculo x;
	struct pilha aux;
	
	if (vazia(p)) {
		printf("\nEstacionamento vazio");
		getch();
		x.placa = -1;
		return x;
	}
	else {
		inicializa(&aux);
		
		while (!vazia(p)) {
			x = pop(p);
			
			if (x.placa != placa) {
				x.manobra = x.manobra + 1;
				push(&aux, x);
			}
			else {
				break;
			}
		}
		
		while (!vazia(&aux)) {
			//push(p, pop(&aux);
			x = pop(&aux);
			push(p, x);
		}	
		
		if (x.placa != placa) {
			x.placa = -1;
		}
	}
}


main() {
	
}
