
/***************************************************************
Trabalho Computacional – Programação II – 2022/1 – Ciência/Engenharia da Computação
Grupo: <Calebe Carias Degenário> e <Guilherme Lima dos Anjos>
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printa_menu(){ //Função para imprimir o menu de opções na tela
    system("cls");//Limpa a tela
    printf("1-Criar Arquivo\n"); //Printa primeira opção
    printf("2-Escrever Frase\n"); //Printa segunda opção
    printf("3-Sair\n"); //Printa terceira opção
}

int main() {
	FILE *arq; //Inicializa variavel que recebe o arquivo
	char nomeArquivo[30],c,frase[100];

	int opcao;

	printa_menu();//Chama a função para imprimir o menu
	scanf("%d",&opcao);//Pega a opção selecionada pelo usuario
	while(opcao != 3){ // Cria laço enquanto o usuario não escolher a opção de saida
        if(opcao == 1){ //Verifica se a opção escolhida foi 1
            printf("Digite o nome do arquivo: "); //Pede o nome do arquivo que será criado
            scanf("%s", nomeArquivo); // Armaneza na variavel nomeArquivo
            arq = fopen (nomeArquivo, "wt"); //Abre o arquivo
            if (arq==NULL) { //Verifica se foi possivel abrir o arquivo
                printf("Não foi possivel abrir o arquivo.");
                exit(1);
	}
        }
        else if(opcao == 2){//Verifica se a opção escolhida foi 2
            printf("Digite a frase: "); //Pede a frase que sera escrita
            scanf("%c");
            fgets(frase,100,stdin); // Armaneza na variavel frase
            fwrite(frase,1,strlen(frase),arq); //Escreve a frase no arquivo
        }
        else{
            printf("Opção invalida!");
        }
        printa_menu();//Chama a função para imprimir o menu novamente
        scanf("%d",&opcao);//Pega a opção selecionada pelo usuario
	}
	fclose(arq); //Fecha o arquivo

	return 0;
}


