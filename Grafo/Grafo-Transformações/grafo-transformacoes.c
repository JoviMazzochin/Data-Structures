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
    g->M[v2][v1] = 1;
    return 1;
}

int removerAresta(grafo_t *g, int v1, int v2){
    g->M[v1][v2] = 0;
    g->M[v2][v1] = 0;
    return 1;
}

grafo_t* criaGrafo(int nVertices){
    grafo_t *g;
    g = (grafo_t*) malloc(sizeof(grafo_t)); //aloca espaço para a estrutura grafo_t

    //cria a matriz e faz o ponteiro **adjM da matriz grafo_t apontar para ela
    g->M = (int**) malloc(nVertices*sizeof(int *)); //cria um array de *
    for(int i=0; i<nVertices; i++){
        g->M[i] = (int*) calloc(nVertices,sizeof(int)); //cria um array de int e inicializa com 0
    }

    g->nVertices = nVertices;
    return g;
}

grafo_t* adicionaVertice(grafo_t* g){
    grafo_t* g2 = criaGrafo(g->nVertices+1);

    for(int i=0; i<g->nVertices; i++){
        for(int j=0; j<g->nVertices ; j++){
           g2->M[i][j] = g->M[i][j];
        }
    }
    return g2;
}

grafo_t* removeVertice(grafo_t* g, int remov){
    remov --;
    grafo_t* g2 = criaGrafo(g->nVertices-1);
    for(int i=0; i<g->nVertices-1; i++){
        for(int j=0; j<g->nVertices-1 ; j++){
            if(i > remov && j > remov){
                g2->M[i][j] = g->M[i+1][j+1];
            }else if(i > remov && j<= remov){
                g2->M[i][j] = g->M[i+1][j];
            }else if(j > remov && i<= remov){
                g2->M[i][j] = g->M[i][j+1];
            }else{
                 g2->M[i][j] = g->M[i][j];
            }
        }
    }
    return g2;
}


int removeAresta(grafo_t *g, int v1, int v2){
    g->M[v1][v2] = 0;
    return 1;
}

int main() {
    grafo_t* g = criaGrafo(6);

    adicionaAresta(g, 0, 1);
    adicionaAresta(g, 0, 2);
    adicionaAresta(g, 1, 0);
    adicionaAresta(g, 1, 3);
    adicionaAresta(g, 2, 0);
    adicionaAresta(g, 2, 3);
    adicionaAresta(g, 2, 4);
    adicionaAresta(g, 3, 1);
    adicionaAresta(g, 3, 2);
    adicionaAresta(g, 4, 2);
    adicionaAresta(g, 4, 5);
    adicionaAresta(g, 5, 4);
    imprimirGrafo(g);

    g = removeVertice(g,5);

    removeAresta(g,1,0);
    removeAresta(g,0,1);

    adicionaAresta(g,0,4);

    adicionaAresta(g,3,4);
    g = removeVertice(g,2);

    g = adicionaVertice(g);
    adicionaAresta(g,2,4);

    printf("RV(5) RA(1,0) IA(0,4) IA(3,4) RV(2) IV(4) IA(2,4)\n");

    imprimirGrafo(g);
}
