#include <stdlib.h>
#include <stdio.h>
#include "bib.h"


int main (void){

	int n=1,m=1,s=1,l,c,i,j,py,px;
	char o[2];
	char **arena = NULL;

	while (n !=0 && m !=0 && s !=0 ){

		Rodada *rod = (Rodada *) malloc (sizeof(Rodada));
		scanf("%d %d %d",&rod->N,&rod->M,&rod->S);
		rod->arena = (char **) malloc ( sizeof(char *) * rod->N);

		for(i=0; i<rod->N; i++){
			rod->arena[i]=(char *) malloc(sizeof(char)* rod->M);
		}

		rod->comandos=(char*)malloc(sizeof(char)* rod->S);
		scanf("%d %d %s ", &py, &px, &o);

		for(i=0; i<rod->N; i++){
			getchar();
			for(j=0; j<rod->M; j++){
				scanf("%c",&rod->arena[i][j]);
				if (rod->arena[i][j]!= '.' && rod->arena[i][j]!= '*' && rod->arena[i][j]!= ' ' && rod->arena[i][j]!= '#' && rod->arena[i][j]!= '\n'){
					printf ("Caracter Errado.");
					return 0;
				}
			}
		}

		scanf("%s",&rod->comandos);

		if(analisar(rod->comandos)==0){
			printar(0,0,0,0,0,0,0,0,0,0,0);
		}else if(analisar(rod->comandos)==1){
			contador(rod->arena, py, px, o, rod->comandos, rod->N, rod->M);
		}

   		free(rod->comandos);
   		for(i=0;i<rod->N;i++){
   			free(rod->arena[i]);
   		}
   		free(rod->arena);
   		free(rod);
  		scanf("%d %d %d",&rod->N,&rod->M,&rod->S);
  	}

  	printar(0,0,0,0,0,0,0,0,0,0,1);
  	return 0;
}
