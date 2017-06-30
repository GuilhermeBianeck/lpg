#ifndef Bibliotecas_h
#define Bibliotecas_h



#define DIRECOES 8

typedef struct{
	int N,M,S;
	char **arena;
	char *comandos;
	int bolinhas;
	int saltos_sobre_cones;
	int contadores[DIRECOES];
}Rodada;

Rodada *stc;

void FRealloc (Rodada *stc);
void FMalloc (Rodada *stc);
void FFree (Rodada *stc);
void MovimentarRobo(Rodada *stc, int PosX, int PosY, char *Ori);
int AngCorrespondente(char *Orientacao);
int MovimentarX(int j);
int MovimentarY(int j);





#endif