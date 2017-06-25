#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bib.h"

int **dados_bloco(int l, int c)
{
	int i;
	int *aux=NULL;
	int **ret = NULL;
	if (!(ret = (int **)malloc(sizeof(int*)*l)))
		return NULL;
	if (!(aux = (int *)malloc(sizeof(int)*l*c))){
		free(ret);
		return NULL;
	}
	for (i=0;i<l;i++){
		ret[i]=&aux[i*c];
	}
	return ret;	
}

int analisar(char *palavra){
    int i;
    for(i=0;i<strlen(palavra);i++){
      if(palavra[i]=='F' || palavra[i]=='S')return 1;
    }
    return 0;
}

Rodada *criar_matriz(int linhas, int colunas)
{
	char **vet = NULL;
	int i=0;

	if(!(vet = (char**)malloc(sizeof(char*)*linhas))){
		return NULL;
	}
	for(i=0;i<colunas;i++){
		vet[i]=(char*)malloc(sizeof(char)*colunas);

		if(!vet[i]){
			return NULL;
		}
	}
	return vet;
}
