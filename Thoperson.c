#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"

//A primeira e a ultima letra estão sempre corretos
//em caso de mais de uma resposta, fornecer o primeiro (alfebeticamente)
//Quando nenhuma entrada for encontrada, substitua por um " "

char  **criar_matriz(int c, int l);
char *filtro(char *input, int tam);
int t_string(char *string);

int main(void){
  char *output=NULL;
  char *input=NULL;
  int tam;
  printf("%d\n",tam);
  scanf("%s",input);
  printf("%s\n",input );
  tam=t_string(input);
  printf("%d\n",tam);
  output=filtro(input,tam);
  printf("%s\n",output);

  return 0;
}

int t_string(char *string)
{
    int t=0;

    while( string[t] != '\0')
        t++;
    return t;
}

char *filtro(char *input,int tam){p
  int i,j,k,p=1,c=1;
  char **dicionario=NULL;
  char **filtro=NULL;
  inicializar_dicionario();
  dicionario=criar_matriz(100,30);
  dicionario=pegar_dicionario();

  filtro=criar_matriz(100,30);

  for(i=0; i< tamanho_dicionario(); i++){
    if(input[0]==dicionario[i][0] && input[tam] == dicionario[i][t_string(dicionario[i])-1]){

      for(p=1,k=1; p<tam; p++){
        if(input[p]==dicionario[i][k])
          k++;

        if (k==t_string(dicionario[i])-1);
          return dicionario[i]; 

        if (i== tamanho_dicionario()-1)
          return (" ");       

      }
    }
  }
}

char **criar_matriz(int l, int c)
{
  char **ret=NULL;
  int i=0;

  if(!(ret=(char**)malloc(sizeof(char)*l))){
    return NULL;
  }

  for (i=0;i<l;i++){
    *(ret+i)=(char*)malloc(sizeof(char)*c);
    if(!(*(ret+i))){
      return NULL;
    }
  }
  return ret;
}