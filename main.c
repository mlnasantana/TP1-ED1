#include <stdio.h>
#include "grafo.h"

int main () {
    int n, x = 1;
    scanf("%d", &n);
    Solucao* resultado = alocarSolucao();
    Solucao* aux = alocarSolucao();
    Grafo* grafo = alocarGrafo();
    
    preencheSolucao(resultado, n);
    preencheSolucaoAux(aux, n);
    preencheGrafo(grafo, n);
    
    leGrafo(grafo);

    // imprimeCaminho(resultado, n);
    // imprimeCaminho(aux, n);
    // imprimeGrafo(grafo, n);

    encontraCaminho(grafo, resultado, aux, x);

    imprimeCaminho(resultado, n);
    desalocarGrafo(grafo);
    desalocaSolucao(resultado);
    desalocaSolucao(aux);
    return 0;
}