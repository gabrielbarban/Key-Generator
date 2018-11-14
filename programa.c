#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void flush_in(){ 
	//função para limpar o buffer do teclado
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void encript(char nome[100]){
		char senha[100];
		char dicionario[100] = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
		'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 
		'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
		'Y', 'Z'};
		printf("\nCerto %s... agora informe a senha que deverá ser encriptada: ", nome);
		scanf("%s", senha);
		int qtd = strlen(senha) + strlen(senha);
		char senha_e[strlen(senha)];
		int i=0;
		int j=0;
		char aux[1];
		int temp = 0;
		for(i=0 ; i<strlen(senha) ; i++)
		{
			for(j=0 ; j<strlen(dicionario) ; j++)
			{
				if( (senha[i] == dicionario[j]) & (j<=59) )
				{
					aux[0] = dicionario[j+3];
					senha_e[i] = aux[0];
				}
				if( (senha[i] == dicionario[j]) & (j==60) )
				{
					aux[0] = dicionario[1];
	                senha_e[i] = aux[0];
				}
				if( (senha[i] == dicionario[j]) & (j==61) )
	            {
					aux[0] = dicionario[2];
	                senha_e[i] = aux[0];
	            }
				if( (senha[i] == dicionario[j]) & (j==62) )
	            {
					aux[0] = dicionario[3];
	                senha_e[i] = aux[0];
	            }
			}
		}
		//populando o resto do vetor encriptado com números aleatórios
		for(int cont=strlen(senha) ; cont<qtd ; cont++)
	    {
	    	temp = rand() % 60;
	        senha_e[cont] = dicionario[temp];
	    }
	    printf("\n\nSENHA ENCRIPTADA COMPLETA:\n");
		for(int cont = 0 ; cont<strlen(senha_e) ; cont++)
	    {
	        printf("%c", senha_e[cont]);
	    }
		printf("\n\n");
}

void decript(char nome[100]){
		char senha_e[100];
		char senha[100];
		char temp;
		char dicionario[100] = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
		'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 
		'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
		'Y', 'Z'};

		printf("\nCerto %s... informe o código que deverá ser desemcriptado: ", nome);
		scanf("%s", senha_e);

		int qtd_certa = (strlen(senha_e) / 2);

		for(int i=0 ; i<qtd_certa ; i++)
		{
			temp = senha_e[i];
			for(int j=0 ; j<strlen(dicionario) ; j++)
			{
				if( (temp == dicionario[j]) & (j<=59))
				{
					senha[i] = dicionario[j-3];
				}
				if( (temp == dicionario[j]) & (j==60) )
				{
					senha[i] = dicionario[1];
				}
				if( (temp == dicionario[j]) & (j==61) )
				{
					senha[i] = dicionario[2];
				}
				if( (temp == dicionario[j]) & (j==62) )
				{
					senha[i] = dicionario[3];
				}
			}
		}

		printf("\n\nSENHA DESEMCRIPTADA:\n");
		for(int cont = 0 ; cont<strlen(senha) ; cont++)
	    {
	        printf("%c", senha[cont]);
	    }
	    printf("\n\n");
}

void opcoes(){

	char nome[100];
	char opcao[1];

	printf("\n\n\n");
	printf("###### Gabriel Barban Rocha - Key Generator Versão 1 ######");
	printf("\n\n\n");

	printf("Qual o seu nome? ");
	scanf("%s", nome);
	flush_in(); 
	printf("\n1- Criar chave encriptada\n2- Desemcriptar uma chave\n\n\nO que você deseja fazer %s (Digite o n° da opção)? ", nome);
	scanf("%c", opcao);
	flush_in(); 
	
	if(opcao[0] == '1') {
		encript(nome);
	}

	if(opcao[0] == '2')
	{
		decript(nome);
	}
	else
	{
		printf("Você não escolheu nenhuma das opções corretas.\n");
	}
}

int main()
{
	opcoes();
	return 0;
}