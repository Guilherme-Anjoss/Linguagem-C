/***************************************************************
Trabalho Computacional – Programação II – 2022/1 – Ciência/Engenharia da Computação
Grupo: <Calebe Carias Degenário> e <Guilherme Lima dos Anjos>
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printa_vetor(int vetor[],char alfabeto[]){ //Função para imprimir o vetor na tela
    int i; //Declaração da variavel i
    for(i = 0; i < 26; i++){ //Laço para percorrer os dois vetores
        printf("%c - %d\n", alfabeto[i],vetor[i]); //Imprime a letra e sua frequencia na posição i
    }
}


int posicao(char c){ //Função para descobrir a qual letra o caractere corresponde e retornar sua posição
    c = tolower(c); //Passa o caractere para minusculo já que não a diferença entre maiusculo e minusculo nesse exercicio
    int i;
    char alfabeto[26] = {"abcdefghijklmnopqrstuvwxyz"}; //Declaração de String alfabeto para servir de comparação com o caracter
    for(i=0;i<26;i++){ //Percorre a string alfabeto
        if(alfabeto[i]==c){ //Verifica se o caractere é igual a alguma letra do alfabeto
            return i; //Se for retorna a posição daquela letra
        }
    }
    return " "; //Caso o programa não encontre nenhuma letra correspondente retorna vazio
}

int main()
{
    FILE* arq;



    char nome_arq[40]; // Declaração da Variavel para receber o nome do arquivo que vai ser lido
    int contador[26],i,j,pos,aux; //Declaração da Variavel Contador para armezenar a frequencia de cada letra
    char alfabeto[26] = {"abcdefghijklmnopqrstuvwxyz"};//Declaração de String alfabeto
    for(i=0;i<26;i++){
        contador[i] = 0; //Inicializa o contador colocando zero em todas as suas posiçoes
    }

    char c; //Para ler os caracteres

    printf("Digite o nome do arquivo: "); //Pega o nome do arquivo para ser lido do usuario
    scanf("%s", nome_arq);// Armazena na variavel nome_arq

    arq = fopen(nome_arq, "r");//Abre o arquivo

    if (arq == NULL) { //Checa se o arquivo existe
        printf("Não foi possivel abrir o arquivo %s",nome_arq);
        return 0;
    }

    c=getc(arq); //Pega o primeiro caractere do arquivo
	while (c!=EOF){ //Laço enquanto a variavel c não identificar o final do arquvio
        pos = posicao(c); //Chamada da função posição
        if(pos != " "){ //Verifica se a função não retornou vazio
            contador[pos] += 1; //Soma um no contador na posição correspondente a sua letra
        }

		c=getc(arq); //Le o proximo caractere
	}
    fclose(arq); //Fecha o arquivo
    //Ordenar o vetor de forma decrescente
    for (i = 0; i < 26; i++){ //Criação de um for para percorrer a lista
        for (j = i; j < 26; j++){ //Outro for para comparar com as posições seguintes
            if (contador[i] < contador[j]){ //Se o numero for menor que o proximo que estamos comparando
                aux = contador[i]; // Armazena o número
                contador[i] = contador[j]; // Traz o numero maior para 'frente'
                contador[j] = aux; // E o substitui pelo numero menor

                aux = alfabeto[i]; //Faz o mesmo processo com a string alfabeto para podermos manter a relação entre a posição e a letra
                alfabeto[i] = alfabeto[j];
                alfabeto[j] = aux;
            }
        }
    }

    printa_vetor(contador,alfabeto); // Chama a função para imprimir o vetor


    return 0;
}
