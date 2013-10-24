/* OperaLib.h é uma biblioteca que compõe todas as funções e procedimentos para a execução de tarefas
 * relacionadas a Operandos/Operadores, desenvolvido para a o Trabalho 02 de EDA 2/2013.
 */
 
#include <string.h>
#include "PilhaVetorLib.h"

// Procedimento para Verificar o Balanceamento de parentesis de uma string
void VerificaParenteses (char expressao[20])
{
	// Variaveis locais
	bool erro_Ordem = false;
	char pilhaParenteses[20],
		 simbAritmeticas[18]= {'+','-','*','x','/','(',' ',')','0','1','2','3','4','5','6','7','8','9'},
		 parentesis;
	int topo = 0, conta_parentesis = 0, j=0, val_aritmetica=0, par_Aberto = 0, par_Fechado = 0;
	
	// Passos de verificação da String
	for(int i=0; expressao[i] != '\0'; i++) // Percorre todos os caracteres da string
	{
		for(j=0;j<18;j++) // Percorre todos os caracteres aritmeticos
		{
			if(simbAritmeticas[j]==expressao[i]) // Se o caractere da string for igual a um aritmetico
			{
				val_aritmetica = 0;
				break;
			}
			else // Se o caractere da string não for igual a um aritmetico
				val_aritmetica++;
		}
		
		if(val_aritmetica != 0) // Se não for validado a condição aritmetica da expressao
			break;
		
		if (expressao[i] == '(') // Se encontrar um Abre-Parentesis
		{
			parentesis = '(';
			pilhaParenteses[topo] = EmpilharChar(parentesis,topo); // PilhaVetorLib.h
			conta_parentesis++;
		}
		else if(expressao[i] == ')') // Se encontrar um Fecha-Parentesis
		{
			parentesis = ')';
			pilhaParenteses[topo] = EmpilharChar(parentesis,topo); // PilhaVetorLib.h
			conta_parentesis++;
		}
	}
	
	// Verificar se a ordem dos parentesis é coerente
	if(conta_parentesis!=0) // Ocorre apenas se houver parentesis
	{
		// Se a ordem não estiver coerente, erro_Ordem será verdadeiro
		for(j=0;j<conta_parentesis;j++)
		{
			if(pilhaParenteses[j]=='(') // Se encontrar um parentesis aberto
				par_Aberto++;
			else if(pilhaParenteses[j]==')')// Se encontrar um parentesis fechado
			{	
				par_Fechado++;
				if(par_Fechado>par_Aberto) // Se ocorrer de ter mais parentesis fechados que abertos
				{
					if(pilhaParenteses[j+1]=='(') // Se o proximo parentesis for aberto
						erro_Ordem = true;
				}
			}
		}
		
		// par_Aberto recebe a diferença entre os parentesis abertos e fechados
		if(par_Aberto>par_Fechado)
			par_Aberto -= par_Fechado;
		else if(par_Aberto<par_Fechado)
		{
			par_Fechado -= par_Aberto;
			par_Aberto = par_Fechado;
		}
		else // Se forem iguais
			par_Aberto -= par_Fechado;
			
		// Desempilhando
		for(j=0;j<=conta_parentesis;j++)
			pilhaParenteses[topo] = DesempilharChar(topo);		
	}
	
	// Informando ao usuário
	if(val_aritmetica == 0) // Se a expressao foi escrita de forma aritmetica
	{
		if(erro_Ordem == true) // Se houve incoerência entre os parenteses abertos e fechados
		{
			printf("A sequencia de parentesis nao esta coerente!\n\n");
			printf("Um ou mais parentesis fechado nao possui seu respectivo\n");
			printf("parentesis aberto associado.\n\n");
			printf("Verifique sua expressao aritmetica e tente novamente.\n\n");
		}
		else // Se não houve incoerência entre os parenteses abertos e fechados
		{
			if(par_Aberto == 0) // Se a quantidade de parentesis abertos e fechados estão balanceados
			{
				if(conta_parentesis == 0) // Se não foi incluido parentesis
				{
					printf("Sua expressao nao possui parentesis!\n");
					printf("Tente novamente, agora adicionando parentesis.\n\n");
				}
				else // Se foi incluido parentesis
					printf("Sua expressao possui parentesis devidamente balanceados!\n\n");
			}
			else // Se a quantidade de parentesis abertos e fechados não estão balanceados
			{
				if(par_Aberto==1)
					printf("Sua expressao possui %d parentesis aberto!\n", par_Aberto);
				else
					printf("Sua expressao possui %d parentesis abertos!\n", par_Fechado);
				printf("Verifique sua expressao aritmetica e tente novamente.\n\n");
			}
		}
	}
	else // Se a expressao não foi escrita de forma aritmetica
	{
		printf("Sua expressao nao %c aritmetica!\n\n", 130);
		printf("Uma expressao aritmetica deve possuir apenas\n");
		printf("numeros, parentesis e os simbolos basicos: + - x * /\n\n");
		printf("Verifique sua expressao e tente novamente.\n\n");
	}			
}