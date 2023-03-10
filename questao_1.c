/***************************************************************
Trabalho Computacional – Programação II – 2022/1 – Ciência/Engenharia da Computação
Grupo: Calebe Carias Degenário e Guilherme Lima dos Anjos
***************************************************************/
#include <stdio.h>

typedef struct lista_Livros {
// Estrutura que vai receber os dados dos livros
    int cod_livro;
    char nome_livro[100];  //vetor de caracteres que recebe o nome
    char nome_autor[100];  //vetor de caracteres que recebe o autor
    char editora[100];     //vetor de caracteres que recebe a editora
    int cod_area;
    int num_pag;

}LIVRO;

void Imprime_Dados(LIVRO lista_Livros[3]){
/* -Essa função vai ser responsável por imprimir os dados na tela.
   -Ela recebe como parâmetro o vetor de struct com os dados dos livros.
   -Utiliza laço 'for' para percorrer o vetor com os dados.
   -Analisa se o código do livro existe ou não, se não existe aparece um aviso na tela
   e pede para digitar novamente.
*/
    int codigo = 0, i, j, cont = 0;
    while(codigo != -1)
    {
        printf("Digite o código do livro: ");
        scanf("%d", &codigo);
        printf("\n=================================================================================================================\n");
        if(codigo != -1)
        {
            cont = 0;
            for(i = 0; i < 3; i++)
            {
                if(codigo == lista_Livros[i].cod_livro)
                {
                    cont++;
                    j = i;
                    printf("===\n");
                    printf("Código do livro: %d", lista_Livros[j].cod_livro);
                    printf("\nNome: %s", lista_Livros[j].nome_livro);
                    printf("\nAutor: %s", lista_Livros[j].nome_autor);
                    printf("\nEditora: %s", lista_Livros[j].editora);
                    printf("\nCódigo da área: %d", lista_Livros[j].cod_area);
                    printf("\nNúmero de páginas: %d", lista_Livros[j].num_pag);
                    printf("\n===\n");
                    printf("=================================================================================================================\n");
                    printf("\n");
                }
            }
            if(cont == 0){
                printf("Código não encontrado!\n");
            }
        }
    }
}

void Paginas(LIVRO lista_Livros[3]){
/* -Essa função vai receber o vetor de struct com os dados dos livros como parâmetro.
   -Ela é responsável por analisar quais livros tem entre 100 e 300 páginas.
   -Utiliza um laço 'for' para percorrer os dados de cada livro que estão no vetor.
   -No fim vai imprimir na tela a quantidade de livros que tem entre 100 e 300 páginas.
*/
    int cont = 0, i;
    for(i = 0; i < 3; i++)
    {
        if((lista_Livros[i].num_pag > 100) && (lista_Livros[i].num_pag < 300))
        {
            cont++;
        }
    }
    printf("\n=================================================================================================================\n");
    printf("Um total de %d livro(s) tem o número de páginas entre 100 e 300.\n", cont);
    printf("=================================================================================================================");


}

int main(){
/* -Função main, é a função central e vai ser responsável por ler os dados
   dos livros e coloca-los em um vetor de struct e chamar as funções anteriores.
   -Utiliza laço 'for' para percorrer o vetor e inserir os dados, e 'while' para verificar
    os dados e repetir inserção deles se forem inválidos.
*/
    int i;
    struct lista_Livros func[3];
    for(i=0; i<3; i++)
    {
        printf("%dº Livro\n", i+1);
        printf("Código do Livro: ");
        scanf("%d", &func[i].cod_livro);
        while(func[i].cod_livro <= 0)
        {
            printf("Valor inválido! Digite novamente: ");
            scanf("%d", &func[i].cod_livro);
        }
        printf("Nome: ");
        scanf(" %[^\n]s", func[i].nome_livro);
        printf("Autor: ");
        scanf(" %[^\n]s", func[i].nome_autor);
        printf("Editora: ");
        scanf(" %[^\n]s", func[i].editora);
        printf("Código da área(1- Ciências exatas, 2-Ciências humanas, 3-Ciências biomédicas): ");
        scanf("%d", &func[i].cod_area);
        while(func[i].cod_area <= 0 || func[i].cod_area > 3)
        {
            printf("Valor inválido! Digite novamente: ");
            scanf("%d", &func[i].cod_area);
        }
        printf("Número de páginas: ");
        scanf("%d", &func[i].num_pag);
        while(func[i].num_pag <= 0)
        {
            printf("Valor inválido! Digite novamente: ");
            scanf("%d", &func[i].num_pag);
        }
        printf("\n=================================================================================================================\n");
    }
    Imprime_Dados(func);
    Paginas(func);
    return 0;

}
