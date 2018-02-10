#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define tamanho 100

struct veiculo {
	int placa;
	int manobras;
};

struct pilha {
	struct veiculo item[tamanho];
	int topo;
};
