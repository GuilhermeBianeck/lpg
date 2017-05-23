#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MATRIZ.H"

int **criar_matriz(int l, int c)
{
	int **ret=NULL,i=0;

	if(!(ret=(int**)malloc(sizeof(int*)*l))){
		return NULL;
	}
	for (i=0;i<l;i++){
		ret[i]=(int*)malloc(sizeof(int)*c);
		if(!ret[i]){
			return NULL;
		}
	}
	return ret;
}

void iniciar_matriz(int **m,int l,int c)
{
	int i,j;

	srand(time(NULL));
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			m[i][j]=rand()%100;
		}
	}
}

void imprimir_matriz(int **m,int l,int c)
{
	int i,j;

	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("[%d][%d]=%d\n",i,j,m[i][j]);
		}
	}
}

void liberar_matriz(int **m,int l, int c)
{
	int i;
	for(i=0;i<l;i++){
		free(m[i]);
	}
	free(m);
}
