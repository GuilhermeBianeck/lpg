#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"

//A primeira e a ultima letra estão sempre corretos
//em caso de mais de uma resposta, fornecer o primeiro (alfebeticamente)
//Quando nenhuma entrada for encontrada, substitua por um " "

char  **criar_matriz(int c, int l);
char *filtro(char **dicionario,char *input, int tam);
int t_string(char *string);
//void fres(char **dicionario);

int main(void){
  char *output,input[1000],**dicionario=NULL;
  int tam=0;
  scanf("%s",input);
  inicializar_dicionario();
  dicionario=criar_matriz(100,30);
  dicionario=pegar_dicionario();
  tam=t_string(input);
  output=filtro(dicionario,input,tam);
  printf("%s\n",output);
  //fres(dicionario);

  return 0;
}

int t_string(char *string)
{
    int t=0;

    while( string[t] != '\0')
        t++;
    return t;
}

char *filtro(char **dicionario, char *input,int tam){
  int i,j,k,p=1,pf[50],l=0;
  char *menor;

  for(i=0; i< tamanho_dicionario(); i++){
    if(input[0]==dicionario[i][0] && input[tam-1] == dicionario[i][t_string(dicionario[i])-1]){

      for(p=0,k=0; p<tam-1; p++){
        if (k<t_string(dicionario[i])){
          if(input[p]==dicionario[i][k]){
          k++;
          }
        }
        
        if (k==t_string(dicionario[i])-1){    
          pf[l]=i;
          l++;
        }
      }
    }
  }

  menor = dicionario[pf[0]];

  if (l>1){

    for (i = 0; i < l-1; i++){
      	for (j = 0; j < t_string(dicionario[pf[i]]); j++)
      	{
       	 if (j<t_string(dicionario[pf[i+1]])){
       	   if (dicionario[pf[i]][j]>dicionario[pf[i+1]][j]){
             menor=dicionario[pf[i+1]];
             break;
        	}
         }


   	    }
	}
    return menor;
     
  }else if (l==1){
      return menor;
  }
  return(" ");
}

char **criar_matriz(int l, int c)
{
  char **ret=NULL;
  int i=0;

  if(!(ret=(char**)malloc(sizeof(char *)*l))){
    return NULL;
  }

  for (i=0;i<l;i++){
    ret[i]=(char *)malloc(sizeof(char)*c);
    if(!(*(ret[i]))){
      return NULL;
    }
  }
  return ret;
}

/*void fres(char **dicionario)
{
	int i;
	for(i=0;i<100;i++){
		free(dicionario[i]);
	}
  free(dicionario);
}

*/