#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	char arquivo[50]; // Aumentei o tamanho para suportar a extens�o
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); 
    strcat(arquivo, ".txt"); // Adiciona extens�o ao arquivo

    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;  // Sai da fun��o se n�o conseguir abrir o arquivo
    }
    
    fprintf(file, "%s,", cpf);
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fprintf(file, "%s", cargo);
    fclose(file);

    printf("Registro salvo em %s\n", arquivo);
    system("pause");
    return 0;
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char arquivo [50];
	char conteudo[300];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf);
	strcat(arquivo, ".txt");  // Adiciona a extens�o ao nome do arquivo
	
	FILE *file = fopen(arquivo, "r");
	
	if(file == NULL)
	{
		printf("Erro ao localizar o arquivo!\n");
		system("pause");
		return 1;
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: ");
	
	while(fgets(conteudo, sizeof(conteudo), file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); // Fechar arquivo ap�s leitura
	system("pause");
	return 0;
	
	
}

int deletar()
{
	printf("Voc� escolheu deletar nomes!\n");
	system("pause");
	return 0;
}

int main()
    {
	int opcao=0; //definindo as vari�veis
	while (1) // Loop infinito
	
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do programa\n"); // Adiciona a op��o de sa�da
		printf("Op��o: ");
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //funciona como um "apagador" para tudo que j� foi escrito
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
				printf("Saindo do programa...\n");
				return 0;
			
			default:
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		
		} //fim da sele��o

}	
}
