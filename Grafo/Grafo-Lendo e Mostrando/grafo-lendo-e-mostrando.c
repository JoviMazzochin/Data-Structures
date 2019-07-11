#include <string.h>
#include <math.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct grafo{
    int **adjM;
    int nVertices;
} grafo_t;

grafo_t* cria(int nVertices){
    grafo_t *g;
    g = (grafo_t*) malloc(sizeof(grafo_t)); //aloca espaço para a estrutura grafo_t

    //cria a matriz e faz o ponteiro **adjM da matriz grafo_t apontar para ela
    g->adjM = (int**) malloc(nVertices*sizeof(int *)); //cria um array de *
    for(int i=0; i<nVertices; i++){
        g->adjM[i] = (int*) malloc(nVertices*sizeof(int)); //cria um array de int
    }

    g->nVertices = nVertices;
    return g;
}

void leGrafo(grafo_t *g){
    int n = g->nVertices;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&g->adjM[i][j]);
        }
    }
}

void imprimirGrafo(grafo_t *g){
    for(int i=0; i<g->nVertices; i++){
        for(int j=0; j<g->nVertices ; j++){
            printf("%d ",g->adjM[i][j]);
        }
        printf("\n");
    }
}

int main(){
    grafo_t *g;
    int nVertices;

    scanf("%d",&nVertices);
    g = cria(nVertices);
    leGrafo(g);

    imprimirGrafo(g);
}
