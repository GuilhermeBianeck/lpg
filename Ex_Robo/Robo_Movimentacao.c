#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bibliotecas.h"



void MovimentarRobo(Rodada *stc,int PosicaoX, int PosicaoY, char *Ori){

	int i,j,AnguloInicial=0,MovX,MovY; 

	AnguloInicial=AngCorrespondente(Ori); //Converte a posição em char para um número manipulável.

	for (i=0; i< stc->S; i++){

		if (stc->comandos[i]=='D'){ // D é girar 45 a direita.

			AnguloInicial--;

			if (AnguloInicial<0){
				AnguloInicial=7;
			}

		}else if(stc->comandos[i]=='E'){ // E é girar 45 a esquerda.

			AnguloInicial++;

			if (AnguloInicial>7){
				AnguloInicial=0;
			}

		}else if(stc->comandos[i]=='F'){ // F é andar para frente.

			for(j=0; j<8; j++){

				if(AnguloInicial==j){
					MovX=MovimentarX(j);
					MovY=MovimentarY(j);
				}
			}

			if(stc->arena[PosicaoX+MovX][MovY+PosicaoY]=='*'){
					stc->bolinhas++;
					stc->contadores[AnguloInicial]++;
					PosicaoX=PosicaoX+MovX;
					PosicaoY=PosicaoY+MovY;
					stc->arena[PosicaoX+MovX][MovY+PosicaoY]='.';

			}else if (stc->arena[PosicaoX+MovX][MovY+PosicaoY]=='.'){

				stc->contadores[AnguloInicial]++;
				PosicaoX=PosicaoX+MovX;
				PosicaoY=PosicaoY+MovY;

			}


		}else if(stc->comandos[i]=='S'){ // S é pular dois quadrados.

			for(j=0; j<8; j++){

				if(AnguloInicial==j){
					MovX=MovimentarX(j)*2;
					MovY=MovimentarY(j)*2;
				}
			}

			if(stc->arena[PosicaoX+MovX][MovY+PosicaoY]=='*'){
					stc->bolinhas++;
					PosicaoX=PosicaoX+MovX;
					PosicaoY=PosicaoY+MovY;
					stc->arena[PosicaoX+MovX][MovY+PosicaoY]='.';

			}else if (stc->arena[PosicaoX+MovX][MovY+PosicaoY]=='.'){

				PosicaoX=PosicaoX+MovX;
				PosicaoY=PosicaoY+MovY;

			}

			if(stc->arena[PosicaoX+(MovX/2)][(MovY/2)+PosicaoY]=='#'){
				stc->saltos_sobre_cones++;

			}
		}
	}
}

int AngCorrespondente(char *Orientacao){

	if(strcmp(Orientacao, "N")){
		return 0;

	}else if(strcmp(Orientacao, "NE")){
		return 1;

	}else if(strcmp(Orientacao, "L")){
		return 2;

	}else if(strcmp(Orientacao, "SE")){
		return 3;

	}else if(strcmp(Orientacao, "S")){
		return 4;

	}else if(strcmp(Orientacao, "SO")){
		return 5;

	}else if(strcmp(Orientacao, "O")){
		return 6;

	}else if(strcmp(Orientacao, "NO")){
		return 7;

	}
}


int MovimentarX(int j){
	if(j == 0 || j == 4){
		return 0;

	}else if(j == 1 || j == 2 || j == 3){
		return 1;

	}else if(j == 5 || j == 6 || j == 7){
		return -1;

	}

}

int MovimentarY(int j){
	if(j == 0 || j == 1 || j == 7){
		return 1;

	}else if(j == 4 || j == 5 || j == 3){
		return -1;

	}else if( j == 2 || j == 6){
		return 0;
		
	}
}