/* OperaLib.h é uma biblioteca que compõe todas as funções e procedimentos para a execução de tarefas
 * relacionadas a Operandos/Operadores, desenvolvido para a o Trabalho 02 de EDA 2/2013.
 */
 
#include <string.h>
#include "PilhaVetorLib.h"

// Procedimento para Verificar o Balanceamento de parenteses de uma string
void VerificaParenteses (char operacao[20], bool &balanceado, bool &inclusao)
{
	// Variaveis locais
	char pilhaParenteses[20];
	char parenteses;
	int topo = 0;
	int conta_parenteses = 0;
	
	for(int i=0; operacao[i] != '\0'; i++) // Percorre todos os caracteres da string
	{
		if (operacao[i] == '(') // Se encontrar um Abre-Parenteses
		{
			parenteses = '(';
			EmpilharChar(pilhaParenteses,parenteses,topo); // PilhaVetorLib.h
			conta_parenteses++;
		}
		else if(operacao[i] == ')') // Se encontrar um Fecha-Parenteses
		{
			DesempilharChar(topo); // PilhaVetorLib.h
			conta_parenteses++;
		}
	}
	if(topo == 0) // Se os parenteses estão balanceados
		balanceado = true;
	else // Se os parenteses não estão balanceados
		balanceado = false;
	
	if(conta_parenteses == 0) // Se há parenteses
		inclusao = false;
	else // Se não há parenteses
		inclusao = true;
}