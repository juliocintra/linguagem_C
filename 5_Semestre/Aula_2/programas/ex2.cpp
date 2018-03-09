/* Ler valores num�ricos de um arquivo texto. 02/03/2018
*/

#include <stdio.h>

main()
{
	FILE *arq;
	char nomearq[101];
	float valor, soma;
	
	printf("Nome do arquivo: ");
	gets(nomearq);
	
	arq = fopen(nomearq, "r"); //abrir arquivo leitura texto (r)
	
	if (arq == NULL) // NULL indica que n�o abriu
		printf("\nERRO ao abrir o arquivo!!");
	else
	{
		soma = 0;
		while (fscanf(arq, "%f", &valor) != EOF)
		{
			soma = soma + valor;	
		}

		printf("\nSoma = %.3f", soma);
		
		fclose(arq); // fecha o arquivo
	}
	
	getchar();
}

