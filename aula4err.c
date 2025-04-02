#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

// Fun��o respons�vel por cadastrar os usu�rios no sistema
int registro() 
{
    // In�cio cria��o das vari�veis/string
    char arquivo[50]; // Aumentei o tamanho para suportar a extens�o
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Fim cria��o das vari�veis/string

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Copia o CPF para a vari�vel de arquivo
    strcat(arquivo, ".txt"); // Adiciona extens�o ao arquivo

    // Cria um arquivo com o nome baseado no CPF, "w" abre para escrita (cria se n�o existir ou sobrescreve)
    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;  // Sai da fun��o se n�o conseguir abrir o arquivo
    }
    
    fprintf(file, "%s,", cpf); // Escreve o CPF no arquivo
    fclose(file); // Fecha o arquivo

    // Captura e grava o nome no arquivo
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a"); // Abre o arquivo no modo de adi��o (append)
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
    system("pause"); // Pausa o programa para o usu�rio ver a mensagem
    return 0;
}

// Fun��o respons�vel por consultar um usu�rio pelo CPF
int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
    char cpf[40];
    char arquivo [50];
    char conteudo[300];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // Copia o CPF para a vari�vel de arquivo
    strcat(arquivo, ".txt");  // Adiciona a extens�o ao nome do arquivo
    
    FILE *file = fopen(arquivo, "r"); // Abre o arquivo no modo leitura
    
    if(file == NULL)
    {
        printf("Erro ao localizar o usu�rio!\n");
        system("pause");
        return 1;
    }
    
    printf("\nEssas s�o as informa��es do usu�rio: ");
    
    while(fgets(conteudo, sizeof(conteudo), file) != NULL) // L� o arquivo linha por linha
    {
        printf("%s", conteudo); // Exibe o conte�do do arquivo
        printf("\n\n");
    }
    
    fclose(file); // Fechar arquivo ap�s leitura
    system("pause");
    return 0;
}

// Fun��o respons�vel por deletar um usu�rio
int deletar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
    char cpf[40];
    char arquivo [50];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // Copia o CPF para a vari�vel de arquivo
    strcat(arquivo, ".txt");  // Cria o nome do arquivo com extens�o
    
    // Remove o arquivo correspondente ao CPF digitado
    if (remove(arquivo) == 0) {
        printf("Usu�rio deletado com sucesso!\n");
    } else {
        printf("Erro ao localizar o usu�rio! O arquivo n�o existe.\n");
    }    
    
    system("pause"); // Pausa o programa para exibir a mensagem
    return 0;
}

// Fun��o principal que exibe o menu e gerencia as op��es do usu�rio
int main()
{
    int opcao = 0; // Definindo a vari�vel para armazenar a escolha do usu�rio
    
    while (1) { // Loop infinito para manter o programa rodando at� que o usu�rio escolha sair
        
        system("cls"); // Limpa a tela
        
        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
        // Exibe o menu principal
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do programa\n\n"); // Adiciona a op��o de sa�da
        printf("Op��o: ");
    
        scanf("%d", &opcao); // Armazena a escolha do usu�rio
    
        system("cls"); // Limpa a tela novamente antes de executar a op��o escolhida
        
        switch(opcao)
        {
            case 1:
                registro(); // Chama a fun��o de registro
                break;
            
            case 2:
                consulta(); // Chama a fun��o de consulta
                break;
            
            case 3:
                deletar(); // Chama a fun��o de dele��o
                break;
            
            case 4:
                printf("Obrigado por utilizar nosso sistema!\n");
                return 0; // Encerra o programa
                break;
            
            default:
                printf("Esta op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        }
    }    
}
