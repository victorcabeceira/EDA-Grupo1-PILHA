/* OperaLib.h é uma biblioteca que compõe todas as funções e procedimentos para a execução de tarefas
 * relacionadas a Operandos/Operadores, desenvolvido para a o Trabalho 02 de EDA 2/2013.
 */
 
#include <string.h>
#include "PilhaVetorLib.h"

// Procedimento para Verificar o Balanceamento de parenteses de uma string
void VerificaParenteses (char expressao[20], bool &balanceado, bool &inclusao, bool &aritmetica)
{
	// Variaveis locais
	char pilhaParenteses[20],
		 simbAritmeticas[18]= {'+','-','*','x','/','(',' ',')','0','1','2','3','4','5','6','7','8','9'},
		 parenteses;
	int topo = 0, conta_parenteses = 0, j=0, val_aritmetica=0;
	
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
		
		if (expressao[i] == '(') // Se encontrar um Abre-Parenteses
		{
			parenteses = '(';
			EmpilharChar(pilhaParenteses,parenteses,topo); // PilhaVetorLib.h
			conta_parenteses++;
		}
		else if(expressao[i] == ')') // Se encontrar um Fecha-Parenteses
		{
			DesempilharChar(topo); // PilhaVetorLib.h
			conta_parenteses++;
		}
	}
	
	if(val_aritmetica == 0) // Se for validado a condição aritmetica da expressao
	{
		aritmetica = true;
		if(topo == 0) // Se os parenteses estão balanceados
			balanceado = true;
		else // Se os parenteses não estão balanceados
			balanceado = false;
	
		if(conta_parenteses == 0) // Se há parenteses
			inclusao = false;
		else // Se não há parenteses
			inclusao = true;
	}
	else // Se não for validado a condição aritmetica da expressao
		aritmetica = false;
}