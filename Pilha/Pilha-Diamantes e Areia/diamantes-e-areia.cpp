#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000

typedef struct pilha{
    int dima[MAX];
    int topo;
}pilha_t;

pilha_t* cria(){
    pilha_t* p = (pilha_t*) malloc(1*sizeof(pilha_t));
    p->topo = 0;
    return p;
}

void empilha(pilha_t* p){
    p->dima[p->topo] = 1;
    p->topo++;
}

void zeraPilha(pilha_t* p){
    p->topo = 0;
}

int pilhaVazia(pilha_t* p){
    if(p->topo == 0){
        return 1;
    }else
    return 0;
}

int desemprilha(pilha_t* p){
    if(!pilhaVazia(p)){
        p->topo--;
        return 1;
    }else{
        return 0;
    }
}


int main() {
    int casos, resp = 0;
    char vet[MAX];
    scanf("%d",&casos);
    pilha_t* p1 = cria();
    
    for(int i = 0; i<casos ; i++){
        int cont = 0;
        scanf("%s", vet);
        int tamanho = strlen(vet);
        for(int i = 0; i < tamanho; i++){
            if(vet[i] == '<'){
                empilha(p1);
            }else if(vet[i] == '>'){
                resp = desemprilha(p1);
                if(resp == 1){
                    cont++;
                }
            }
        }
        printf("%d\n",cont);
        zeraPilha(p1);
    }
    return 0;
}
