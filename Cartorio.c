#include <stdio.h> // biblioteca de comunicação com usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() //Fução responsavel por cadastrar os usuários no sistema
{
	//Inicio criação de variaveis/string	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	printf("Digite o CPF a ser cadastrado: \n"); // coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a strings
	
	strcpy(arquivo, cpf); // responsavel por copiar valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" para atualizar o arquivo
	fprintf(file, ","); // como as informações serão separadas
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n");
		printf("%s", conteudo, "\n\n");
		printf("\n\n");
		
		
	}
	
	system("pause");
}

int deletar()
{
    setlocale(LC_ALL,"Portuguese");
    
	char cpf[40];
    
    printf("Digite o cpf do usuário ser deletado: \n");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("o usuário não se encontra no sistema! .\n");
    	system("pause");
    	printf("Usuário deletado! \n");
    	system("pause");
    	
	}

int retornar()
{
    
    printf("Retornar ao menu inicial!\n");
        
    FILE *file;
    file = fopen(cpf,"r");
    fclose(file);
    
    system("pause");
}    
}


int main()
{
	
	int opcao=0; // definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {

     system("cls");
	
	 setlocale(LC_ALL,"Portuguese");
    
     printf("### Cartório da EBAC ### \n\n"); // inicio do menu
     printf("Escolha a opção desejada do menu: \n\n");
     printf("\t1 - Registrar nomes \n");
     printf("\t2 - Consultar nomes \n");
     printf("\t3 - Deletar nomes \n");
     printf("\t4 - Deseja inserir mais usuários?\n");
	 printf("\t5 - sair do sistema\n\n");
    
	 printf("opção:"); // fim do menu
    
     scanf("%d", &opcao); // armazenando a escolha do usuário
    
     system("cls"); // responsavel por limpar a tela
     
     switch(opcao) // inicio da seleção do menu
     {
     	case 1:
     	registro(); // chamada de funções
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Retornar ao menu inicial?");
		break;	
		
		case 5:
		printf("Obrigado por utilizar nosso sistema!\n");
		return 0;
		break;	
		
		default:
		printf("essa opção não está disponivel!\n");
		system("pause");
		break;	
	 } // fim da seleção
    

   	 
    }
}

	
	
	
	

