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

void posmove(Rodada *rod, int rotacao,char inicial[], int sub,int *linha,int *coluna,int *cones,int *N,int *S,int *L,int *O,int *NE,int *SE,int *SO,int *NO);
int analisar(Rodada *rod);
int rotacao_equivalente(int rotacao);
int analisador_de_movimentacao_pulo(Rodada *rod, int rotacao, char inicial[], int sub, int linha, int coluna);
void contador(Rodada *rod, int linha, int coluna, char inicial[]);
void imprimir(int N,int S,int L,int O,int NE,int SE,int SO,int NO,int bolinha, int pulos_sob_cones, int t1);



#endif
