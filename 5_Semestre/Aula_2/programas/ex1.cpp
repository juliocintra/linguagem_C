/* Ler caractere por caractere e escrever em outro arquivo.
*/

#include <stdio.h>

main()
{
	FILE *ent, *sai;
	char nomearq[101], crt;
	
	printf("Nome do arquivo: ");
	gets(nomearq);
	
	ent = fopen(nomearq, "r"); //abrir arquivo leitura texto (r)
	
	if (ent == NULL) // NULL indica que não abriu
		printf("\nERRO ao abrir o arquivo!!");
	else
	{
		sai = fopen("saida.txt", "w");
		
		fprintf(sai, "Processamento dos dados...\n\n");
		fprintf(sai, "teste para entender o programa \n\n");		// fprintf grava novos dados no arquivo criado
		while ((crt = fgetc(ent)) != EOF)
		{
			if (crt == 'a' || crt == 'A')
				fputc('@', sai);
			else
				fputc(crt, sai);	
		}
		
		fclose(ent); // fecha o arquivo de entrada
		fclose(sai); // fecha o arquivo de saída
	}
	
	printf("\n\nFim...");
	getchar();
}

