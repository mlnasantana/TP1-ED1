#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_TAM 10000
#include "grafo.h"

struct grafoP{
    int cidades;  /*armazena a quantidade de cidades*/
    int **matriz; /*armazena distancia entre as cidades, 0 caminho nulo, indice é  o numero da cidade*/
};

struct soluc{
    int *menorCa;
    int custo;
};


/* Aloca solução*/ /*falha de segmentação n é aq*/
Solucao* alocarSolucao(int n) {/*aloca as cidades primeiro q o grafo*/
    return malloc(sizeof(Solucao));
}

void preencheSolucao(Solucao* soluc, int n) {
    soluc->custo = MAX_TAM;
    soluc->menorCa = alocaVetor(n);
    soluc->menorCa[0] = 0;
}

void preencheSolucaoAux(Solucao* soluc, int n) {
    preencheSolucao(soluc, n);
    soluc->custo = 0;
}

void preencheGrafo(Grafo* grafo, int n) {
    grafo->matriz = alocaMatriz(n);
    grafo->cidades = n;
}

int** alocaMatriz(int n) {
    int** mat = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
       mat[i] = malloc(n * sizeof(int));
    }
    return mat;
}

int* alocaVetor (int n) {
    int* vet = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        vet[i] = -1;
    }
    return vet;
}

/* Aloca a struct */ /*falha de segmentação não é nessa aq*/
Grafo* alocarGrafo(int cidades){ /*aloca as cidades primeiro q o grafo*/
    return malloc(sizeof(Grafo));; /*retorna a estrutura alocada*/
}

/* Desaloca a struct */
void desalocarGrafo(Grafo *grafo){
    desalocaMatriz(grafo->matriz, grafo->cidades);
    free(grafo);
}


void desalocaSolucao(Solucao *soluc){
    desalocaVetor(soluc->menorCa);
    free(soluc);
}

void desalocaMatriz(int** mat, int n) {
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}


void desalocaVetor(int *vet){
    free(vet);
}

/* Le os dados */
void leGrafo(Grafo *grafo){
    int origem, destino, distancia, med;
    med = grafo->cidades * grafo->cidades;
    for (int i = 0; i < med; i++){ /*percorre as cidade de origem*/
        scanf("%d %d %d", &origem, &destino, &distancia);
        grafo->matriz[origem][destino] = distancia;
    }
}

    /* Percorre as cidades */
    void encontraCaminho(Grafo *grafo, Solucao *result, Solucao *aux, int x)
{
    if (x == grafo->cidades && grafo->matriz[aux->menorCa[x - 1]][0] != 0){
        aux->custo += grafo->matriz[aux->menorCa[x - 1]][0];
        trocaResultado(aux, result, grafo->cidades);
        aux->custo -= grafo->matriz[aux->menorCa[x - 1]][0];
        return;
    }
    for (int i = 0; i < grafo->cidades; i++) {
        if (caminhoValido(grafo, aux, x, aux->menorCa[x - 1], i)) {
            aux->menorCa[x] = i;
            aux->custo += grafo->matriz[aux->menorCa[x - 1]][i];
            encontraCaminho(grafo, result, aux, x + 1);
            aux->custo -= grafo->matriz[aux->menorCa[x - 1]][i];
        }
    }
}

bool caminhoValido(Grafo* grafo, Solucao *soluc, int x, int orig, int dest) {
    for (int i = 0; i < x; i++)
        if ((soluc->menorCa[i] == dest) || (grafo->matriz[orig][dest] == 0))
            return false;    
    return true;
}


void trocaResultado(Solucao *aux, Solucao *result, int x){
    if (aux->custo < result->custo) {
        for (int i = 0; i < x; i++)
            result->menorCa[i] = aux->menorCa[i];
        result->custo = aux->custo;
    }
}


/* Imprime o caminho */
void imprimeCaminho(Solucao* soluc, int n){
    for (int i = 0; i < n ; i++) {
        printf("%d ", soluc->menorCa[i]);
    }
    printf("0\n");
    printf("%d\n", soluc->custo);
}


void imprimeGrafo(Grafo* grafo, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            printf("%d ", grafo->matriz[i][j]);
        }
        printf("\n");
    }
}
