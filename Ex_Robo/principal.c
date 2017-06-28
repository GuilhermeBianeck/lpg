#include <stdlib.h>
#include <stdio.h>
#include "bib.h"


int main (void){

	int n=1,m=1,s=1,l,c,i,j,py,px;
	char o[2];
	char **arena = NULL;


	Rodada *rod = (Rodada *) malloc (sizeof(Rodada));

	scanf("%d %d %d",&rod->N,&rod->M,&rod->S);

	while (rod->N !=0 && rod->M !=0 && rod->S !=0 ){

		alocar(rod);

		scanf("%d %d %s ", &py, &px, o);

		for(i=0; i<rod->N; i++){
			getchar();
			for(j=0; j<rod->M; j++){
				scanf("%c",&rod->arena[i][j]);
				if (rod->arena[i][j]!= '.' && rod->arena[i][j]!= '*' && rod->arena[i][j]!= ' ' && rod->arena[i][j]!= '#' && rod->arena[i][j]!= '\n'){
					printf ("Caracter Incorreto.");
					return 0;
				}
			}
		}
		scanf("%s",rod->comandos);
		if(analisar(rod)==0){
			imprimir(0,0,0,0,0,0,0,0,0,0,0);
		}else if(analisar(rod)==1){
			contador(rod, py, px, o);
		}

  		scanf("%d %d %d",&rod->N,&rod->M,&rod->S);
  	}

  	imprimir(0,0,0,0,0,0,0,0,0,0,1);

  	limpar(rod);

   	printf("Executado com sucesso.\n");

  	return 0;
}
