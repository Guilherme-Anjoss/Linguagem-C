
/***************************************************************
Trabalho Computacional � Programa��o II � 2022/1 � Ci�ncia/Engenharia da Computa��o
Grupo: <Calebe Carias Degen�rio> e <Guilherme Lima dos Anjos>
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printa_menu(){ //Fun��o para imprimir o menu de op��es na tela
    system("cls");//Limpa a tela
    printf("1-Escrever palavra\n"); //Printa primeira op��o
    printf("2-Listar palavras\n"); //Printa segunda op��o
    printf("3-Sair\n"); //Printa terceira op��o
}

int main() {
	FILE *arq; //Inicializa variavel que recebe o arquivo
	char nomeArquivo[30],palavra[100]; //Inicializa variavel para coletar nome do arquivo e a palavra digitada
	int i,j;

    printf("Digite o nome do arquivo: "); //Pede o nome do arquivo que ser� criado
    scanf("%s", nomeArquivo); // Armaneza na variavel nomeArquivo
    arq = fopen (nomeArquivo, "w"); //Abre o arquivo

    if (arq==NULL) { //Verifica se foi possivel abrir o arquivo
        printf("N�o foi possivel abrir o arquivo.");
        exit(1);
	}
    printf("Digite a cadeia de caracteres: "); //Pede a cadeia de caracteres
    scanf("%c");
    gets(palavra); // Armaneza na variavel palavra

    for(i = strlen(palavra);i>0;i--){ //For para percorrer toda a palavra
        for(j=0;j<i;j++){ //For para digitar as palavras em formado de 'escada'
            fputc(palavra[j],arq); //Coloca o caracter no arquivo
        }
        fputc('\n',arq); //Da um enter no arquivo apos digitar os caracteres
    }

	fclose(arq); //Fecha o arquivo

	return 0;
}
