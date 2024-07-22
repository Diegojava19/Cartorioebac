#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//inicio cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infor��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string , ou salvar a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo "a" ,  que significa "append" (adicionar no final do arquivo)
	fprintf(file,","); // escreve uma v�rgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome); // l� o nome digitado pelo usu�rio e armazena na vari�vel 'nome' 
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo "a" (adicionar no final)
	fprintf(file,nome); // escreve uma v�rgula no arquivo
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a"); // abre o arquivo no modo "a" (adicionar no final)
	fprintf(file,","); // escreve uma V�rgula no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); 
	scanf("%s",sobrenome); //l� o sobrenome digitado pelo usu�rio e armazena na vari�vel 'sobrenome'
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo "a" (adicionar no final)
	fprintf(file,sobrenome); // escreve o valor da vari�vel 'sobrenome' no arquivo
	fclose(file); // fecha o arquivo
	
		file = fopen(arquivo, "a"); // abre o arquivo no modo "a" (adicionar no final)
	fprintf(file,","); // escreve uma v�rgula no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); 
	scanf("%s",cargo); // l� o cargo digitado pelo usu�rio e armazena na vari�vel 'cargo'
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo "a" (adicionar no final)
	fprintf(file,cargo); // escreve o valor da vari�vel 'cargo' no arquivo
	fclose(file); // fecha arquivo
	
	system("pause"); // pausa o sistema (no windows), aguardando que o usu�rio pressione uma tecla
	
	
	
	
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem para portugu�s
	
	char cpf[40];  // Vari�vel para armazenar o CPF
	char conteudo[200];  // Vari�vel para armazenar o conte�do do arquivo
	
	printf("Digite o CPF a ser consultado: "); 
	scanf("%s",cpf); // Lendo o cpf fornecido pelo usu�rio
	
	FILE *file;
	file = fopen(cpf,"r"); // Abrindo o Arquivo com o nome do CPF em modo leitura
	
	if(file == NULL) 
    {
	    printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");  // mensagem de erro caso o arquivo n�o seja encontrado	
    }
	
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s",conteudo); // Exibindo o conte�do do arquivo
    	printf("\n\n"); 
	}
	
	system("pause"); //  Pausando o sistema para que o usu�rio possa ver as informa��es
	
	
}

int deletar()
{
	char cpf[40]; // Vari�vel para armazenar o CPF
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);  //  Lendo o CPF fornecido pelo usu�rio
	
	remove(cpf); //  Removendo o arquivo com o nome CPF
	
	FILE *file; 
	file = fopen(cpf,"r"); // Tentando abrir o arquivo para verificar se foi realmente deletado
	
	if(file == NULL)
	{
		printf("O usu�rio foi deletado com sucesso!.\n");  //  Mensagem de confirma��o de exclus�o
		system("pause"); //  Pausando o sistema para que o usu�rio possa ver a mensagem
	}
}

int main ()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	
	    setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	 
	    printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
    	printf("Op��o: "); //fim do menu
	
	    scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
	    system("cls"); //responsavel por limpar a tela
	    
	    switch(opcao) //inicio da sele��o
	    {
	    	case 1:
	    	registro(); // chamada de fun��es 
	        break;
	        
	        case 2:
	        consulta();
        	break;
        	
        	case 3:
        	deletar();	
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por utilizar o sistema!/n");
	    	return 0;
	    	break;
	    	
	    	default:
	    	printf("Essa op��o n�o est� disponivel!\n");
	    	system("pause");
	    	break;
	    	//  fim da sele��o
	    }
	
       
    }
}




