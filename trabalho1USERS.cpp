
#include <stdio.h>
//biblioteca de comunicação do usuário// 

#include <stdlib.h>
//biblioteca de alocação de espaço em memória//

#include <locale.h>
//biblioteca de alocação de texto por região//

#include <string.h>
//biblioteca de alocação de strings//


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
	
	file = fopen(arquivo, "a");// vai atualizar a informação
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
		printf("\n\nInformações do Usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");//vai pausar a escolha do usuário até ele escolher outra
} 

int exclusao() //definindo variaveis de exclusão
{
	char cpf[40];
	
	printf("\n\n\tQual o usuário a ser deletado ? : \n\n");
	scanf("%s",cpf); //vai armazenar a informação deletada --- %s refere-se a string
	
	remove(cpf); // vai remover a informação selecionada
	
	FILE *file;
	file = fopen(cpf,"r"); //vai consultar a informação removida
	
	
	if(file == NULL)
		{
			printf("\n\n\t O usuário não se encontra no sistema.\n");
			system("pause");
			return 0;
		}
		
	fclose(file);
	
	if(remove(cpf)==0)
		{
			printf("\n\n\t O usuário foi removido do sistema.\n");
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

	
		
		int opcao=0; // Serve para deixar a seleção de opcoes zerada.
		int x=1;
		
		for(x=1; x=1;)
		{
			
			system("cls");//cls serve para limpar a tela
			
			setlocale(LC_ALL, "Portuguese");//definindo linguagem
			
		
	printf("\n Central de Usuários - Ebac\n\n");//inicio do menu
	printf("\t Menu de Opções ;\n\n");
	printf("\t 1 - Registro de Usuários\n");
	printf("\t 2 - Consulta de Usuários\n");
	printf("\t 3 - Exclusão de Usuários\n\n");
	printf("\t Qual a opção deseja? ");//final do menu
	
			{  // armazenando seleção
			scanf("%d",&opcao);// vai escanear oque o usuário coloca --- %d serve para armazenar uma variavel inteira
			
			system("cls");//cls serve para limpar a tela

			switch (opcao)//retorno de seleções
				{
					case 1:
					 registro(); //chamada de funções
					break;
					
					case 2:
					 consulta();
					break;
					
					case 3:
					 exclusao();
					break;
					
					default:
						printf("\n\n\topção inexistente\n\n");	
						system("pause");//vai pausar a escolha do usuário até ele escolher outra
				}

			}	
		}// fim da seleção
	}
	// 	printf("\n\n\n Software criado por Emmanuel Sodo.\n");
