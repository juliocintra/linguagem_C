#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct aluno
{  int codigo;
   char nome[50];
   float notas[2];
   struct aluno * proximo;
};

struct disciplina
{  int codigo;
   char nome[50];
   int numHoras;
   char curso[50];
   struct disciplina * proximo;
   struct aluno * ialuno;
};

struct professor
{
   int codigo;
   char nome[50];
   int tipo; // 1.Horista, 2.Mensalista
   struct professor * proximo;
   struct disciplina * idisciplina;
};

struct professor *insereInicioProfessor(struct professor *inicioProf, int codigo, char nome[50], int tipo) {
	struct professor *aux;
	aux = (struct professor *) malloc(sizeof(struct professor));
	aux->codigo = codigo;
	strcpy(aux->nome, nome);
	aux->tipo = tipo;
	aux->proximo = inicioProf;
	inicioProf = aux;
	inicioProf->idisciplina = NULL;							//TODA VEZ QUE SE INSERE UM PROFESSOR DEVE SETAR DISCIPLINA COMO NULL;
		
	return inicioProf;
}

void insereInicioDisciplina(struct professor *prof, struct disciplina *inicioDisc, int codigo, char nome[50], int numHoras, char curso[50]) {
	struct disciplina *aux;
	aux = (struct disciplina *) malloc(sizeof(struct disciplina));
	aux->codigo = codigo;
	strcpy(aux->nome, nome);
	aux->numHoras = numHoras;
	strcpy(aux->curso, curso);
	aux->proximo = inicioDisc;
	inicioDisc = aux;
	
	prof->idisciplina = aux;
	aux->ialuno = NULL;							
}

void insereInicioAluno(struct disciplina *disc, struct aluno *inicioAluno, int codigo, char nome[50], float *notas) {
	struct aluno *aux;
	aux = (struct aluno *) malloc(sizeof(struct aluno));
	aux->codigo = codigo;
	strcpy(aux->nome, nome);
	aux->notas[0] = notas[0];
	aux->notas[1] = notas[1];
	aux->proximo = inicioAluno;
	inicioAluno = aux;	
	
	disc->ialuno = aux;										
}

void insereDepoisProfessor(struct professor *prof, int codigo, char nome[50], int tipo) {
	struct professor *aux;
	aux = (struct professor *) malloc(sizeof(struct professor));
	aux->codigo = codigo;
	strcpy(aux->nome, nome);
	aux->tipo = tipo;
	aux->proximo = prof->proximo;
	prof->proximo = aux;
	
	aux->idisciplina = NULL; 								//TODA VEZ QUE SE INSERE UM PROFESSOR DEVE SETAR DISCIPLINA COMO NULL;
}

void insereDepoisDisciplina(struct disciplina *disc, int codigo, char nome[50], int numHoras, char curso[50]) {
	struct disciplina *aux;
	aux = (struct disciplina *) malloc(sizeof(struct disciplina));
	aux->codigo = codigo;
	strcpy(aux->nome, nome);
	aux->numHoras = numHoras;
	strcpy(aux->curso, curso);
	aux->proximo = disc->proximo;
	disc->proximo = aux;
	
	aux->ialuno = NULL;
}

void insereDepoisAluno(struct aluno *aluno, int codigo, char nome[50], float *notas) {
	struct aluno *aux;
	aux = (struct aluno *) malloc(sizeof(struct aluno));
	aux->codigo = codigo;
	strcpy(aux->nome, nome);
	aux->notas[0] = notas[0];
	aux->notas[1] = notas[1];
	aux->proximo = aluno->proximo;
	aluno->proximo = aux;	
}

struct professor *insereProfessorOrdenado(struct professor *inicioProf, int codigo, char nome[50], int tipo) {
	struct professor *p, *q;
	
	if (inicioProf == NULL || codigo < inicioProf->codigo) {
		printf("\nProfessor inserido com sucesso...");
		getch();
		return	insereInicioProfessor(inicioProf, codigo, nome, tipo);
	}
	
	p = q = inicioProf;
	
	while(q != NULL && q->codigo < codigo) {
		p = q;
		q = p->proximo;
	}	
	
	if (q == NULL || q->codigo > codigo) {
		printf("\nProfessor inserido com sucesso...");
		getch();
		insereDepoisProfessor(p, codigo, nome, tipo);
	}		
	else {
		printf("\nJa existem Professores com esse codigo");
		getch();
	}
	
	return inicioProf;
}

struct professor *encontraProfessor(struct professor *inicioProf, int codigo) {
	struct professor *procuraProf;
	procuraProf = inicioProf;
	
	while(procuraProf != NULL) 
	{
		if (procuraProf->codigo == codigo) 		
			return procuraProf;					//ACHOU O PROFESSOR COM O CODIGO E RETORNA SEU ENDEREÇO DE MEMORIA
						
		procuraProf = procuraProf->proximo;			
	}
	
	return procuraProf;							//NAO ACHOU O PROFESSOR, RETORNA NULL
}

struct aluno *encontraAluno(struct professor *inicioProf, int codigo){
	struct professor *procuraProf;
	struct disciplina *procuraDisc;
	struct aluno *procuraAluno;
	procuraProf = inicioProf;
	
	while(procuraProf!=NULL)
	{
		procuraDisc = procuraProf->idisciplina;
		while(procuraDisc!=NULL)
		{
			procuraAluno = procuraDisc->ialuno;
			while(procuraAluno!=NULL)
			{
				if(codigo == procuraAluno->codigo)
					return procuraAluno;
				
				procuraAluno = procuraAluno->proximo;
			}
			
			procuraDisc = procuraDisc->proximo;
		}
		
		procuraProf = procuraProf->proximo;
	}
	
	return NULL;
}

struct disciplina *procuraDisciplina(struct professor *inicio, int codigoProf, int codigoDisc) {
	struct professor *prof;
	struct disciplina *disc;
	prof = inicio;
	
	while(prof != NULL) {
		
		disc = prof->idisciplina;
		
		while(disc != NULL) {				//aux agora possui o valor do primeiro item da lista disciplina
			
			if (disc->codigo == codigoDisc)
				return disc;
				
			disc = disc->proximo;	
		}
		
		prof = prof->proximo;
	}
	
	return NULL;	
}

void insereDisciplinaOrdenado(struct professor *inicioProf, int codigoProf, int codigoDisc, char nome[50], int numHoras, char curso[50]) {
	struct disciplina *inicioDisc, *p, *q;
	struct professor *prof;
	prof = encontraProfessor(inicioProf, codigoProf);						//FUNCAO PARA ENCONTRAR PROFESSOR COM CODIGO PASSADO COMO PARAMETRO
	
	if (prof == NULL) {
		printf("\nImpossivel inserir disciplina! Professor nao cadastrado");
		getch();
		return;
	}
	
	if (procuraDisciplina(inicioProf, codigoProf, codigoDisc) != NULL) {
		printf("\nEssa Disciplinas ja e ministrada por um professor");
		getch();
		return;
	}	
	
	inicioDisc = prof->idisciplina;

	if (inicioDisc == NULL || codigoDisc < inicioDisc->codigo) {
		printf("\nDisciplina inserida com Sucesso");
		getch();
		insereInicioDisciplina(prof, inicioDisc, codigoDisc, nome, numHoras, curso);
		return;
	}
		
	q = inicioDisc;
	p = q;

	while(q != NULL && q->codigo < codigoDisc)
	{
		p = q;
		q = p->proximo;
	}
	
	if (q == NULL || q->codigo > codigoDisc) {
		printf("\nDisciplina inserida com Sucesso");
		getch();
		insereDepoisDisciplina(p, codigoDisc, nome, numHoras, curso);
	}		
}

struct disciplina *encontraDisciplina(struct professor *inicioProf, int codigoDisc) {
	struct professor *prof;
	struct disciplina *disc;
	prof = inicioProf;
	
	while(prof != NULL) {
		disc = prof->idisciplina;
		
		while(disc != NULL) {
			
			if (disc->codigo == codigoDisc)
				return disc;
			
			disc = disc->proximo;
		}
		
		prof = prof->proximo;
	}
	
	return NULL;
}

struct professor *encontraProfessorDisciplina(struct professor *inicioProf, int codigoDisc) {
	struct professor *prof;
	struct disciplina *disc;
	prof = inicioProf;
	
	while(prof != NULL) {
		disc = prof->idisciplina;
		
		while(disc != NULL) {
			
			if (disc->codigo == codigoDisc)
				return prof;
			
			disc = disc->proximo;
		}
		
		prof = prof->proximo;
	}
	
	return NULL;
}

void insereAlunoOrdenado(struct professor *inicioProf, int codigoDisc, int codigoAluno, char nome[50], float *notas) {
	struct aluno *inicioAluno, *p, *q;
	struct professor *prof;
	struct disciplina *disc;
	
	disc = encontraDisciplina(inicioProf, codigoDisc);
	
	if (disc == NULL) {
		printf("\nImpossivel inserir Aluno! Disciplina nao cadastrada");
		getch();
		return;
	}
	
	inicioAluno = disc->ialuno;
	
	if (inicioAluno == NULL || codigoAluno < inicioAluno->codigo) {
		printf("\nAluno inserido com sucesso!");
		getch();
		insereInicioAluno(disc, inicioAluno, codigoAluno, nome, notas);
		return;
	}
	
	q = inicioAluno;
	p = q;
	
	while(q != NULL && q->codigo < codigoAluno) {
		p = q;
		q = p->proximo;
	}
	
	if (q == NULL || q->codigo > codigoAluno) {
		printf("\nAluno inserido com sucesso!");
		getch();
		insereDepoisAluno(p, codigoAluno, nome, notas);
	}
		
	else {
		printf("\nAluno ja cadastrado nessa Disciplina...");
		getch();
	}
}

void alteraDadosProfessor(struct professor *prof) {
	char nome[50];
	int tipo;
	
	printf("\nNovo nome do Professor: ");
	scanf("%s", &nome);
	
	printf("\nNovo tipo do Professor: ");
	scanf("%d", &tipo);
	
	strcpy(prof->nome, nome);
	prof->tipo = tipo;
	
	printf("\nProfessor Alterado com Sucesso!");
	getch();
}

void alteraProfessor(struct professor *inicio) {
	struct professor *prof;
	int codigo;
	
	printf("\nQual professor deseja alterar: ");
	scanf("%d", &codigo);
	
	prof = encontraProfessor(inicio, codigo);
	
	if (prof != NULL) 
		alteraDadosProfessor(prof);
	else {
		printf("\nImpossivel alterar! Professor nao encontrado");
		getch();
	}
}

void alteraDadosDisciplina(struct disciplina *disc) {
	char nome[50];
	int numHoras;
	char curso[50];
	
	printf("\nNovo nome da Disciplina: ");
	scanf("%s", &nome);
	
	printf("\nNovo numero de horas: ");
	scanf("%d", &numHoras);
	
	printf("\nNovo nome do Curso: ");
	scanf("%s", &curso);
	
	strcpy(disc->nome, nome);
	disc->numHoras = numHoras;
	strcpy(disc->curso, curso);
	
	printf("\nDisciplina Alterada com Sucesso!");
	getch();
}

void alteraDisciplina(struct professor *inicio) {
	struct disciplina *disc;
	int codigo;
	
	printf("\nQual discipina deseja alterar: ");
	scanf("%d", &codigo);
	
	disc = encontraDisciplina(inicio, codigo);
	
	if (disc != NULL) 
		alteraDadosDisciplina(disc);
	else {
		printf("\nImpossivel alterar! Disciplina nao encontrada");
		getch();
	}
}

void alteraDadosAluno(struct aluno *aluno, struct professor *inicioProf, int codigo) {
	struct professor *procuraProf;
	struct disciplina *procuraDisc;
	struct aluno *procuraAluno;
	
	char nome[50];
	float notas[2];
	int escolha;

	printf("\nNovo nome do Aluno: ");
    scanf("%s", &nome);
   
	while(procuraProf!=NULL)
	{
		procuraDisc = procuraProf->idisciplina;
		while(procuraDisc!=NULL)
		{
			procuraAluno = procuraDisc->ialuno;
			while(procuraAluno!=NULL)
			{
				if(codigo == procuraAluno->codigo)
				{
					strcpy(procuraAluno->nome, nome);
					
					printf("\nDeseja alterar a nota da materia: %s" , procuraDisc->nome);
					printf("\n1) Sim ");
					printf("\n2) Nao");
					printf("\nEscolha: ");
					scanf("%d" , &escolha);
					
					if(escolha == 1)
					{
						printf("\nNova nota A1: ");
	   					scanf("%f", &notas[0]);
	   
	   					printf("\nNova nota A2: ");
	    				scanf("%f", &notas[1]);
	    				
	    				procuraAluno->notas[0] = notas[0];
	    				procuraAluno->notas[1] = notas[1];
    				}
    				printf("\nAluno Alterado com Sucesso!");
					getch();
					
				}
				
				procuraAluno = procuraAluno->proximo;
			}
			
			procuraDisc = procuraDisc->proximo;
		}
		
		procuraProf = procuraProf->proximo;
	}

}

void alteraAluno(struct professor *inicioProf) {
	struct aluno *aluno;
	int codigo;
	
	printf("\nDigite o codigo do aluno: ");
	scanf("%d" , &codigo);
	
	aluno = encontraAluno(inicioProf, codigo);
	
	if(aluno != NULL)
		alteraDadosAluno(aluno, inicioProf, codigo);
	else {
		printf("\nImpossivel alterar! Aluno nao encontrado...");
		getch();
	}
		
}

struct professor *excluirInicioProfessor(struct professor *inicioProf) {
	struct professor *prof;
	prof = inicioProf;
	inicioProf = inicioProf->proximo;
	free(prof);
	
	return inicioProf;
}

void excluirInicioDisciplina(struct disciplina *inicioDisc, struct professor *prof) {
	struct disciplina *disc;
	disc = inicioDisc;
	inicioDisc = inicioDisc->proximo;
	free(disc);
	
	prof->idisciplina = inicioDisc;
}

void excluirInicioAluno(struct aluno *inicioAluno, struct disciplina *disc) {
	struct aluno *aluno;
	aluno = inicioAluno;
	inicioAluno = inicioAluno->proximo;
	free(aluno);
	
	disc->ialuno = inicioAluno;
}

struct professor *excluirDepoisProfessor(struct professor *prof) {
	struct professor *aux;
	aux = prof->proximo;
	prof->proximo = aux->proximo;
	free(aux);
}

void excluirDepoisDisciplina(struct disciplina *disc) {
	struct disciplina *aux;
	aux = disc->proximo;
	disc->proximo = aux->proximo;
	free(aux);
}

void excluirDepoisAluno(struct aluno *aluno) {
	struct aluno *aux;
	aux = aluno->proximo;
	aluno->proximo = aux->proximo;
	free(aux);
}

struct professor *excluirProfessorOrdenado(struct professor *inicioProf, int codigo) {
	struct professor *prof, *p, *q;
	
	if (inicioProf == NULL) {
		printf("\nLista de Professores esta Vazia");
		getch();
		return inicioProf;
	}
	
	prof = encontraProfessor(inicioProf, codigo);
	
	if (prof == NULL) {
		printf("\nNao existe professor com esse codigo");
		getch();
		return inicioProf;
	}
	
	if (prof->idisciplina != NULL) {
		printf("\nEste Professor possui disciplinas vinculadas!");
		getch();
		return inicioProf;
	}
	
	if (codigo == inicioProf->codigo) {
		printf("\nProfessor excluido com sucesso...");
		getch();
		return excluirInicioProfessor(inicioProf);		
	}
	
	p = inicioProf;
	q = p;
	
	while(q != NULL && q->codigo < codigo) {
		p = q;
		q = p->proximo;
	}
	
	if (q != NULL && q->codigo == codigo)  {
		printf("\nProfessor excluido com sucesso...");
		getch();
		excluirDepoisProfessor(p);
	}
			
	return inicioProf;
}

void excluirDisciplinaOrdenado(struct professor *inicioProf, int codigoDisc) {
	struct disciplina *disc, *p, *q;
	struct professor *prof;
	
	disc = encontraDisciplina(inicioProf, codigoDisc);
	
	if (disc == NULL) {
		printf("\nNao existem Disciplinas com esse codigo");
		getch();
		return;
	}
	
	if (disc->ialuno != NULL) {
		printf("\nEsta disciplina possui alunos vinculados");
		getch();
		return;
	}
	
	prof = encontraProfessorDisciplina(inicioProf, codigoDisc);  //FUNCAO PARA RETORNAR O PROFESSOR REFERENTE A ESSA DISCIPLINA
	
	if (prof->idisciplina == disc) {
		printf("\nDisciplina excluida com sucesso...");
		getch();				// if verifica se a discplina encontrada é o inicio;
		excluirInicioDisciplina(disc, prof);
		return;
	}
	
	p = prof->idisciplina;							//p esta pegando o inicio da lista de disciplinas
	q = p;
	
	while(q != NULL && q->codigo < codigoDisc) {
		p = q;
		q = p->proximo;
	}
	
	if (q != NULL && q->codigo == codigoDisc) {
		printf("\nDisciplina excluida com sucesso...");
		getch();
		excluirDepoisDisciplina(p);
	}		
}

void excluirAlunoOrdenado(struct professor *inicioProf, int codigoAluno, int codigoDisc) {
	struct aluno *aluno, *p, *q;
	struct disciplina *disc;
	
	disc = encontraDisciplina(inicioProf, codigoDisc);
	
	if (disc == NULL) {
		printf("\nImpossivel excluir aluno! Disciplina nao cadastrada");
		getch();
		return;
	}
	
	aluno = disc->ialuno;
	
	if (aluno->codigo == codigoAluno) {
		printf("\nAluno excluido com sucesso...");
		getch();
		excluirInicioAluno(aluno, disc);
		return;
	}
	
	p = aluno;
	q = p;
	
	while(q != NULL && q->codigo < codigoAluno) {
		p = q;
		q = p->proximo;
	}
	
	if (q != NULL && q->codigo == codigoAluno) {
		printf("\nAluno excluido com sucesso...");
		getch();
		excluirDepoisAluno(p);
	}
	else {
		printf("\nNao existe aluno com esse codigo cadastrado nessa disciplina");
		getch();
	}
}

struct professor *excluirProfessor(struct professor *inicioProf) {
	int codigo;
	
	printf("\nCodigo do Professor que deseja excluir: ");
	scanf("%d", &codigo);
	
	return excluirProfessorOrdenado(inicioProf, codigo);
}

void excluirDisciplina(struct professor *inicioProf) {
	int codigo;
	
	printf("\nCodigo da Disciplina que deseja excluir: ");
	scanf("%d", &codigo);
	
	excluirDisciplinaOrdenado(inicioProf, codigo);
}


void excluirAluno(struct professor *inicioProf) {
	int codigoAluno;
	int codigoDisc;
	
	printf("\nCodigo do Aluno que deseja excluir: ");
	scanf("%d", &codigoAluno);
	
	printf("\nCodigo da materia na qual deseja excluir: ");
	scanf("%d", &codigoDisc);
	
	excluirAlunoOrdenado(inicioProf, codigoAluno, codigoDisc);
}

struct professor *menuProfessor(struct professor *inicioProfessor) {
	int codigo;
	char nome[50];
	int tipo;
	
	printf("\nCodigo: ");
	scanf("%d", &codigo);
	
	printf("Nome: ");
	scanf("%s", &nome);
	
	printf("Tipo: ");
	scanf("%d", &tipo);
	
	return insereProfessorOrdenado(inicioProfessor, codigo, nome, tipo);	 
}

void menuDisciplina(struct professor *inicioProf) {
	int codigoProf;
	int codigoDisc;
	char nome[50];
	int numHoras;
	char curso[50];
	
	printf("\nCodigo do Professor: ");
	scanf("%d", &codigoProf);
	
	printf("Codigo Disciplina: ");
	scanf("%d", &codigoDisc);
	
	printf("Nome: ");
	scanf("%s", &nome);
	
	printf("Numero de Horas: ");
	scanf("%d", &numHoras);
	
	printf("Curso: ");
	scanf("%s", &curso);
	
	insereDisciplinaOrdenado(inicioProf, codigoProf, codigoDisc, nome, numHoras, curso);
}

void menuAluno(struct professor *inicioProf) {
   struct aluno *aluno;
		
   int codigoDisc;
   int codigo;
   char nome[50];
   float notas[2];
   
   printf("\nCodigo da Disciplina para inserir o Aluno: ");
   scanf("%d", &codigoDisc);
     
   printf("\nCodigo do Aluno: ");
   scanf("%d", &codigo);
   
   aluno = encontraAluno(inicioProf,codigo);
   if(aluno != NULL)
   {
   		printf("\nNota A1: ");
   		scanf("%f", &notas[0]);
   
   		printf("\nNota A2: ");
  		scanf("%f", &notas[1]);
  		
  		insereAlunoOrdenado(inicioProf, codigoDisc, codigo, aluno->nome, notas);
  		return;
   }
   
   printf("\nNome do Aluno: ");
   scanf("%s", &nome);
   
   printf("\nNota A1: ");
   scanf("%f", &notas[0]);
   
   printf("\nNota A2: ");
   scanf("%f", &notas[1]);
   
   insereAlunoOrdenado(inicioProf, codigoDisc, codigo, nome, notas); 						//passando o endereco de memoria de notas;
}

void mostraAlunos(struct aluno *inicio) {
	struct aluno *alunos;
	alunos = inicio;
	
	printf("\n------------- Alunos ------------");
	while(alunos != NULL) {
		printf("\nCodigo  = %d", alunos->codigo);
		printf("\nNome    = %s", alunos->nome);
		printf("\nNota A1 = %.1f", alunos->notas[0]);
		printf("\nNota A1 = %.1f", alunos->notas[1]);
		
		printf("\n");
		
		alunos = alunos->proximo;
	}
	
	printf("\n");
}

void mostraDisciplinas(struct disciplina *d) {
	struct disciplina *disc;
	disc = d;
	
	
	while(disc != NULL) {	
	
		struct aluno *aluno;
		aluno = disc->ialuno;
		
		printf("\n---------- Disciplinas ---------");	
		printf("\nCodigo Disciplina = %d", disc->codigo);
		printf("\nNome Disciplina   = %s", disc->nome);
		printf("\nNumero de Horas   = %d", disc->numHoras);
		printf("\nNome do Curso     = %s", disc->curso);
		
		printf("\n");
		
		if (aluno != NULL)
			mostraAlunos(aluno);
		
		disc = disc->proximo;
	}
}

void mostraProfessor(struct professor *inicioProf) {
	struct professor *p;
	p = inicioProf;
	
	while(p != NULL) {
		
		struct disciplina *d;
		d = p->idisciplina;
		
		printf("\n---------- DADOS PROFESSOR---------");
		printf("\nCodigo = %d", p->codigo);
		printf("\nNome   = %s", p->nome);
		printf("\nTipo   = %d", p->tipo);
		printf("\n");
		
		if (d != NULL)
			mostraDisciplinas(d);
			
		p = p->proximo;
		
		printf("\n-------------------------------------------------------- \n");
		printf("------------------ SEPARANDO PROFESSORES --------------- \n");
		printf("-------------------------------------------------------- \n");
	}	
	getch();
}
		
main() {
	
	struct professor *inicioProfessor;
	inicioProfessor = NULL;

	int op = 0;
	int op2 = 0;
	
	while(op != 5) {
		printf("********* MENU PRINCIPAL *********");		
		printf("\n\nO QUE DESEJA FAZER?");
		printf("\n1 - Incluir");
		printf("\n2 - Alterar");
		printf("\n3 - Excluir");
		printf("\n4 - Mostrar Dados");
		printf("\n5 - Sair");
		printf("\nEscolha: ");
		scanf("%d", &op);
		
		if (op == 1) {
			
			op2 = 0;
			
			system("cls");
			
			while(op2 != 4) {
				printf("\nQUEM VOCE DESEJA INCLUIR?");
				printf("\n1 - Incluir Professor");
				printf("\n2 - Incluir Disciplina");
				printf("\n3 - Incluir Aluno");
				printf("\n4 - Voltar ao menu principal");
				printf("\nEscolha: " );
				scanf("%d", &op2);
				
				if (op2 == 1) {
					inicioProfessor = menuProfessor(inicioProfessor);
					system("cls");
				}
				
				else if (op2 == 2) {
					menuDisciplina(inicioProfessor);
					system("cls");
				}
				
				else if (op2 == 3) {
					menuAluno(inicioProfessor);
					system("cls");
				}
				
				else if(op2 == 4){
					system("cls");
				}
				else {
					printf("\nOpercao Invalida");
					getch();
					system("cls");
				}
			}
		}
		
		else if (op == 2) {
			
			op2 = 0;
			
			system("cls");
			
			while(op2 != 4) {
				printf("\nQUEM VOCE DESEJA ALTERAR?");
				printf("\n1 - Alterar Professor");
				printf("\n2 - Alterar Disciplina");
				printf("\n3 - Alterar Aluno");
				printf("\n4 - Voltar ao menu principal");
				printf("\nEscolha: " );
				scanf("%d", &op2);
				
				if (op2 == 1) {
					alteraProfessor(inicioProfessor);
					system("cls");
				}
				
				else if (op2 == 2) {
					alteraDisciplina(inicioProfessor);
					system("cls");
				}
				
				else if (op2 == 3) {
					alteraAluno(inicioProfessor);
					system("cls");
				}
				
				else if(op2 == 4){
					system("cls");
				}
				
				else {
					printf("\nOpercao Invalida");
					getch();
					system("cls");
				}
			}
		}
		
		else if (op == 3) {
			
			op2 = 0;
			
			system("cls");
			
			while (op2 != 4) {
				printf("\nQUEM VOCE DESEJA EXCLUIR?");
				printf("\n1 - Excluir Professor");
				printf("\n2 - Excluir Disciplina");
				printf("\n3 - Excluir Aluno");
				printf("\n4 - Voltar ao menu principal");
				printf("\nEscolha: " );
				scanf("%d", &op2);
				
				if (op2 == 1) {
					inicioProfessor = excluirProfessor(inicioProfessor);
					system("cls");
				}
				
				else if (op2 == 2) {
					excluirDisciplina(inicioProfessor);
					system("cls");
				}
				
				else if (op2 == 3) {
					excluirAluno(inicioProfessor);
					system("cls");
				}
			
				else if(op2 == 4){
					system("cls");
				}
				
				else {
					printf("\nOpercao Invalida");
					getch();
					system("cls");
				}
			}
		}
		
		else if (op == 4) {
			mostraProfessor(inicioProfessor);
			system("cls");
		}
		
		else if (op == 5) {
			printf("\nSaindo do Programa");
			getch();
			system("cls");
		}
		
		else {
			printf("\nOpercao Invalida");
			getch();
			system("cls");
		}
	}	
}
