#ifndef MATRIZ_H
#define MATRIZ_H

int **criar_matriz (int linhas,int colunas);

void iniciar_matriz(int **m,int linhas,int colunas);

void imprimir_matriz(int **m, int linhas, int colunas);

void liberar_matriz(int **m, int linhas, int colunas);

#endif
//int *f (int) retorna um vetor int (*f)(int)chamada de função