/***************************************************************
Trabalho Computacional – Programação II – 2022/1 – Ciência/Engenharia da Computação
Grupo: Calebe Carias Degenário e Guilherme Lima dos Anjos
***************************************************************/
#include <stdio.h>

typedef struct Produtos{
// Estrutura que vai receber os dados dos produtos.
  int codigo;
  int quantidade;
  float preco;
}PROD;

void Imprime_Dados(PROD produtos[15]){
/* -Função que vai ser responsável por imprimir os dados dos produtos na tela.
   -Utiliza um 'While' para analisar se o código do livro é válido ou se o usuário que encerrar a consulta.
   -Utiliza laço 'for' para percorrer o vetor com os dados.
*/
    int codigo = 0, i, j, cont = 0;
    while(codigo != -1)
    {
        printf("\n============================================\n");
        printf("Digite o código do produto: ");
        scanf("%d", &codigo);
        printf("\n============================================\n");
        if(codigo != -1)
        {
            cont = 0;
            for(i = 0; i < 15; i++)
            {
                if(codigo == produtos[i].codigo)
                {
                    cont++;
                    j = i;
                    printf("Código: %d", produtos[j].codigo);
                    printf("\nQuantidade: %d", produtos[j].quantidade);
                    printf("\nPreço: %.2f", produtos[j].preco);
                    printf("\n");
                }
            }
            if(cont == 0){
                printf("Código não encontrado! Digite novamente.\n");
            }
        }
    }
}

void Acima_de_15(PROD produtos[15]){
/* -Função responsável por analisar quais produtos tem o preço acima de R$15,00.
   -Recebe como parâmetro o vetor de struct com os dados dos produtos.
   -Percorre o vetor de dados com um laço 'for'.
*/
    int i, cont = 0;
    printf("\nProdutos com o preço acima de R$15,00:\n");
    for(i = 0; i < 15; i++){
        if(produtos[i].preco > 15.00){
            printf("Código: %d", produtos[i].codigo);
            printf("\nQuantidade: %d", produtos[i].quantidade);
            printf("\nPreço: %.2f", produtos[i].preco);
            printf("\n");
        }else{
            cont++;
            if(cont == 15){
                printf("Nenhum!");
            }
        }
    }
    
    
}

void media_acima_de_10(PROD produtos[15]){
/* -Função responsável por cálcular a média de preço dos produtos que custam mais de R$10,00.
   -Recebe como parâmetro o vetor de struct com os dados dos produtos.
   -Percorre o vetor de dados com um laço 'for'.
   -Utiliza uma variável 'somaPreco' para ir somando os preços dentro do 'for'.
   -No final divide o valor da 'somaPreco' pelo número de produtos que custam R$10,00.
   -Utiliza a variável contadora 'cont' para contar os produtos.
*/
    int i;
    float media, somaPreco, cont = 0.0;
    printf("\nProdutos com preço acima de R$10,00:\n");
    for(i = 0; i < 15; i++){
        if(produtos[i].preco > 10.00){
            printf("Código: %d", produtos[i].codigo);
            printf("\nQuantidade: %d", produtos[i].quantidade);
            printf("\nPreço: %.2f", produtos[i].preco);
            printf("\n");
            somaPreco = somaPreco + produtos[i].preco;
            cont = cont + 1.0;
        }
    }
    media = somaPreco / cont;
    printf("\nMédia de preço dos produtos acima de R$10,00: %.2f", media);
}

int main(){
/* -Função main, é a função central que é responsável por receber os dados dos produtos.
   -Função que chama as funções anteriores.
*/
    int i, j, cont = 0;
    struct Produtos func[15];
    for(i = 0; i < 15; i++)
    {
        printf("Insira as informações do produto\n");
        printf("Código: ");
        scanf("%d", &func[i].codigo);
        printf("Quantidade: ");
        scanf(" %d", &func[i].quantidade);
        printf("Preço: ");
        scanf("%f", &func[i].preco);
        
    }
    Imprime_Dados(func);
    Acima_de_15(func);
    media_acima_de_10(func);
    return 0;
}