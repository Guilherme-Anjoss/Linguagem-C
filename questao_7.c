
/***************************************************************
Trabalho Computacional – Programação II – 2022/1 – Ciência/Engenharia da Computação
Grupo: <Calebe Carias Degenário> e <Guilherme Lima dos Anjos>
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *arq; //Inicializa variavel que recebe o arquivo
	char nomeArquivo[30],resposta,c;
	int i, j;
	printf("Digite o nome do arquivo: "); //Pede o nome do arquivo que será criado
	scanf("%s", nomeArquivo); // Armaneza na variavel nomeArquivo
	arq = fopen (nomeArquivo, "wt"); //Abre o arquivo

	if (arq==NULL) { //Verifica se foi possivel abrir o arquivo
		printf("Não foi possivel abrir o arquivo.");
		exit(1);
	}

	for (i=1;i<10;i++) { // Inicializa um laço que vai de 1 até o numero 10
		for (j=1;j<11;j++) { // Inicializa um laço que vai de 1 até o numero 11
			fprintf(arq, "%d * %d = %d ",i,j,i*j); //Imprime no arquivo os números que estão sendo multiplicados e o seu resultado
	}
        fprintf(arq, "\n"); // Quebra a linha para a proxima tabuada
	}

	fclose(arq); //Fecha o arquivo
	printf("Imprimir resultados?(s/n)"); //Verifica se o usuario quer que imprima os resultados
	scanf("%c");
	scanf("%c",&resposta);
	if(resposta == 's'){
        arq = fopen (nomeArquivo, "rt"); //Abre o arquivo

        if (arq==NULL) {//Verifica se foi possivel abrir o arquivo
            printf("Não foi possivel abrir o arquivo.");
            exit(1);
        }
        c = getc(arq); //Pega o primeiro caracter do arquivo
        while (c!=EOF){ //Laço enquanto não foi identificado o fim do arquivo
            printf("%c", c); //Printa na tela o caracter
            c=getc(arq); //Pega o proximo caracter
	}
	}

	return 0;
}

