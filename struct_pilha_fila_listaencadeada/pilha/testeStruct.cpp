#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define tamanho 10

struct ficha_aluno {
	int codigo;
	char nome[50];
	char disciplina[30];
	float nota_prova1;
	float nota_prova2; 
};
int pos;

int menu() {
	int opcao;
	printf("\n.....Menu.....");
	printf("\n1 - Incluir aluno");
	printf("\n2 - Alterar aluno");
	printf("\n3 - Excluir aluno");
	printf("\n4 - Pesquisar aluno");
	printf("\n5 - Mostrar todos os alunos cadastrados");
	printf("\n6 - Terminar");
	printf("\n\nDigite a sua opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void mostraAluno(struct ficha_aluno aluno) {
	printf("\nCodigo aluno: %d", aluno.codigo);
	printf("\nNome Aluno: %s", aluno.nome);
	printf("\nDisciplina aluno: %s", aluno.disciplina);
	printf("\nNota 1 aluno: %.1f", aluno.nota_prova1);
	printf("\nNota 2 aluno: %.1ff", aluno.nota_prova2);
}

int buscaAluno(struct ficha_aluno cadastro[], int codigo) {
	int i;
	for(i = 0; i < pos; ++i) {	
		if (cadastro[i].codigo == codigo) {
			return i;
		}
	}
	return -1;
}

struct ficha_aluno entradaDadosAluno() {
	
	struct ficha_aluno aluno;
	fflush(stdin);
	
	printf("\nInforme o nome do aluno: ");
	gets(aluno.nome);
	
	printf("\nInforme a disciplina: ");
	gets(aluno.disciplina);
	
	printf("\nInforme a primeira nota: ");
	scanf("%f", &aluno.nota_prova1);
	
	printf("\nInforme a segunda_nota \n");
	scanf("%f", &aluno.nota_prova2);
	
	return aluno;
}

void incluirAluno(struct ficha_aluno cadastro[]) {
	int indice;
	int cod;
	struct ficha_aluno aluno;
	
	printf("\nInforme o codigo do aluno: ");
	scanf("%d", &cod);
	
	indice = buscaAluno(cadastro, cod);
	
	if (indice != -1) {
		printf("\nAluno ja cadastrado: %s", cadastro[indice].nome);
		getch();
		return;
	}
	
	aluno = entradaDadosAluno();
	aluno.codigo = cod;
	cadastro[pos] = aluno;
	pos++;
	
}

void alteraAluno(struct ficha_aluno cadastro[]) {
	int indice;
	int cod;
	struct ficha_aluno aluno;
	
	printf("\nInforme o codigo do aluno: ");
	scanf("%d", &cod);
	
	indice = buscaAluno(cadastro, cod);
	
	if (indice == -1) {
		printf("\nAluno nao cadastrado");
		getch();
		return;
	}
	aluno = entradaDadosAluno();
	aluno.codigo = cod;
	cadastro[indice] = aluno;
}

void pesquisarAluno(struct ficha_aluno cadastro[]) {
	int indice;
	int cod;
	printf("\nInforme o codigo do aluno: ");
	scanf("%d", &cod);
	
	indice = buscaAluno(cadastro, cod);
	
	if (indice == -1) {
		printf("\nAluno nao cadastrado");
		getch();
		return;
	}
	
	mostraAluno(cadastro[indice]);
	
	getch();
}

void mostrarAlunos(struct ficha_aluno cadastro[]) {
	int i;
	 
	for (i = 0; i < pos; i++) {    //FUNCAO QUE LISTA TODOS ALUNOS
		mostraAluno(cadastro[i]);
	}
	getch();
	
		
	/*
	printf("\n\nAlunos Cadastrados");
	for (i = 0; i < pos; i++) {
		printf("\nNome = %s", cadastro[i].nome);
	}
	getch();
	*/
	
}

void excluirAluno(struct ficha_aluno cadastro[]) {
	int i;
	int cod;
	int indice;
	
	printf("\nExcluir aluno (codigo): ");
	scanf("%d", &cod);
	
	indice = buscaAluno(cadastro, cod);
	
	if (indice == -1) {
		printf("\nAluno nao cadastrado");
		getch();
		return;
	}	
	
	for (i = indice; i < pos -1; ++i) {
		cadastro[i] = cadastro[i + 1]; // pos -1 é por causa do cadastro[i + 1];
	}
	//cadastro é o que esta dentro do vetor
	pos--; 
}

main() {
	
	int opcao = 0;
	struct ficha_aluno cadastro[tamanho];
	pos = 0;
	
	while (opcao != 6) {
		system("cls");
		opcao = menu();
		
		switch(opcao) {
			
			case 1: {
				if (pos == tamanho) {
					printf("\nVetor cheio");
					getch();
				}
				else {
					incluirAluno(cadastro);
				}
				break;
			}
			
			case 2: {
				if (pos == tamanho) {
					printf("\nVetor cheio");
					getch();
				}
				else {
					alteraAluno(cadastro);
					break;
				}
				break;
			}
			
			case 3: {
				excluirAluno(cadastro);
				break;
			}
			
			case 4: {
				pesquisarAluno(cadastro);
				break;
			}
			
			case 5: {
				mostrarAlunos(cadastro);
				break;
			}
			
			case 6: {
				printf("\nFim do Programa");
				getch();
				break;
			}
			
			default: {
				printf("\nOpcao nao valida");
				getch();
				break;
			}
		}
	}
	
}

