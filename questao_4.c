/***************************************************************
Trabalho Computacional – Programação II – 2022/1 – Ciência/Engenharia da Computação
Grupo: Calebe Carias Degenário e Guilherme Lima dos Anjos
***************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int quant, i, multiplo = 7;
    
    FILE *arq; // Cria o panteiro de arquivo.
    arq = fopen("multiplos7.txt", "w"); // Abre/cria o arquivo do tipo .txt e faz o ponteiro apontar para ele.
     
    if(arq == NULL){ // Analisa se o arquivo foi aberto ou não.
        printf("Erro! O arquivo não foi aberto.\n");
        exit(1);
    }else{
        printf("Arquivo criado com sucesso!\n");
    }
    
    printf("Digite quantos valores você quer inserir no arquivo: ");
    scanf("%d", &quant); // Limite de valores que aparecerão no arquivo.
    
    printf("Inserindo %d multiplos de 7 no arquivo...", quant);
    
    for(i = 0; i < quant; i++){ // Vai multiplicando a variável 'multiplo' que tem o valor 7 por 'i'.
        fprintf(arq,"%d\n", multiplo * i); // Imprime os resultados no arquivo que foi criado.
    }
    
    fclose(arq); //Fecha arquivo.
     return 0;
 }