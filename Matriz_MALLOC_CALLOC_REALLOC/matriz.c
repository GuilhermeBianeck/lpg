#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

void iniciar_matriz(TMatriz *mat)
{
	int i;
	int j;
	if (!mat)
		return;

	srand(time(NULL));
	for (i = 0; i < mat->linhas; i++) {
		for (j = 0; j < mat->colunas; j++) {
			mat->m[i][j] = rand() % 100;
		}
	}
}

void imprimir_matriz(TMatriz *mat)
{
	int i;
	int j;
	if (!mat)
		return;

	for (i = 0; i < mat->linhas; i++) {
		for (j = 0; j < mat->colunas; j++) {
			printf("mat[%d][%d] = %d", i, j, mat->m[i][j]);
		}
	}
}

int **dados_bloco(int l, int c){
	int i;
	int *aux = 	NULL;
	int **ret = NULL;
	if(!(ret = (int **) malloc(sizeof(int *)*l)))
		return NULL;
	if(!(aux = (int *) malloc(sizeof(int)* l * c))){
		free(ret);
		return NULL;
	}
	for(i=0; i<l; i++){
		ret[i] = &aux[i * c];
	}
	return ret;

}
int **dados_distribuidos(int l, int c){
	int i,j;
	int **ret = NULL;
	if(!(ret = (int **) malloc(sizeof(int *) * l)))
		return NULL;
		for(i=0; i < l; i++){
			if(!(ret[i] = (int *)malloc(sizeof(int) * c))){
				for(j = 0; j< i; j++)
					free(ret[j]);
				return(ret);
				return NULL;
			}
		}
		return ret;
	}

TMatriz *criar_matriz(int linhas, int colunas, int **(*f)(int, int)){
	TMatriz *ret = NULL;
	if(!(ret = TMatriz *) malloc(sizeof(TMatriz)))
		return NULL;
	ret->linha = linhas;
	(*ret).colunas = colunas;
	ret->m = (int **)(*f)(linhas, colunas);
	return ret;

}
