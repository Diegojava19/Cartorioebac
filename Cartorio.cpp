#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//inicio criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando inforção do usuário
	scanf("%s",cpf); //%s refere-se a string , ou salvar a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo "a" ,  que significa "append" (adicionar no final do arquivo)
	fprintf(file,","); // escreve uma vírgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome); // lê o nome digitado pelo usuário e armazena na variável 'nome' 
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo "a" (adicionar no final)
	fprintf(file,nome); // escreve uma vírgula no arquivo
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a"); // abre o arquivo no modo "a" (adicionar no final)
	fprintf(file,","); // escreve uma Vírgula no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); 
	scanf("%s",sobrenome); //lê o sobrenome digitado pelo usuário e armazena na variável 'sobrenome'
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo "a" (adicionar no final)
	fprintf(file,sobrenome); // escreve o valor da variável 'sobrenome' no arquivo
	fclose(file); // fecha o arquivo
	
		file = fopen(arquivo, "a"); // abre o arquivo no modo "a" (adicionar no final)
	fprintf(file,","); // escreve uma vírgula no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); 
	scanf("%s",cargo); // lê o cargo digitado pelo usuário e armazena na variável 'cargo'
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo "a" (adicionar no final)
	fprintf(file,cargo); // escreve o valor da variável 'cargo' no arquivo
	fclose(file); // fecha arquivo
	
	system("pause"); // pausa o sistema (no windows), aguardando que o usuário pressione uma tecla
	
	
	
	
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem para português
	
	char cpf[40];  // Variável para armazenar o CPF
	char conteudo[200];  // Variável para armazenar o conteúdo do arquivo
	
	printf("Digite o CPF a ser consultado: "); 
	scanf("%s",cpf); // Lendo o cpf fornecido pelo usuário
	
	FILE *file;
	file = fopen(cpf,"r"); // Abrindo o Arquivo com o nome do CPF em modo leitura
	
	if(file == NULL) 
    {
	    printf("Não foi possivel abrir o arquivo, não localizado!.\n");  // mensagem de erro caso o arquivo não seja encontrado	
    }
	
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s",conteudo); // Exibindo o conteúdo do arquivo
    	printf("\n\n"); 
	}
	
	system("pause"); //  Pausando o sistema para que o usuário possa ver as informações
	
	
}

int deletar()
{
	char cpf[40]; // Variável para armazenar o CPF
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);  //  Lendo o CPF fornecido pelo usuário
	
	remove(cpf); //  Removendo o arquivo com o nome CPF
	
	FILE *file; 
	file = fopen(cpf,"r"); // Tentando abrir o arquivo para verificar se foi realmente deletado
	
	if(file == NULL)
	{
		printf("O usuário foi deletado com sucesso!.\n");  //  Mensagem de confirmação de exclusão
		system("pause"); //  Pausando o sistema para que o usuário possa ver a mensagem
	}
}

int main ()
    {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	
	    setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	 
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
    	printf("Opção: "); //fim do menu
	
	    scanf("%d", &opcao); // armazenando a escolha do usuário
	
	    system("cls"); //responsavel por limpar a tela
	    
	    switch(opcao) //inicio da seleção
	    {
	    	case 1:
	    	registro(); // chamada de funções 
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
	    	printf("Essa opção não está disponivel!\n");
	    	system("pause");
	    	break;
	    	//  fim da seleção
	    }
	
       
    }
}




