#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct grafo{
    int **M;
    int nVertices;
} grafo_t;

grafo_t* cria(int nVertices){
    grafo_t *g;
    g = (grafo_t*) malloc(sizeof(grafo_t)); //aloca espaço para a estrutura grafo_t

    //cria a matriz e faz o ponteiro **adjM da matriz grafo_t apontar para ela
    g->M = (int**) malloc(nVertices*sizeof(int *)); //cria um array de *
    for(int i=0; i<nVertices; i++){
        g->M[i] = (int*) malloc(nVertices*sizeof(int)); //cria um array de int
    }

    g->nVertices = nVertices;
    return g;
}

void leGrafo(grafo_t *g){
    int n = g->nVertices;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           g->M[i][j] = 0;
        }
    }
}

int adicionaAresta(grafo_t *g, int v1, int v2){
    g->M[v1][v2] = 1;
    return 1;
}

void imprimirGrafo(grafo_t *g){
    for(int i=0; i<g->nVertices; i++){
        for(int j=0; j<g->nVertices ; j++){
            printf("%d ",g->M[i][j]);
        }
        printf("\n");
    }
}

int main() {

    grafo_t *g = cria(6);

    adicionaAresta(g,0,1);
    adicionaAresta(g,0,2);
    adicionaAresta(g,1,0);
    adicionaAresta(g,1,3);
    adicionaAresta(g,2,0);
    adicionaAresta(g,2,3);
    adicionaAresta(g,2,4);
    adicionaAresta(g,3,1);
    adicionaAresta(g,3,2);
    adicionaAresta(g,4,2);
    adicionaAresta(g,4,5);
    adicionaAresta(g,5,4);

    imprimirGrafo(g);

}
