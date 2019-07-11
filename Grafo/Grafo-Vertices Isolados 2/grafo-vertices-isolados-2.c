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

int adicionaArestaDirecionada(grafo_t *g, int v1, int v2){
    g->M[v1][v2] = 1;
    return 1;
}

int removerArestaDirecionada(grafo_t *g, int v1, int v2){
    g->M[v1][v2] = 0;
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

int verificaLaco(grafo_t* g, int i){
    if(g->M[i][i] == 1){
        return 1;
    }
    return 0;
}

int verticeIsolado(grafo_t* g){
    int numIso = 0;
    int verifIsolado;
    for(int i=0 ; i<g->nVertices; i++){
        verifIsolado = 0;
        for(int j=0; j<g->nVertices; j++){
            if(g->M[i][j] == 1 || g->M[j][i] == 1){
                verifIsolado ++;
            }

        }
        if(verifIsolado == 0){
            numIso++;
        }
    }
    if(numIso > 0){
        printf("sim %d\n",numIso);
    }else{
        printf("nao\n");
    }
    return 1;
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

void transformaNaoDirecionado(grafo_t* g){
    for(int i=0; i<g->nVertices ; i++){
        for(int j=0; j<g->nVertices ; j++){
            if(g->M[i][j] == 1){
                g->M[j][i] = 1;
            }
        }
    }
}

int main() {
    grafo_t* g = criaGrafo(9);
    int n;
    adicionaArestaDirecionada(g,1,2);
    adicionaArestaDirecionada(g,1,3);
    adicionaArestaDirecionada(g,2,4);
    adicionaArestaDirecionada(g,3,3);
    adicionaArestaDirecionada(g,3,2);
    adicionaArestaDirecionada(g,4,4);
    adicionaArestaDirecionada(g,4,3);
    adicionaArestaDirecionada(g,4,6);
    adicionaAresta(g,5,6);
    adicionaArestaDirecionada(g,6,2);
    adicionaArestaDirecionada(g,7,0);
    adicionaArestaDirecionada(g,8,7); //Figura 1
    verticeIsolado(g);

    removerArestaDirecionada(g,3,2); //Figura 2
    verticeIsolado(g);

    removerArestaDirecionada(g,4,4); //Figura 3
    verticeIsolado(g);

    g = removeVertice(g,7); //Figura 4
    verticeIsolado(g);
    //imprimirGrafo(g);

    g = removeVertice(g,7);//Figura 5
    verticeIsolado(g);

    adicionaArestaDirecionada(g,1,0);//Figura 6
    verticeIsolado(g);

    transformaNaoDirecionado(g);//Figura 7
    verticeIsolado(g);

    removerAresta(g,3,3);//Figura 8
    verticeIsolado(g);

    //imprimirGrafo(g);


    return 0;
}
