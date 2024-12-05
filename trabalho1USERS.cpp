
#include <stdio.h>
//biblioteca de comunica��o do usu�rio// 

#include <stdlib.h>
//biblioteca de aloca��o de espa�o em mem�ria//

#include <locale.h>
//biblioteca de aloca��o de texto por regi�o//

#include <string.h>
//biblioteca de aloca��o de strings//


int registro() //definindo variaveis de registro
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\n\n\tDigite o cpf: \n\n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das strings//
	
	FILE *file;// cria o arquivo do banco de dados
	file = fopen(arquivo, "w");//cria o arquivo do banco de dados
	fprintf(file, cpf);//salva a variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");// vai atualizar a informa��o
	fprintf(file,",");// separar os dados com uma virgula
	fclose(file);
	
	printf("\n\n\t Digite o nome: \n\n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\n\n\tDigite o sobrenome: \n\n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\n\n\tDigite o cargo: \n\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta() //definindo variaveis de consulta
{
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
	printf("\n\nDigite o CPF: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //vai ler o arquivo consultado
	
	if(file == NULL)
	{
		printf ("\n\nNenhum arquivo localizada. \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL);
	{
		printf("\n\nInforma��es do Usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");//vai pausar a escolha do usu�rio at� ele escolher outra
} 

int exclusao() //definindo variaveis de exclus�o
{
	char cpf[40];
	
	printf("\n\n\tQual o usu�rio a ser deletado ? : \n\n");
	scanf("%s",cpf); //vai armazenar a informa��o deletada --- %s refere-se a string
	
	remove(cpf); // vai remover a informa��o selecionada
	
	FILE *file;
	file = fopen(cpf,"r"); //vai consultar a informa��o removida
	
	
	if(file == NULL)
		{
			printf("\n\n\t O usu�rio n�o se encontra no sistema.\n");
			system("pause");
			return 0;
		}
		
	fclose(file);
	
	if(remove(cpf)==0)
		{
			printf("\n\n\t O usu�rio foi removido do sistema.\n");
		}
	else 
		{
			printf("\n\n\t Erro ao remover arquivo.\n");
		}
	system("pause");
	return 0;
}

int main()  //definindo variaveis principais
	{

	
		
		int opcao=0; // Serve para deixar a sele��o de opcoes zerada.
		int x=1;
		
		for(x=1; x=1;)
		{
			
			system("cls");//cls serve para limpar a tela
			
			setlocale(LC_ALL, "Portuguese");//definindo linguagem
			
		
	printf("\n Central de Usu�rios - Ebac\n\n");//inicio do menu
	printf("\t Menu de Op��es ;\n\n");
	printf("\t 1 - Registro de Usu�rios\n");
	printf("\t 2 - Consulta de Usu�rios\n");
	printf("\t 3 - Exclus�o de Usu�rios\n\n");
	printf("\t Qual a op��o deseja? ");//final do menu
	
			{  // armazenando sele��o
			scanf("%d",&opcao);// vai escanear oque o usu�rio coloca --- %d serve para armazenar uma variavel inteira
			
			system("cls");//cls serve para limpar a tela

			switch (opcao)//retorno de sele��es
				{
					case 1:
					 registro(); //chamada de fun��es
					break;
					
					case 2:
					 consulta();
					break;
					
					case 3:
					 exclusao();
					break;
					
					default:
						printf("\n\n\top��o inexistente\n\n");	
						system("pause");//vai pausar a escolha do usu�rio at� ele escolher outra
				}

			}	
		}// fim da sele��o
	}
	// 	printf("\n\n\n Software criado por Emmanuel Sodo.\n");
