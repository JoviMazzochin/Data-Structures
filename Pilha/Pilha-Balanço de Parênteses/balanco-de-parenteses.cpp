#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000

typedef struct pilha{
    int topo;
    int vet[MAX];
}pilha_t;

pilha_t* cria(){
    pilha_t* p = (pilha_t*) malloc(1*sizeof(pilha_t));
    p->topo = 0;
    return p;
}

void zeraPilha(pilha_t* p){
    p->topo = 0;
}

void empilha(pilha_t* p){
    p->vet[p->topo] = 1;
    p->topo++;
}

int pilhaVazia(pilha_t* p){
    if(p->topo == 0){
        return 1;
    }
    return 0;
}

int desempilha(pilha_t* p){
    if(!pilhaVazia(p)){
        p->topo--;
        return 1;
    }else 
    return 0;
}



int main() {
    int casos, resp,aux;
    scanf("%d",&casos);
    pilha_t* p1 = cria();
    
    for(int i=0; i < casos; i++){
        char vet[1000];
        scanf("%s", vet);
        int tamanho = strlen(vet);
        
        for(int i = 0; i < tamanho; i++){
            aux = 0;
            if(vet[i] == '('){
                empilha(p1);
            }else if(vet[i] == ')'){
                int resp = desempilha(p1);
                if(resp == 0){
                    aux = 1;
                    break;
                }
            }
        }
            if(!pilhaVazia(p1) || aux == 1){
                printf("incorrect\n");
            }else{
                printf("correct\n");
            }
        zeraPilha(p1);
    }
    return 0;
}
