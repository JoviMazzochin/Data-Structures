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
    int nV,a;
    char op, aux;
    scanf("%d",&nV);
    grafo_t* g = criaGrafo(nV);
    leGrafo(g);

    // I = 73 // R = 82 // S = 83
    //I 0 I 2 3 R 1 I 0 1 2 3 4 5 6 S
    do{
        scanf(" %c",&op);
        if(op == 'I'){
            aux = 'I';
            g = adicionaVertice(g);
        }else if(op == 'R'){
            aux = 'R';
        }else if(op != 'S'){
            if(aux == 'I'){
                a = atoi(&op);
                adicionaAresta(g,g->nVertices-1, a);
            }else if(aux == 'R'){
                a = atoi(&op);
                g = removeVertice(g, a);
            }
        }

    }while(op != 'S' ); // S
    imprimirGrafo(g);


    return 0;
}
