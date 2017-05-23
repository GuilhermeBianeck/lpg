#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct{
	int linhas;
	int colunas;
	int **m;
} TMatriz;

/* funcoes para manipular a matriz */
TMatriz *criar_matriz(int linhas, int colunas, int **(*f)(int, int));
void iniciar_matriz(TMatriz *	mat);
void imprimir_matriz(TMatriz *mat);
void liberar_matriz(TMatriz *mat, void (*f)(int **, int));

/* funcoes para manipular dados */
int **dados_bloco(int l, int c);
int **dados_distribuida(int l, int c);
void liberar_dados_bloco(int **m, int l);
void liberar_dados_distribuida(int **m, int l);	

#endif
