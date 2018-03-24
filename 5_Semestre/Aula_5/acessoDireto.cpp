// Acesso direto em arquivos binários
//fgetc fprintf fgets fscanfs fopen fclose
#include <stdio.h>

struct sreg {
	int cod;
	float sal;
	char sta; 	//'a' = ativo 'i' = inativo;
	
};

FILE *arq;

void inserir() {
	sreg reg;
	
	reg.cod = 10;
	reg.sal = 5000;
	reg.sta = 'A';
	
	//gravar vetor fwrite(vet, sizeof(vet), 1) || fwrite(vet, sizeof(int), 100); 
	
	fwrite(&reg, sizeof(sreg), 1, arq);
	printf("Dados inseridos");
}

void ler() {
	sreg reg;
	
//	fread(&reg, sizeof(sreg), 1, arq);	 		// vai no arquivo, le um registro e joga no &reg;
	
	fread(&reg, sizeof(sreg), 1, arq);
	printf("\n%d  r$ %.2f  %c", reg.cod, reg.sal, reg.sta);
}

main() {
	
	//sreg reg;//
	
	arq = fopen("dados.dat", "rb+");
	if (arq == NULL)
		arq = fopen("dados.dat", "wb+");	//se o arquivo nao existir ele vai criar;
	
//	fseek(arq, 0, SEEK_END); 				// posiciona o ponteiro no final do arquivo;
	fseek(arq, 2 * sizeof(sreg), SEEK_SET);	// posicao inicial - para alterar terceiro valor um valor 
//	inserir();
	
	ler();
	ler();
	ler();
	ler();
	
	//inserir();
	//printf("%d", sizeof(sreg));
	
	fclose(arq);
	
	printf("\n\nFim...");
	getchar();
}
