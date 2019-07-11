#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct grafo{
    int **M;
    int nVertices;
}grafo_t;


void imprimirGrafo(grafo_t *g){
    for(int i=0; i<g->nVertices; i++){
        for(int j=0; j<g->nVertices ; j++){
            printf("%d ",g->M[i][j]);
        }
        printf("\n");
    }
}

void leGrafo(grafo_t *g){
    int n = g->nVertices;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&g->M[i][j]);
        }
    }
}

int adicionaAresta(grafo_t *g, int v1, int v2){
    g->M[v1][v2] = 1;
    return 1;
}

int removeAresta(grafo_t *g, int v1, int v2){
    g->M[v1][v2] = 0;
    return 1;
}

grafo_t* criaGrafo(int nVertices){
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

int main() {
    int nV;
    int a,b;
    char op;
    scanf("%d",&nV);
    grafo_t * g = criaGrafo(nV);
    leGrafo(g);

    do{
        scanf(" %c",&op);
        switch(op){
            case 'I':

                scanf("%d",&a);
                scanf("%d",&b);
                adicionaAresta(g,a,b);
                break;
            case 'R':

                scanf("%d",&a);
                scanf("%d",&b);
                removeAresta(g,a,b);
                break;
            case 'S':
                imprimirGrafo(g);
                break;
        }
    }while(op != 'S');

    return 0;
}
