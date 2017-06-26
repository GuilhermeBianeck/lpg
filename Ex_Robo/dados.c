#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bib.h"

FILE *arquivo = NULL;
int casos=0;

int analisar(char *palavra){
    int i;
    for(i=0;i<strlen(palavra);i++){
      if(palavra[i]=='F' || palavra[i]=='S')
      	return 1;
    }
    return 0;
}

void posmove(char **vet, int rotacao,char inicial[], int subtraindo,int *linha,int *coluna,int *cones,int *N,int *S,int *L,int *O,int *NE,int *SE,int *SO,int *NO){
	switch (rotacao){
	    case(0):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha-=subtraindo;*coluna+=subtraindo;
	        *NE+1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha+=subtraindo;*coluna+=subtraindo;
	        *SE+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha+=subtraindo;*coluna-=subtraindo;
	        *SO+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha-=subtraindo;*coluna-=subtraindo;
	        *NO+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha-=subtraindo;
	        *N+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha+=subtraindo;
	        *S+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna+=subtraindo;
	        *L+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna-=subtraindo;
	        *O+=1;
	      }
	      break;
	    case(45):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *coluna-=subtraindo;
	        *L+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha+=subtraindo;
	        *S+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *coluna-=subtraindo;
	        *O+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha-=subtraindo;
	        *N+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha-=subtraindo;*coluna+=subtraindo;
	        *NE+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha+=subtraindo;*coluna-=subtraindo;
	        *SO+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna+=subtraindo;*linha+=subtraindo;
	        *SE+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna-=subtraindo;*linha-=subtraindo;
	        *NO+=1;
	      }
	      break;
	    case(90):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha+=subtraindo;*coluna+=subtraindo;
	        *SE+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha+=subtraindo;*coluna-=subtraindo;
	        *SO+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha-=subtraindo;*coluna-=subtraindo;
	        *NO+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha-=subtraindo;*coluna+=subtraindo;
	        *NE+=1;
	      }
	      else if(inicial[0]=='N'){
	        *coluna+=subtraindo;
	        *L+=1;
	      }
	      else if(inicial[0]=='S'){
	        *coluna-=subtraindo;
	        *O+=1;
	      }
	      else if(inicial[0]=='L'){
	        *linha+=subtraindo;
	        *S+=1;
	      }
	      else if(inicial[0]=='O'){
	        *linha-=subtraindo;
	        *N+=1;
	      }
	      break;
	    case(135):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha+=subtraindo;
	        *S+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *coluna-=subtraindo;
	        *O+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha-=subtraindo;
	        *N+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *coluna-=subtraindo;
	        *L+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha+=subtraindo;*coluna+=subtraindo;
	        *SE+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha-=subtraindo;*coluna-=subtraindo;
	        *NO+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna+=subtraindo;*linha-=subtraindo;
	        *SO+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna-=subtraindo;*linha+=subtraindo;
	        *NE+=1;
	      }
	      break;
	    case(180):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha+=subtraindo;*coluna-=subtraindo;
	        *SO+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha-=subtraindo;*coluna-=subtraindo;
	        *NO+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha-=subtraindo;*coluna+=subtraindo;
	        *NE+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha+=subtraindo;*coluna+=subtraindo;
	        *SE+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha+=subtraindo;
	        *S+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha-=subtraindo;
	        *N+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna-=subtraindo;
	        *O+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna+=subtraindo;
	        *L+=1;
	      }
	      break;
	    case(225):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *coluna-=subtraindo;
	        *O+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha-=subtraindo;
	        *N+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *coluna+=subtraindo;
	        *L+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha+=subtraindo;
	        *S+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha-=subtraindo;*coluna+=subtraindo;
	        *SO+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha-=subtraindo;*coluna+=subtraindo;
	        *NE+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna-=subtraindo;*linha-=subtraindo;
	        *NO+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna+=subtraindo;*linha+=subtraindo;
	        *SE+=1;
	      }
	      break;
	    case(270):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha-=subtraindo;*coluna-=subtraindo;
	        *NO+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha-=subtraindo;*coluna+=subtraindo;
	        *NE+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha+=subtraindo;*coluna+=subtraindo;
	        *SE+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha+=subtraindo;*coluna-=subtraindo;
	        *SO+=1;
	      }
	      else if(inicial[0]=='N'){
	        *coluna-=subtraindo;
	        *O+=1;
	      }
	      else if(inicial[0]=='S'){
	        *coluna+=subtraindo;
	        *L+=1;
	      }
	      else if(inicial[0]=='L'){
	        *linha-=subtraindo;
	        *N+=1;
	      }
	      else if(inicial[0]=='O'){
	        *linha+=subtraindo;
	        *S+=1;
	      }
	      break;
	    case(315):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha-=subtraindo;
	        *N+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *coluna+=subtraindo;
	        *L+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha+=subtraindo;
	        *S+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *coluna-=subtraindo;
	        *O+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha-=subtraindo;*coluna-=subtraindo;
	        *NO+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha+=subtraindo;*coluna+=subtraindo;
	        *SE+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna+=subtraindo;*linha-=subtraindo;
	        *NE+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna-=subtraindo;*linha+=subtraindo;
	        *SO+=1;
	      }
	      break;
	  }
	if(vet[*linha][*coluna]=='#'){
	  *cones+=1;
	}
}

void contador(char **vet, int linha, int coluna, char inicial[],char comandos[], int matriz_linhas, int matriz_colunas){
  int i=0, bolinha=0, subtraindo=0, pulos_sob_cones=0, aux_printar=0;
	int N=0,S=0,L=0,O=0,NE=0,SE=0,SO=0,NO=0;

  while(comandos[i]!='\0'){
		int N1=0,S1=0,L1=0,O1=0,NE1=0,SE1=0, SO1=0,NO1=0;
    int rotacao = 0;
		int cones=0;
		//atribui a rotação total pela sequencia de comandos dados
    while(comandos[i]!='F'){
			if(comandos[i]=='S'){
				break;
			}
			if(comandos[i]=='\0'){
				printar(N,S,L,O,NE,SE,SO,NO,bolinha,pulos_sob_cones,0);
				aux_printar+=1;
				break;
			}
      if(comandos[i]=='D'){
        rotacao+=45;
      }
      else if(comandos[i]=='E'){
        rotacao-=45;
      }
      i++;
    }
		if(comandos[i]=='\0'){
			break;
		}
    if(comandos[i]=='F'){
      subtraindo = 1;
    }
    if(comandos[i]=='S'){
      subtraindo = 2;
    }

    rotacao = rotacao_equivalente(rotacao);
		int linha_pulo=linha, coluna_pulo=coluna;
		posmove(vet, rotacao, inicial, 1 ,&linha,&coluna, &cones,&N1,&S1,&L1,&O1,&NE1,&SE1,&SO1,&NO1);

		if(comandos[i]=='F' && cones==0 && linha>=0 && linha<matriz_linhas && coluna>=0 && coluna<matriz_colunas){
			N+=N1;S+=S1;L+=L1;O+=O1;NE+=NE1;SE+=SE1;SO+=SO1;NO+=NO1;
				if(vet[linha][coluna]=='*'){
							bolinha++;
				}
		}

		if(comandos[i]=='S'){
    if(analisador_de_movimentacao_pulo(vet, rotacao, inicial, 2, matriz_linhas, matriz_colunas, linha_pulo , coluna_pulo)==1){
					pulos_sob_cones+=cones;
					switch (rotacao){
						case(0):
							if(inicial[0]=='N' && inicial[1]=='E'){
								linha_pulo-=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='E'){
								linha_pulo+=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='O'){
								linha_pulo+=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='N' && inicial[1]=='O'){
								linha_pulo-=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='N'){
								linha_pulo-=subtraindo;
							}
							else if(inicial[0]=='S'){
								linha_pulo+=subtraindo;
							}
							else if(inicial[0]=='L'){
								coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='O'){
								coluna_pulo-=subtraindo;
							}
							break;
						case(45):
							if(inicial[0]=='N' && inicial[1]=='E'){
								coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='E'){
								linha_pulo+=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='O'){
								coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='N' && inicial[1]=='O'){
								linha_pulo-=subtraindo;
							}
							else if(inicial[0]=='N'){
								linha_pulo-=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='S'){
								linha_pulo+=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='L'){
								coluna_pulo+=subtraindo;linha_pulo+=subtraindo;
							}
							else if(inicial[0]=='O'){
								coluna_pulo-=subtraindo;linha_pulo-=subtraindo;
							}
							break;
						case(90):
							if(inicial[0]=='N' && inicial[1]=='E'){
								linha_pulo+=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='E'){
								linha_pulo+=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='O'){
								linha_pulo-=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='N' && inicial[1]=='O'){
								linha_pulo-=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='N'){
								coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='S'){
								coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='L'){
								linha_pulo+=subtraindo;
							}
							else if(inicial[0]=='O'){
								linha_pulo-=subtraindo;
							}
							break;
						case(135):
							if(inicial[0]=='N' && inicial[1]=='E'){
								linha_pulo+=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='E'){
								coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='O'){
								linha_pulo-=subtraindo;
							}
							else if(inicial[0]=='N' && inicial[1]=='O'){
								coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='N'){
								linha_pulo+=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='S'){
								linha_pulo-=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='L'){
								coluna_pulo+=subtraindo;linha_pulo-=subtraindo;
							}
							else if(inicial[0]=='O'){
								coluna_pulo-=subtraindo;linha_pulo+=subtraindo;
							}
							break;
						case(180):
							if(inicial[0]=='N' && inicial[1]=='E'){
								linha_pulo+=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='E'){
								linha_pulo-=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='O'){
								linha_pulo-=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='N' && inicial[1]=='O'){
								linha_pulo+=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='N'){
								linha_pulo+=subtraindo;
							}
							else if(inicial[0]=='S'){
								linha_pulo-=subtraindo;
							}
							else if(inicial[0]=='L'){
								coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='O'){
								coluna_pulo+=subtraindo;
							}
							break;
						case(225):
							if(inicial[0]=='N' && inicial[1]=='E'){
								coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='E'){
								linha_pulo-=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='O'){
								coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='N' && inicial[1]=='O'){
								linha_pulo+=subtraindo;
							}
							else if(inicial[0]=='N'){
								linha_pulo-=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='S'){
								linha_pulo-=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='L'){
								coluna_pulo-=subtraindo;linha_pulo-=subtraindo;
							}
							else if(inicial[0]=='O'){
								coluna_pulo+=subtraindo;linha_pulo+=subtraindo;
							}
							break;
						case(270):
							if(inicial[0]=='N' && inicial[1]=='E'){
								linha_pulo-=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='E'){
								linha_pulo-=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='O'){
								linha_pulo+=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='N' && inicial[1]=='O'){
								linha_pulo+=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='N'){
								coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='S'){
								coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='L'){
								linha_pulo-=subtraindo;
							}
							else if(inicial[0]=='O'){
								linha_pulo+=subtraindo;
							}
							break;
						case(315):
							if(inicial[0]=='N' && inicial[1]=='E'){
								linha_pulo-=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='E'){
								coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='S' && inicial[1]=='O'){
								linha_pulo+=subtraindo;
							}
							else if(inicial[0]=='N' && inicial[1]=='O'){
								coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='N'){
								linha_pulo-=subtraindo;coluna_pulo-=subtraindo;
							}
							else if(inicial[0]=='S'){
								linha_pulo+=subtraindo;coluna_pulo+=subtraindo;
							}
							else if(inicial[0]=='L'){
								coluna_pulo+=subtraindo;linha_pulo-=subtraindo;
							}
							else if(inicial[0]=='O'){
								coluna_pulo-=subtraindo;linha_pulo+=subtraindo;
							}
							break;
					}
							if(vet[linha_pulo][coluna_pulo]=='*'){
				          	bolinha++;
				    	}
						}
				}

    i++;
  }
  	if(aux_printar==0){
  printar(N,S,L,O,NE,SE,SO,NO,bolinha,pulos_sob_cones,0);
	}
}

int rotacao_equivalente(int rotacao){
	if(rotacao==360 || rotacao==0 || rotacao==720 || rotacao==1080){
		return 0;
	}
	else if(rotacao==45 || rotacao==405 || rotacao==765 || rotacao==-315){
		return 45;
	}
	else if(rotacao==90 || rotacao==450 || rotacao==810 || rotacao==-270){
		return 90;
	}
	else if(rotacao==135 || rotacao==495 || rotacao==855 || rotacao==-225){
		return 135;
	}
	else if(rotacao==180 || rotacao==540 || rotacao==900 || rotacao==-180){
		return 180;
	}
	else if(rotacao==225 || rotacao==585 || rotacao==945 || rotacao==-135){
		return 225;
	}
	else if(rotacao==270 || rotacao==630 || rotacao==990 || rotacao==-90){
		return 270;
	}
	else if(rotacao==315 || rotacao==675 || rotacao==1035 || rotacao==-45){
		return 315;
	}
}

int analisador_de_movimentacao_pulo(char **vet, int rotacao, char inicial[], int subtraindo, int matriz_linhas, int matriz_colunas, int linha, int coluna){
	switch (rotacao){
	    case(0):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha-=subtraindo;coluna+=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha+=subtraindo;coluna+=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha+=subtraindo;coluna-=subtraindo;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha-=subtraindo;coluna-=subtraindo;
	      }
				else if(inicial[0]=='N'){
	        linha-=subtraindo;
	      }
	      else if(inicial[0]=='S'){
	        linha+=subtraindo;
	      }
	      else if(inicial[0]=='L'){
	        coluna+=subtraindo;
	      }
	      else if(inicial[0]=='O'){
	        coluna-=subtraindo;
	      }
	      break;
	    case(45):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        coluna-=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha+=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        coluna-=subtraindo;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha-=subtraindo;
	      }
				else if(inicial[0]=='N'){
	        linha-=subtraindo;coluna+=subtraindo;
	      }
	      else if(inicial[0]=='S'){
	        linha+=subtraindo;coluna-=subtraindo;
	      }
	      else if(inicial[0]=='L'){
	        coluna+=subtraindo;linha+=subtraindo;
	      }
	      else if(inicial[0]=='O'){
	        coluna-=subtraindo;linha-=subtraindo;
	      }
	      break;
	    case(90):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha+=subtraindo;coluna+=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha+=subtraindo;coluna-=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha-=subtraindo;coluna-=subtraindo;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha-=subtraindo;coluna+=subtraindo;
	      }
				else if(inicial[0]=='N'){
	        coluna+=subtraindo;
	      }
	      else if(inicial[0]=='S'){
	        coluna-=subtraindo;
	      }
	      else if(inicial[0]=='L'){
	        linha+=subtraindo;
	      }
	      else if(inicial[0]=='O'){
	        linha-=subtraindo;
	      }
	      break;
	    case(135):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha+=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        coluna-=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha-=subtraindo;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        coluna-=subtraindo;
	      }
				else if(inicial[0]=='N'){
					linha+=subtraindo;coluna+=subtraindo;
				}
				else if(inicial[0]=='S'){
					linha-=subtraindo;coluna-=subtraindo;
				}
				else if(inicial[0]=='L'){
					coluna+=subtraindo;linha-=subtraindo;
				}
				else if(inicial[0]=='O'){
					coluna-=subtraindo;linha+=subtraindo;
				}
	      break;
	    case(180):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha+=subtraindo;coluna-=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha-=subtraindo;coluna-=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha-=subtraindo;coluna+=subtraindo;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha+=subtraindo;coluna+=subtraindo;
	      }
				else if(inicial[0]=='N'){
	        linha+=subtraindo;
	      }
	      else if(inicial[0]=='S'){
	        linha-=subtraindo;
	      }
	      else if(inicial[0]=='L'){
	        coluna-=subtraindo;
	      }
	      else if(inicial[0]=='O'){
	        coluna+=subtraindo;
	      }
	      break;
	    case(225):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        coluna-=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha-=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        coluna+=subtraindo;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha+=subtraindo;
	      }
				else if(inicial[0]=='N'){
	        linha-=subtraindo;coluna+=subtraindo;
	      }
	      else if(inicial[0]=='S'){
	        linha-=subtraindo;coluna+=subtraindo;
	      }
	      else if(inicial[0]=='L'){
	        coluna-=subtraindo;linha-=subtraindo;
	      }
	      else if(inicial[0]=='O'){
	        coluna+=subtraindo;linha+=subtraindo;
	      }
	      break;
	    case(270):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha-=subtraindo;coluna-=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha-=subtraindo;coluna+=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha+=subtraindo;coluna+=subtraindo;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha+=subtraindo;coluna-=subtraindo;
	      }
				else if(inicial[0]=='N'){
	        coluna-=subtraindo;
	      }
	      else if(inicial[0]=='S'){
	        coluna+=subtraindo;
	      }
	      else if(inicial[0]=='L'){
	        linha-=subtraindo;
	      }
	      else if(inicial[0]=='O'){
	        linha+=subtraindo;
	      }
	      break;
	    case(315):
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha-=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        coluna+=subtraindo;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha+=subtraindo;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        coluna-=subtraindo;
	      }
				else if(inicial[0]=='N'){
	        linha-=subtraindo;coluna-=subtraindo;
	      }
	      else if(inicial[0]=='S'){
	        linha+=subtraindo;coluna+=subtraindo;
	      }
	      else if(inicial[0]=='L'){
	        coluna+=subtraindo;linha-=subtraindo;
	      }
	      else if(inicial[0]=='O'){
	        coluna-=subtraindo;linha+=subtraindo;
	      }
	      break;
	  }

  if(linha < 0 || linha >= matriz_linhas || coluna < 0 || coluna >= matriz_colunas){
    return 0;
  }
	else if(vet[linha][coluna]=='#'){
		return 0;
	}
  else{
		return 1;
	}
}

void printar(int N,int S,int L,int O,int NE,int SE,int SO,int NO,int bolinha, int pulos_sob_cones, int t1){
		if(casos==0){
			arquivo=fopen("saida.txt", "w");
		}
		if(t1==1){
			fclose(arquivo);
		}
		fprintf(arquivo, "Caso %d:\nBolinhas coletadas = %d.\nSaltos sobre cones = %d.\nAndou para frente:\nN: %d, NE: %d, L: %d, SE: %d, S: %d, SO: %d, O: %d, NO: %d\n\n", casos+=1, bolinha, pulos_sob_cones, N , NE, L , SE, S , SO , O , NO);
}