/***************************************************************
Trabalho Computacional – Programação II – 2022/1 – Ciência/Engenharia da Computação
Grupo: Calebe Carias Degenário e Guilherme Lima dos Anjos
***************************************************************/
#include <stdio.h>

/* Estrutura que vai receber as informações dos funcionários*/
struct Funcionarios
{
    int matricula;
    char nome[100];   //vetor de caracteres para receber o nome do funcionário.
    int admissao_dia;
    int admissao_mes;
    int admissao_ano;
    float salario;
};

int main(){
    int i, j, anoAtual = 2022, cont=0;
    float somaSalario = 0, media_salarial = 0;
    struct Funcionarios func[10];  // Chamada da estrutura para manipular os dados dela dentro de um vetor de struct 
    /* Estrutura de repetição que vai possibilitar a leitura dos dados de todos os funcionários
       e inserir os dados um um vetor de struct
    */
    for(i = 0; i < 10; i++) 
    {
        printf("Insira os dados do funcionário\n");
        printf("Matrícula: ");
        scanf("%d", &func[i].matricula);
        printf("Nome: ");
        scanf(" %[^\n]s", func[i].nome);
        printf("Dia de admissão: ");
        scanf("%d", &func[i].admissao_dia);
        printf("Mês de admissão: ");
        scanf("%d", &func[i].admissao_mes);
        printf("Ano de admissão: ");
        scanf("%d", &func[i].admissao_ano);
        printf("Salário: ");
        scanf("%f", &func[i].salario);
        
    }
    
    int matricula = 0;
    /* Estrutura de repetição que vai  ler a matricula do usuário e analizar se
       existe algum funcionário com essa matrícula, se não vai emitir um aviso e
       pedir para digitar novamente. Recebendo uma matrícula que esteja na struct,
       vai imprimir na tela todos os dados relacionados que estão salvos em um espaço do vetor
    */
    while(matricula != -1)
    {
        printf("\n============================================\n");
        printf("Digite a matrícula do funcionário: ");
        scanf("%d", &matricula);
        printf("\n============================================\n");
        if(matricula != -1)
        {
            cont = 0;
            for(i = 0; i < 10; i++)
            {
                if(matricula == func[i].matricula)
                {
                    cont++;
                    j = i;
                    printf("Matrícula: %d", func[j].matricula);
                    printf("\nNome: %s", func[j].nome);
                    printf("\nDia de admissão: %d", func[j].admissao_dia);
                    printf("\nMês de admissão: %d", func[j].admissao_mes);
                    printf("\nAno de admissão: %d", func[j].admissao_ano);
                    printf("\nSalário: %.2f", func[j].salario);
                    printf("\n");
                }
            }
            if(cont == 0){
                printf("Matrícula não encontrada! Digite novamente.\n");
            }
        }
    }
    cont = 0;
    
    /* Código responsável por analizar quais funcionários foram contratados
       nos ultimos 2 anos, vai funcionar recebendo uma variável com o ano atual
       e passando por um laço 'for' que vai imprimir o nome do funcionário.
    */
    printf("\nFuncionários que foram contratados nos últimos 2 anos:\n");
    for(i = 0; i < 10; i++)
    {
        if(func[i].admissao_ano == (anoAtual - 1) || func[i].admissao_ano == (anoAtual - 2))
        {
            printf("-> %s\n", func[i].nome);
        }else{
            cont++;
            if(cont == 9){
                printf("\n-> Nenhum funcionário encontrado!");
            }
        }
    }
    
    /* Para cácular a média salarial dos funcionários, foi usado um laço 'for'
       que vai percorrer a quantidade de funcionários e somando seus salários
       com auxilio da variável 'somaSalario', em seguida vai dividir a soma pelo
       número de funcionários.
    */
    for(i = 0; i < 10; i++)
    {
        somaSalario = somaSalario + func[i].salario;
    }
    media_salarial = somaSalario / 10.0;
    printf("\n\nMédia salarial dos funcionários: %.2f", media_salarial); // vai imprimir a média salarial na tela.
    return 0;
}