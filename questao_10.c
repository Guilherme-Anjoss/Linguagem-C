
/***************************************************************
Trabalho Computacional � Programa��o II � 2022/1 � Ci�ncia/Engenharia da Computa��o
Grupo: <Calebe Carias Degen�rio> e <Guilherme Lima dos Anjos>
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int palindromo(char palavra[]){
    int tamanho = strlen(palavra); // Cria uma variavel para descobrir o tamanho da palavra
    char invertida[tamanho]; //Cria uma string do mesmo tamanho da palavra
    int i;
     for(i = 0; palavra[i]; i++){
        palavra[i] = tolower(palavra[i]); // Passa toda a palavra para minusculo para n�o ter problemas na hora da compara��o
    }
    if(palavra[tamanho - 1] = '\n'){ //Verifica se o ultimo caracter da string � um \n
        palavra[tamanho - 1] = 0; // Remove o \n na string para n�o ter problemas na compara��o
    }
    strcpy(invertida, palavra); //Copia a palavra
    strrev(invertida); //Inverte a palavra
    return  strcmp(palavra, invertida); //Retorna a compara��o das duas strings

}

void printa_menu(){ //Fun��o para imprimir o menu de op��es na tela
    system("cls");//Limpa a tela
    printf("1-Escrever palavra\n"); //Printa primeira op��o
    printf("2-Listar palavras\n"); //Printa segunda op��o
    printf("3-Sair\n"); //Printa terceira op��o
}

int main() {
	FILE *arq; //Inicializa variavel que recebe o arquivo
	char nomeArquivo[30],palavra[100];
	char *result;

	int opcao,check; // Inicializa variavel para receber a op��o selecionada pelo usuario

    printf("Digite o nome do arquivo: "); //Pede o nome do arquivo que ser� criado
    scanf("%s", nomeArquivo); // Armaneza na variavel nomeArquivo
    arq = fopen (nomeArquivo, "w"); //Abre o arquivo

    if (arq==NULL) { //Verifica se foi possivel abrir o arquivo
        printf("N�o foi possivel abrir o arquivo.");
        exit(1);
	}

	printa_menu();//Chama a fun��o para imprimir o menu
	scanf("%d",&opcao);//Pega a op��o selecionada pelo usuario

	while(opcao != 3){ // Cria la�o enquanto o usuario n�o escolher a op��o de saida
        if(opcao == 1){ //Verifica se a op��o escolhida foi 1
            printf("Digite a palavra: "); //Pede a palavra que sera escrita
            scanf("%c");
            gets(palavra); // Armaneza na variavel palavra
            strcat (palavra, "\n");
            fwrite(palavra,1,strlen(palavra),arq); //Escreve a palavra no arquivo
            printa_menu();//Chama a fun��o para imprimir o menu novamente
            scanf("%d",&opcao);//Pega a op��o selecionada pelo usuario
        }
        else if(opcao == 2){//Verifica se a op��o escolhida foi 2
            fclose(arq);
            arq = fopen (nomeArquivo, "r"); //Abre o arquivo

            if (arq==NULL) { //Verifica se foi possivel abrir o arquivo
            printf("N�o foi possivel abrir o arquivo.");

            }
            result = fgets(palavra, 100, arq);  //Le a primeira palavra do arquivo
            while(result != NULL){ //Enquanto a palavra n�o for nula
                check =  palindromo(palavra); // Chama a fun��o para verificar se a palavra � um palindromo
                if(check == 0){ //Verifica se a palavra � um palindromo
                    printf("%s - e um palindromo\n",palavra); //printa o resultado
                }
                else{
                   printf("%s - nao e um palindromo\n",palavra);
                }

                result = fgets(palavra, 100, arq); //Pega a proxima palavra do arquivo
            }
            exit(1); //Sai do programa

            }


        else{
            printf("Op��o invalida!");
        }
	}
	fclose(arq); //Fecha o arquivo

	return 0;
}

