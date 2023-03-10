
/***************************************************************
Trabalho Computacional � Programa��o II � 2022/1 � Ci�ncia/Engenharia da Computa��o
Grupo: <Calebe Carias Degen�rio> e <Guilherme Lima dos Anjos>
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *arq; //Inicializa variavel que recebe o arquivo
	char nomeArquivo[30],resposta,c;
	int i, j;
	printf("Digite o nome do arquivo: "); //Pede o nome do arquivo que ser� criado
	scanf("%s", nomeArquivo); // Armaneza na variavel nomeArquivo
	arq = fopen (nomeArquivo, "wt"); //Abre o arquivo

	if (arq==NULL) { //Verifica se foi possivel abrir o arquivo
		printf("N�o foi possivel abrir o arquivo.");
		exit(1);
	}

	for (i=1;i<10;i++) { // Inicializa um la�o que vai de 1 at� o numero 10
		for (j=1;j<11;j++) { // Inicializa um la�o que vai de 1 at� o numero 11
			fprintf(arq, "%d * %d = %d ",i,j,i*j); //Imprime no arquivo os n�meros que est�o sendo multiplicados e o seu resultado
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
            printf("N�o foi possivel abrir o arquivo.");
            exit(1);
        }
        c = getc(arq); //Pega o primeiro caracter do arquivo
        while (c!=EOF){ //La�o enquanto n�o foi identificado o fim do arquivo
            printf("%c", c); //Printa na tela o caracter
            c=getc(arq); //Pega o proximo caracter
	}
	}

	return 0;
}

