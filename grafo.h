#include <stdbool.h>
#ifndef GRAFO_H
#define GRAFO_H


/* Struct */
typedef struct grafoP Grafo;

typedef struct soluc Solucao;



/* Aloca a struct */
Grafo* alocarGrafo();
Solucao* alocarSolucao();
int* alocaVetor(int n);
int** alocaMatriz(int n);

void preencheSolucao(Solucao*, int);
void preencheSolucaoAux(Solucao*, int);
void preencheGrafo(Grafo*, int);

/* Desaloca a struct */
void desalocarGrafo(Grafo* grafo);
void desalocaMatriz(int** mat, int n);
void desalocaSolucao(Solucao* soluc);
void desalocaVetor(int* vet);

/* Le os dados */
void leGrafo(Grafo* grafo);

/* Percorre as cidades */
void encontraCaminho(Grafo *grafo, Solucao *result, Solucao *aux, int x);
void trocaResultado(Solucao* dest, Solucao* source, int x);
bool caminhoValido(Grafo* grafo, Solucao *soluc, int x, int orig, int dest);

/* Imprime o caminho */
void imprimeCaminho(Solucao* soluc, int n);

void imprimeGrafo(Grafo* grafo, int n);

#endif