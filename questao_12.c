
/***************************************************************
Trabalho Computacional – Programação II – 2022/1 – Ciência/Engenharia da Computação
Grupo: <Calebe Carias Degenário> e <Guilherme Lima dos Anjos>
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printa_menu(){ //Função para imprimir o menu de opções na tela
    system("cls");//Limpa a tela
    printf("1-Escrever palavra\n"); //Printa primeira opção
    printf("2-Listar palavras\n"); //Printa segunda opção
    printf("3-Sair\n"); //Printa terceira opção
}

int main() {
	FILE *arq; //Inicializa variavel que recebe o arquivo
	char nomeArquivo[30],palavra[100]; //Inicializa variavel para coletar nome do arquivo e a palavra digitada
	int i,j;

    printf("Digite o nome do arquivo: "); //Pede o nome do arquivo que será criado
    scanf("%s", nomeArquivo); // Armaneza na variavel nomeArquivo
    arq = fopen (nomeArquivo, "w"); //Abre o arquivo

    if (arq==NULL) { //Verifica se foi possivel abrir o arquivo
        printf("Não foi possivel abrir o arquivo.");
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
