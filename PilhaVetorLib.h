/* PilhaVetorLib.h é uma biblioteca que compõe todas as funções e procedimentos para a execução
 * de tarefas relacionadas a Pilhas de Vetores, desenvolvido para a o Trabalho 02 de EDA 2/2013.
 */

// Função que empilha um caractere em um vetor
char EmpilharChar (char simbolo, int &topo)
{
	topo++;
	return simbolo;
}

// Uma função que desempilha um caractere em um vetor
char DesempilharChar (int &topo)
{
	topo--;
	return ' ';
}