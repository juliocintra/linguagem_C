#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct lista {
	int info;
	struct lista *proximo;
};

struct lista *inicio;

void insereInicio(int x)
{ struct lista * aux;
aux=(struct lista *)malloc(sizeof(struct lista));
aux ->info = x;
aux ->proximo=inicio; // correcao
inicio=aux;
}
void removeInicio( )
{ struct lista *aux;
aux = inicio;
inicio = inicio->proximo;
free(aux);
}

void insereDepois(struct lista *p, int x)
{ struct lista *aux;
aux=(struct lista *) malloc(sizeof(struct lista));
aux ->info=x;
aux ->proximo=p->proximo;
p->proximo=aux;
}
void remove_depois(struct lista *p)
{ struct lista *aux;
aux = p->proximo;
p->proximo = aux->proximo;
free(aux);
}

void insereOrdenado(int x)
{ struct lista *p, *q;
p=inicio;
if((p==NULL)||(x<p->info))
{ insereInicio(x);
return; }
q=p;
while((q!=NULL) && (q->info<x))
{ p=q;
q=p->proximo; }
if((q==NULL) || (q->info>x))
insereDepois(p, x);
else
printf("\nElemento já Existe");
}

main() {
	
}
