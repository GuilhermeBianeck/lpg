#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void){

	TMatriz *mat = NULL;
	int op, l, c;
	printf("Informe 1 para bloco e 2 para distribuida\n");
	scanf("%d", &op);
	printf("Informe o número de linhas e colunas\n");
	scanf("%d%d", &l, &c);
	if(op == 1){
		mat = criar_matriz(l, c, dados_bloco);
	} else if(op == 2){
		mat = criar_matriz(l, c, dados_distribuidos);
	} else {
		printf("Opção inválida\n");
		exit(EXIT_FAILURE);
	}

	iniciar_matriz(mat);
	imprimir_matriz(mat);

	if( op == 1){
		liberar_matriz(mat, liberar_dados_bloco);
	} else {
		liberar_matriz(mat, liberar_dados_distribuidos);
	}
	return 0;


}
