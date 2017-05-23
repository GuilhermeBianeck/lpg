#include <stdio.h>
#include "MATRIZ.H"

int main(void)
{
	int **mat=NULL;
	int linhas=0,colunas=0;

	printf("Informe o número de linhas e coluas\n");
	scanf("%d%d",&linhas,&colunas);

	mat=criar_matriz(linhas,colunas);
	iniciar_matriz(mat,linhas,colunas);
	imprimir_matriz(mat,linhas,colunas);
	liberar_matriz(mat,linhas,colunas);

	return 0;
}
