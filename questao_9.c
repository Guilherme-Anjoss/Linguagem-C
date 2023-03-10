/***************************************************************
Trabalho Computacional – Programação II – 2022/1 – Ciência/Engenharia da Computação
Grupo: Calebe Carias Degenário e Guilherme Lima dos Anjos
***************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq = fopen("Frases.txt", "r"); // Cria ponteiro que aponta para um arquivo e abre o arquivo já criado para fazer a leitura.
    char frase[1000]; // Vetor de caracteres que vai conter cada frase.
    
    if(arq == NULL){ // Analiza se o arquivo foi aberto ou não.
        printf("Não foi possível abrir o arquivo!");
        exit(1);
    }
    
    while(fgets(frase, 1000, arq) != NULL){ // Adiciona caracteres da linha do arquivo de texto no vetor.
        printf("%s", frase); // Imprime na tela a frase armazenada no vetor.
    }
    
    fclose(arq); // Fecha o arquivo.
    return 0;
}