/* Arquivos ASCII (texto)
	 Abrir, Fechar e Ler dados.
*/

#include <stdio.h>
#include <windows.h>

main()
{	
	FILE *arq;									//criando um ponteiro do tipo FILE
	char nomearq[101], linha[255];
	int a = 1;
	printf("Nome do arquivo: ");
	gets(nomearq);								// gets copia a sequencia de caracteres no buffer
	
	arq = fopen(nomearq, "r"); 					//abrir arquivo leitura texto (r) --> retrorna o endereço de memoria
	printf("%d", arq);
	
	if (arq == NULL) // NULL indica que não abriu
		printf("\nERRO ao abrir o arquivo!!");
	else
	{
		while (fgets(linha, 255, arq) != NULL) // lê uma linha do arquivo
		{
			printf("%s", linha);
			Sleep(300);
		}
		
		fclose(arq); // fecha o arquivo
	}
	
	getchar();
}

