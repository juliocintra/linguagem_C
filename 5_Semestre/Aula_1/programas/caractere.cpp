/* Arquivos ASCII (texto)
	 Ler dados caractere por caractere.
*/

#include <stdio.h>
#include <windows.h>

main()
{
	FILE *arq;
	char nomearq[101], crt;
	
	printf("Nome do arquivo: ");
	gets(nomearq);
	
	arq = fopen(nomearq, "r"); //abrir arquivo leitura texto (r)
	
	if (arq == NULL) // NULL indica que n�o abriu
		printf("\nERRO ao abrir o arquivo!!");
	else
	{
		crt = fgetc(arq); // l� um caractere do arquivo
		while (!feof(arq)) // verifica se n�o chegou ao final ->> se retornar zero quer dizer fim do arquivo
		{
			printf("%c", crt);
			Sleep(2);	
			
			crt = fgetc(arq); // l� novamente	->> lendo o proximo caractere
		}
/*
		while ((crt = fgetc(arq)) != EOF) // l� e verifica se n�o chegou ao final
		{
			printf("%c", crt);
			Beep(1000, 50);	
		}

*/		
		fclose(arq); // fecha o arquivo
	}
	
	getchar();
}

