/* O que o programa faz?
 * R: Lê uma expressão aritmética de 20 caracteres e verifica se os parenteses abertos
   e fechados estão balanceados.
 * Arquivos Anexos: OperaLib.h, PilhaVetorLib.h
 * Disciplina: Estrutura de Dados e Algoritmos - 193704
 * Professor: Nilton Correia da Silva
 * Turma: B
 * Tarefa: Trabalho Prático (Pilhas)
 * Grupo: 1
 * Data de Término: 22/10/2013
 * Integrantes:
 * -> Henrique Augusto Pereira dos Santos
 * --> GitHub: https://github.com/henriqueaps
 * -> Jonathan Henrique Maia de Moraes
 * --> GitHub: https://github.com/arkye
 * -> Victor Fellipe Gonçalves Cabeceira
 * --> GitHub: https://github.com/victorcabeceira
 */

#include <stdio.h>
#include <stdlib.h>
#include "OperaLib.h"

int main()
{
	// Variaveis Locais
	char expressao[20];
	int loop = 0;
	bool balanceado = false;
	bool inclusao = false;
	
	do{
		system("cls");
		printf("Este programa verifica se os parenteses de uma expressao\n");
		printf(" aritmetica de at%c 20 caracteres foram devidamente utilizadas\n\n", 130);
		printf("Insira uma expressao aritmetica:\n");
		printf("Exemplo: (3+5)*(2-7)\n");
		scanf(" %20[^\n]", expressao);
		system("cls");
		printf("\nExpressao recebida: %s\n\n", expressao);
		VerificaParenteses(expressao, balanceado, inclusao); // OperaLib.h
		
		if(balanceado == true) // Se a quantidade de parenteses abertos e fechados estão balanceados
		{
			if(inclusao == true) // Se foi incluido parenteses
				printf("Sua expressao possui parenteses devidamente balanceados!\n\n");
			else // Se não foi incluido parenteses
			{
				printf("Sua expressao nao possui parenteses!\n");
				printf("Tente novamente, agora adicionando parenteses.\n\n");
			}
		}
		else // Se a quantidade de parenteses abertos e fechados não estão balanceados
		{
			printf("Sua expressao possui parenteses abertos!\n");
			printf("Verifique sua expressao aritmetica e tente novamente.\n\n");
		}
		
		printf("\nDeseja inserir uma nova expressao aritmetica?\n");
		printf("(1) - Sim \n(0) - Nao \n");
		scanf("%d", &loop);
	}while(loop==1);
	
	system("PAUSE");
	return 0;
}