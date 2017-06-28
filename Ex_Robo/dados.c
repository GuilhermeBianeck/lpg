#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bib.h"

FILE *arquivo = NULL;
int casos=0;

int analisar(Rodada *rod){
    int i;
    for(i=0;i<strlen(rod->comandos);i++){
        if(rod->comandos[i]=='F' || rod->comandos[i]=='S'){
            return 1;
        }
    }
    return 0;
}

void posmove(Rodada *rod, int rotacao,char inicial[], int sub,int *linha,int *coluna,int *cones,int *N,int *S,int *L,int *O,int *NE,int *SE,int *SO,int *NO){
	if (rotacao==0){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha-=sub;*coluna+=sub;
	        *NE+1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha+=sub;*coluna+=sub;
	        *SE+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha+=sub;*coluna-=sub;
	        *SO+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha-=sub;*coluna-=sub;
	        *NO+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha-=sub;
	        *N+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha+=sub;
	        *S+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna+=sub;
	        *L+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna-=sub;
	        *O+=1;
	      }
		}
	    if (rotacao==45){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *coluna-=sub;
	        *L+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha+=sub;
	        *S+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *coluna-=sub;
	        *O+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha-=sub;
	        *N+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha-=sub;*coluna+=sub;
	        *NE+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha+=sub;*coluna-=sub;
	        *SO+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna+=sub;*linha+=sub;
	        *SE+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna-=sub;*linha-=sub;
	        *NO+=1;
	      }
		}
	    if (rotacao==90){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha+=sub;*coluna+=sub;
	        *SE+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha+=sub;*coluna-=sub;
	        *SO+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha-=sub;*coluna-=sub;
	        *NO+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha-=sub;*coluna+=sub;
	        *NE+=1;
	      }
	      else if(inicial[0]=='N'){
	        *coluna+=sub;
	        *L+=1;
	      }
	      else if(inicial[0]=='S'){
	        *coluna-=sub;
	        *O+=1;
	      }
	      else if(inicial[0]=='L'){
	        *linha+=sub;
	        *S+=1;
	      }
	      else if(inicial[0]=='O'){
	        *linha-=sub;
	        *N+=1;
	      }
		}
	    if (rotacao==135){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha+=sub;
	        *S+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *coluna-=sub;
	        *O+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha-=sub;
	        *N+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *coluna-=sub;
	        *L+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha+=sub;*coluna+=sub;
	        *SE+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha-=sub;*coluna-=sub;
	        *NO+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna+=sub;*linha-=sub;
	        *SO+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna-=sub;*linha+=sub;
	        *NE+=1;
	      }
	  	}
	    if (rotacao==180){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha+=sub;*coluna-=sub;
	        *SO+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha-=sub;*coluna-=sub;
	        *NO+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha-=sub;*coluna+=sub;
	        *NE+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha+=sub;*coluna+=sub;
	        *SE+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha+=sub;
	        *S+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha-=sub;
	        *N+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna-=sub;
	        *O+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna+=sub;
	        *L+=1;
	      }
	  	}
	    if (rotacao==225){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *coluna-=sub;
	        *O+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha-=sub;
	        *N+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *coluna+=sub;
	        *L+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha+=sub;
	        *S+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha-=sub;*coluna+=sub;
	        *SO+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha-=sub;*coluna+=sub;
	        *NE+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna-=sub;*linha-=sub;
	        *NO+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna+=sub;*linha+=sub;
	        *SE+=1;
	      }
	  	}
	    if (rotacao==270){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha-=sub;*coluna-=sub;
	        *NO+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *linha-=sub;*coluna+=sub;
	        *NE+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha+=sub;*coluna+=sub;
	        *SE+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *linha+=sub;*coluna-=sub;
	        *SO+=1;
	      }
	      else if(inicial[0]=='N'){
	        *coluna-=sub;
	        *O+=1;
	      }
	      else if(inicial[0]=='S'){
	        *coluna+=sub;
	        *L+=1;
	      }
	      else if(inicial[0]=='L'){
	        *linha-=sub;
	        *N+=1;
	      }
	      else if(inicial[0]=='O'){
	        *linha+=sub;
	        *S+=1;
	      }
		}
	    if (rotacao==315){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        *linha-=sub;
	        *N+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        *coluna+=sub;
	        *L+=1;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        *linha+=sub;
	        *S+=1;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        *coluna-=sub;
	        *O+=1;
	      }
	      else if(inicial[0]=='N'){
	        *linha-=sub;*coluna-=sub;
	        *NO+=1;
	      }
	      else if(inicial[0]=='S'){
	        *linha+=sub;*coluna+=sub;
	        *SE+=1;
	      }
	      else if(inicial[0]=='L'){
	        *coluna+=sub;*linha-=sub;
	        *NE+=1;
	      }
	      else if(inicial[0]=='O'){
	        *coluna-=sub;*linha+=sub;
	        *SO+=1;
	      }
	  }
	if(rod->arena[*linha][*coluna]=='#'){
	  *cones+=1;
	}
}

void contador(Rodada *rod, int linha, int coluna, char inicial[]){
  int i=0, bolinha=0, sub=0, pulos_sob_cones=0, aux_imprimir=0;
	int N=0,S=0,L=0,O=0,NE=0,SE=0,SO=0,NO=0;

  while(rod->comandos[i]!='\0'){
		int N1=0,S1=0,L1=0,O1=0,NE1=0,SE1=0, SO1=0,NO1=0;
    int rotacao = 0;
		int cones=0;
		//atribui a rotação total pela sequencia de rod->comandos dados
    while(rod->comandos[i]!='F'){
			if(rod->comandos[i]=='S'){
				break;
			}
			if(rod->comandos[i]=='\0'){
				imprimir(N,S,L,O,NE,SE,SO,NO,bolinha,pulos_sob_cones,0);
				aux_imprimir+=1;
				break;
			}
      if(rod->comandos[i]=='D'){
        rotacao+=45;
      }
      else if(rod->comandos[i]=='E'){
        rotacao-=45;
      }
      i++;
    }
		if(rod->comandos[i]=='\0'){
			break;
		}
    if(rod->comandos[i]=='F'){
      sub = 1;
    }
    if(rod->comandos[i]=='S'){
      sub = 2;
    }

    rotacao = rotacao_equivalente(rotacao);
		int linha_pulo=linha, coluna_pulo=coluna;
		posmove(rod, rotacao, inicial, 1 ,&linha,&coluna, &cones,&N1,&S1,&L1,&O1,&NE1,&SE1,&SO1,&NO1);

		if(rod->comandos[i]=='F' && cones==0 && linha>=0 && linha<rod->N && coluna>=0 && coluna<rod->M){
			N+=N1;S+=S1;L+=L1;O+=O1;NE+=NE1;SE+=SE1;SO+=SO1;NO+=NO1;
				if(rod->arena[linha][coluna]=='*'){
							bolinha++;
				}
		}

		if(rod->comandos[i]=='S'){
    if(analisador_de_movimentacao_pulo(rod, rotacao, inicial, 2, linha_pulo , coluna_pulo)==1){
					pulos_sob_cones+=cones;
		if (rotacao==0){
			if(inicial[0]=='N' && inicial[1]=='E'){
				linha_pulo-=sub;coluna_pulo+=sub;
				}
				else if(inicial[0]=='S' && inicial[1]=='E'){
					linha_pulo+=sub;coluna_pulo+=sub;
					}
				else if(inicial[0]=='S' && inicial[1]=='O'){
					linha_pulo+=sub;coluna_pulo-=sub;
					}
				else if(inicial[0]=='N' && inicial[1]=='O'){
					linha_pulo-=sub;coluna_pulo-=sub;
				}
				else if(inicial[0]=='N'){
					linha_pulo-=sub;
				}
				else if(inicial[0]=='S'){
					linha_pulo+=sub;
				}
				else if(inicial[0]=='L'){
					coluna_pulo+=sub;
				}
				else if(inicial[0]=='O'){
					coluna_pulo-=sub;
				}
		}
		if (rotacao==45){
			if(inicial[0]=='N' && inicial[1]=='E'){
				coluna_pulo-=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='E'){
				linha_pulo+=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='O'){
				coluna_pulo-=sub;
			}
			else if(inicial[0]=='N' && inicial[1]=='O'){
				linha_pulo-=sub;
			}
			else if(inicial[0]=='N'){
				linha_pulo-=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='S'){
				linha_pulo+=sub;coluna_pulo-=sub;
			}
			else if(inicial[0]=='L'){
				coluna_pulo+=sub;linha_pulo+=sub;
			}
			else if(inicial[0]=='O'){
				coluna_pulo-=sub;linha_pulo-=sub;
			}
		}
		if (rotacao==90){
			if(inicial[0]=='N' && inicial[1]=='E'){
				linha_pulo+=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='E'){
				linha_pulo+=sub;coluna_pulo-=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='O'){
				linha_pulo-=sub;coluna_pulo-=sub;
			}
			else if(inicial[0]=='N' && inicial[1]=='O'){
				linha_pulo-=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='N'){
				coluna_pulo+=sub;
			}
			else if(inicial[0]=='S'){
				coluna_pulo-=sub;
			}
			else if(inicial[0]=='L'){
				linha_pulo+=sub;
			}
			else if(inicial[0]=='O'){
				linha_pulo-=sub;
			}
		}
		if (rotacao==135){
			if(inicial[0]=='N' && inicial[1]=='E'){
				linha_pulo+=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='E'){
				coluna_pulo-=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='O'){
				linha_pulo-=sub;
			}
			else if(inicial[0]=='N' && inicial[1]=='O'){
				coluna_pulo-=sub;
			}
			else if(inicial[0]=='N'){
				linha_pulo+=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='S'){
				linha_pulo-=sub;coluna_pulo-=sub;
			}
			else if(inicial[0]=='L'){
				coluna_pulo+=sub;linha_pulo-=sub;
			}
			else if(inicial[0]=='O'){
				coluna_pulo-=sub;linha_pulo+=sub;
			}
		}
		if (rotacao==180){
			if(inicial[0]=='N' && inicial[1]=='E'){
				linha_pulo+=sub;coluna_pulo-=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='E'){
				linha_pulo-=sub;coluna_pulo-=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='O'){
				linha_pulo-=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='N' && inicial[1]=='O'){
				linha_pulo+=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='N'){
				linha_pulo+=sub;
			}
			else if(inicial[0]=='S'){
				linha_pulo-=sub;
			}
			else if(inicial[0]=='L'){
				coluna_pulo-=sub;
			}
			else if(inicial[0]=='O'){
				coluna_pulo+=sub;
			}
		}
		if (rotacao==225){
			if(inicial[0]=='N' && inicial[1]=='E'){
				coluna_pulo-=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='E'){
				linha_pulo-=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='O'){
				coluna_pulo+=sub;
			}
			else if(inicial[0]=='N' && inicial[1]=='O'){
				linha_pulo+=sub;
			}
			else if(inicial[0]=='N'){
				linha_pulo-=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='S'){
				linha_pulo-=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='L'){
				coluna_pulo-=sub;linha_pulo-=sub;
			}
			else if(inicial[0]=='O'){
				coluna_pulo+=sub;linha_pulo+=sub;
			}
		}
		if (rotacao==270){
			if(inicial[0]=='N' && inicial[1]=='E'){
				linha_pulo-=sub;coluna_pulo-=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='E'){
				linha_pulo-=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='O'){
				linha_pulo+=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='N' && inicial[1]=='O'){
				linha_pulo+=sub;coluna_pulo-=sub;
			}
			else if(inicial[0]=='N'){
				coluna_pulo-=sub;
			}
			else if(inicial[0]=='S'){
				coluna_pulo+=sub;
			}
			else if(inicial[0]=='L'){
				linha_pulo-=sub;
			}
			else if(inicial[0]=='O'){
				linha_pulo+=sub;
			}
		}
		if (rotacao==315){
			if(inicial[0]=='N' && inicial[1]=='E'){
				linha_pulo-=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='E'){
				coluna_pulo+=sub;
			}
			else if(inicial[0]=='S' && inicial[1]=='O'){
				linha_pulo+=sub;
			}
			else if(inicial[0]=='N' && inicial[1]=='O'){
				coluna_pulo-=sub;
			}
			else if(inicial[0]=='N'){
				linha_pulo-=sub;coluna_pulo-=sub;
			}
			else if(inicial[0]=='S'){
				linha_pulo+=sub;coluna_pulo+=sub;
			}
			else if(inicial[0]=='L'){
				coluna_pulo+=sub;linha_pulo-=sub;
			}
			else if(inicial[0]=='O'){
				coluna_pulo-=sub;linha_pulo+=sub;
			}
		}
		if(rod->arena[linha_pulo][coluna_pulo]=='*'){
			bolinha++;
		}
	}
	}

    i++;
  }
  	if(aux_imprimir==0){
  imprimir(N,S,L,O,NE,SE,SO,NO,bolinha,pulos_sob_cones,0);
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

int analisador_de_movimentacao_pulo(Rodada *rod, int rotacao, char inicial[], int sub, int linha, int coluna){
	if (rotacao==0){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha-=sub;coluna+=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha+=sub;coluna+=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha+=sub;coluna-=sub;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha-=sub;coluna-=sub;
	      }
				else if(inicial[0]=='N'){
	        linha-=sub;
	      }
	      else if(inicial[0]=='S'){
	        linha+=sub;
	      }
	      else if(inicial[0]=='L'){
	        coluna+=sub;
	      }
	      else if(inicial[0]=='O'){
	        coluna-=sub;
	      }
	  	}
	    if(rotacao==45){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        coluna-=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha+=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        coluna-=sub;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha-=sub;
	      }
				else if(inicial[0]=='N'){
	        linha-=sub;coluna+=sub;
	      }
	      else if(inicial[0]=='S'){
	        linha+=sub;coluna-=sub;
	      }
	      else if(inicial[0]=='L'){
	        coluna+=sub;linha+=sub;
	      }
	      else if(inicial[0]=='O'){
	        coluna-=sub;linha-=sub;
	      }
		}
	    if(rotacao==90){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha+=sub;coluna+=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha+=sub;coluna-=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha-=sub;coluna-=sub;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha-=sub;coluna+=sub;
	      }
				else if(inicial[0]=='N'){
	        coluna+=sub;
	      }
	      else if(inicial[0]=='S'){
	        coluna-=sub;
	      }
	      else if(inicial[0]=='L'){
	        linha+=sub;
	      }
	      else if(inicial[0]=='O'){
	        linha-=sub;
	      }
		}
		if(rotacao==135){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha+=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        coluna-=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha-=sub;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        coluna-=sub;
	      }
				else if(inicial[0]=='N'){
					linha+=sub;coluna+=sub;
				}
				else if(inicial[0]=='S'){
					linha-=sub;coluna-=sub;
				}
				else if(inicial[0]=='L'){
					coluna+=sub;linha-=sub;
				}
				else if(inicial[0]=='O'){
					coluna-=sub;linha+=sub;
				}
		}
	    if(rotacao==180){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha+=sub;coluna-=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha-=sub;coluna-=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha-=sub;coluna+=sub;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha+=sub;coluna+=sub;
	      }
				else if(inicial[0]=='N'){
	        linha+=sub;
	      }
	      else if(inicial[0]=='S'){
	        linha-=sub;
	      }
	      else if(inicial[0]=='L'){
	        coluna-=sub;
	      }
	      else if(inicial[0]=='O'){
	        coluna+=sub;
	      }
	    }
	    if(rotacao==225){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        coluna-=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha-=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        coluna+=sub;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha+=sub;
	      }
				else if(inicial[0]=='N'){
	        linha-=sub;coluna+=sub;
	      }
	      else if(inicial[0]=='S'){
	        linha-=sub;coluna+=sub;
	      }
	      else if(inicial[0]=='L'){
	        coluna-=sub;linha-=sub;
	      }
	      else if(inicial[0]=='O'){
	        coluna+=sub;linha+=sub;
	      }
	    }
	    if(rotacao==270){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha-=sub;coluna-=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        linha-=sub;coluna+=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha+=sub;coluna+=sub;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        linha+=sub;coluna-=sub;
	      }
				else if(inicial[0]=='N'){
	        coluna-=sub;
	      }
	      else if(inicial[0]=='S'){
	        coluna+=sub;
	      }
	      else if(inicial[0]=='L'){
	        linha-=sub;
	      }
	      else if(inicial[0]=='O'){
	        linha+=sub;
	      }
		}
	    if(rotacao==315){
	      if(inicial[0]=='N' && inicial[1]=='E'){
	        linha-=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='E'){
	        coluna+=sub;
	      }
	      else if(inicial[0]=='S' && inicial[1]=='O'){
	        linha+=sub;
	      }
	      else if(inicial[0]=='N' && inicial[1]=='O'){
	        coluna-=sub;
	      }
				else if(inicial[0]=='N'){
	        linha-=sub;coluna-=sub;
	      }
	      else if(inicial[0]=='S'){
	        linha+=sub;coluna+=sub;
	      }
	      else if(inicial[0]=='L'){
	        coluna+=sub;linha-=sub;
	      }
	      else if(inicial[0]=='O'){
	        coluna-=sub;linha+=sub;
	      }
		}

  if(linha < 0 || linha >= rod->N || coluna < 0 || coluna >= rod->M){
    return 0;
  }
	else if(rod->arena[linha][coluna]=='#'){
		return 0;
	}
  else{
		return 1;
	}
}

void imprimir(int N,int S,int L,int O,int NE,int SE,int SO,int NO,int bolinha, int pulos_sob_cones, int t1){
		if(casos==0){
			arquivo=fopen("saida.txt", "w");
		}
		if(t1==1){
			fclose(arquivo);
		}
		fprintf(arquivo, "Caso %d:\nBolinhas coletadas = %d.\nSaltos sobre cones = %d.\nAndou para frente:\nN: %d, NE: %d, L: %d, SE: %d, S: %d, SO: %d, O: %d, NO: %d\n\n", casos+=1, bolinha, pulos_sob_cones, N , NE, L , SE, S , SO , O , NO);
}
