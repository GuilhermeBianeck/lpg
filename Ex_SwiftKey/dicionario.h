#ifndef _DICIONARIO_H_
#define _DICIONARIO_H_

/*
 * Inicializa as estruturas internas da biblioteca de manipulação do dicionário
 */
void inicializar_dicionario();

/*
 * Informa o número de palavras presentes no dicionário
 */
int tamanho_dicionario();

/*
 * Retorna o dicionário
 */
char **pegar_dicionario();

#endif
