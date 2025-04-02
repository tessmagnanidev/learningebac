#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

// Função responsável por cadastrar os usuários no sistema
int registro() 
{
    // Início criação das variáveis/string
    char arquivo[50]; // Aumentei o tamanho para suportar a extensão
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Fim criação das variáveis/string

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Copia o CPF para a variável de arquivo
    strcat(arquivo, ".txt"); // Adiciona extensão ao arquivo

    // Cria um arquivo com o nome baseado no CPF, "w" abre para escrita (cria se não existir ou sobrescreve)
    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;  // Sai da função se não conseguir abrir o arquivo
    }
    
    fprintf(file, "%s,", cpf); // Escreve o CPF no arquivo
    fclose(file); // Fecha o arquivo

    // Captura e grava o nome no arquivo
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a"); // Abre o arquivo no modo de adição (append)
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fprintf(file, "%s,", nome); // Escreve o nome no arquivo
    fclose(file);

    // Captura e grava o sobrenome no arquivo
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fprintf(file, "%s,", sobrenome); // Escreve o sobrenome no arquivo
    fclose(file);

    // Captura e grava o cargo no arquivo
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fprintf(file, "%s", cargo); // Escreve o cargo no arquivo
    fclose(file);

    printf("Registro salvo em %s\n", arquivo);
    system("pause"); // Pausa o programa para o usuário ver a mensagem
    return 0;
}

// Função responsável por consultar um usuário pelo CPF
int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
    char cpf[40];
    char arquivo [50];
    char conteudo[300];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // Copia o CPF para a variável de arquivo
    strcat(arquivo, ".txt");  // Adiciona a extensão ao nome do arquivo
    
    FILE *file = fopen(arquivo, "r"); // Abre o arquivo no modo leitura
    
    if(file == NULL)
    {
        printf("Erro ao localizar o usuário!\n");
        system("pause");
        return 1;
    }
    
    printf("\nEssas são as informações do usuário: ");
    
    while(fgets(conteudo, sizeof(conteudo), file) != NULL) // Lê o arquivo linha por linha
    {
        printf("%s", conteudo); // Exibe o conteúdo do arquivo
        printf("\n\n");
    }
    
    fclose(file); // Fechar arquivo após leitura
    system("pause");
    return 0;
}

// Função responsável por deletar um usuário
int deletar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
    char cpf[40];
    char arquivo [50];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // Copia o CPF para a variável de arquivo
    strcat(arquivo, ".txt");  // Cria o nome do arquivo com extensão
    
    // Remove o arquivo correspondente ao CPF digitado
    if (remove(arquivo) == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("Erro ao localizar o usuário! O arquivo não existe.\n");
    }    
    
    system("pause"); // Pausa o programa para exibir a mensagem
    return 0;
}

// Função principal que exibe o menu e gerencia as opções do usuário
int main()
{
    int opcao = 0; // Definindo a variável para armazenar a escolha do usuário
    
    while (1) { // Loop infinito para manter o programa rodando até que o usuário escolha sair
        
        system("cls"); // Limpa a tela
        
        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
        // Exibe o menu principal
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do programa\n\n"); // Adiciona a opção de saída
        printf("Opção: ");
    
        scanf("%d", &opcao); // Armazena a escolha do usuário
    
        system("cls"); // Limpa a tela novamente antes de executar a opção escolhida
        
        switch(opcao)
        {
            case 1:
                registro(); // Chama a função de registro
                break;
            
            case 2:
                consulta(); // Chama a função de consulta
                break;
            
            case 3:
                deletar(); // Chama a função de deleção
                break;
            
            case 4:
                printf("Obrigado por utilizar nosso sistema!\n");
                return 0; // Encerra o programa
                break;
            
            default:
                printf("Esta opção não está disponível!\n");
                system("pause");
                break;
        }
    }    
}
