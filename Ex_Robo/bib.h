#ifndef bib_h
#define bib_h

#define DIRECOES 8
typedef struct{
	int N,M,S;
	char **arena;
	char *comandos;
	int bolinhas;
	int saltos_sobre_cones;
	int contadores[DIRECOES];
}Rodada;

Rodada *rod;

void posmove(char **vet, int rotacao,char inicial[], int subtraindo,int *linha,int *coluna,int *cones,int *N,int *S,int *L,int *O,int *NE,int *SE,int *SO,int *NO);
int analisar(char *palavra);
int rotacao_equivalente(int rotacao);
int analisador_de_movimentacao_pulo(char **vet, int rotacao, char inicial[], int subtraindo, int matriz_linhas, int matriz_colunas, int linha, int coluna);
void contador(char **vet, int linha, int coluna, char inicial[],char comandos[], int matriz_linhas, int matriz_colunas);
void printar(int N,int S,int L,int O,int NE,int SE,int SO,int NO,int bolinha, int pulos_sob_cones, int t1);



#endif
