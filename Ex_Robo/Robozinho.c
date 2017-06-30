#include <stdio.h>
#include <stdlib.h>
#include "Bibliotecas.h"

//O caminho do robô

int main (void){

	int AlocAuxi= 0, PosX, PosY, i, j;
	char *Ori=NULL;


	stc = (Rodada *) malloc (sizeof(Rodada));

	stc->N = AlocAuxi;	//
	stc->M = AlocAuxi;	// Para que possa ser feito a primeira alocação de memória
	stc->S = AlocAuxi;	//

	//FMalloc(stc);

	//Do While Aqui 

	do{

	stc->arena = (char**) realloc (stc->arena,sizeof(char)* stc->N);

	scanf("%d %d %d", &stc->N, &stc->M, &stc->S);

	FMalloc(stc);

	//FRealloc (stc); // Faz a realocação baseado na nova entrada,

	scanf("%d %d %s", &PosX, &PosY, Ori);

	for (i=0; i < stc->N; i++){
		for (j=0; j < stc->M; j++){
			scanf ("%c", &stc->arena[i][j]); // Recebe o mapa alocado
		}
	}

	scanf("%s",stc->comandos); // Lê os comandos a serem executados pelo robo.

	MovimentarRobo(stc, PosX, PosY, Ori);

	}while(stc->N !=0 || stc->M != 0 || stc->S !=0);

}