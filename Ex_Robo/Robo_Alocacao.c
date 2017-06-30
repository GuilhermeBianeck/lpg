#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Bibliotecas.h"


// FUNÇÔES DE ALOCAÇÂO DE MEMÒRIA DINÂMICA.

	void FRealloc (Rodada *stc){

	//Realloc faz a nova alocação da ARENA apenas;
		int i;

		

		for(i=0; i<stc->N ; i++){
			stc->arena[i] = (char *) realloc (stc->arena,sizeof(char)* stc->M);
		}

		stc->comandos=(char*) realloc (stc->comandos,sizeof(char)* stc->S);

	}

	void FMalloc (Rodada *stc){

	//Faz o alocamento de TODOS os elementos da Struct;
		int i;

		
		stc->arena = (char **) malloc (sizeof(char *) * stc->N);

		for(i=0; i<stc->N; i++){
			stc->arena[i]=(char *) malloc(sizeof(char)* stc->M);
		}

		stc->comandos=(char*)malloc(sizeof(char)* stc->S);

	}


	void FFree (Rodada *stc){

	//Libera todos os elementos da Struct;
		int i; 

		free(stc->comandos);

		for(i=0; i<stc->N; i++){
			free(stc->arena[i]);
		}

		free(stc->arena);
		free(stc);

	}

//
