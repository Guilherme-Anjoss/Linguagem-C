
/***************************************************************
Trabalho Computacional � Programa��o II � 2022/1 � Ci�ncia/Engenharia da Computa��o
Grupo: <Calebe Carias Degen�rio> e <Guilherme Lima dos Anjos>
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printa_menu(){ //Fun��o para imprimir o menu de op��es na tela
    system("cls");//Limpa a tela
    printf("1-Criar Arquivo\n"); //Printa primeira op��o
    printf("2-Escrever Frase\n"); //Printa segunda op��o
    printf("3-Sair\n"); //Printa terceira op��o
}

int main() {
	FILE *arq; //Inicializa variavel que recebe o arquivo
	char nomeArquivo[30],c,frase[100];

	int opcao;

	printa_menu();//Chama a fun��o para imprimir o menu
	scanf("%d",&opcao);//Pega a op��o selecionada pelo usuario
	while(opcao != 3){ // Cria la�o enquanto o usuario n�o escolher a op��o de saida
        if(opcao == 1){ //Verifica se a op��o escolhida foi 1
            printf("Digite o nome do arquivo: "); //Pede o nome do arquivo que ser� criado
            scanf("%s", nomeArquivo); // Armaneza na variavel nomeArquivo
            arq = fopen (nomeArquivo, "wt"); //Abre o arquivo
            if (arq==NULL) { //Verifica se foi possivel abrir o arquivo
                printf("N�o foi possivel abrir o arquivo.");
                exit(1);
	}
        }
        else if(opcao == 2){//Verifica se a op��o escolhida foi 2
            printf("Digite a frase: "); //Pede a frase que sera escrita
            scanf("%c");
            fgets(frase,100,stdin); // Armaneza na variavel frase
            fwrite(frase,1,strlen(frase),arq); //Escreve a frase no arquivo
        }
        else{
            printf("Op��o invalida!");
        }
        printa_menu();//Chama a fun��o para imprimir o menu novamente
        scanf("%d",&opcao);//Pega a op��o selecionada pelo usuario
	}
	fclose(arq); //Fecha o arquivo

	return 0;
}


