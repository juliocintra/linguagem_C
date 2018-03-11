/*
	Arquivos binarios - Criptografia
	Execução do programa pelo terminal;
*/

#include <stdio.h>
#include <string.h>

main(int argc, char *argv[]) {
	
	FILE *ent, *sai;
	char byte, arqsai[101];
	
	if (argc != 3)											// tem que ter 3 parametros
		printf("\ncript <arquivo> <senha>\n\n");
	else {
		ent = fopen(argv[1], "rb");							// rb pega binario; pq vai ler byte a byte
		
		if (ent == NULL)
			printf("\n\nArquivo inexistente...\n");
		else {
			strcpy(arqsai, argv[1]);						//copia o nome do arquivo;
			
			if (arqsai[strlen(arqsai) - 1] == 'x')
				arqsai[strlen(arqsai) - 2] = '\0';			//elimina o '.x';
			else
				strcat(arqsai, ".x");
			
//			strcat(arqsai, ".x");										//concatena as strings;
			
//			sai = fopen("saida.x", "wb");					//escrita binario
			
			sai = fopen(arqsai, "wb");
			
			byte = fgetc(ent);
			while(!feof(ent)) {
				byte = ~(byte ^ argv[2][0]); // ^ XOT :: ~ NOT
				fputc(byte, sai);
				byte = fgetc(ent);
				
			}
			
			fclose(ent);
			fclose(ent);
			
			remove(argv[1]) ;			//exclui o arquivo original
			
			printf("\nProcessado");
		}
	}
}
