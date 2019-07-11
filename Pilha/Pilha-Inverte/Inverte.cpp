#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 500

typedef struct pilha{
    char vet[MAX];
    int topo;
}pilha_t;

pilha_t* cria(){
    pilha_t* p = (pilha_t*) malloc(1*sizeof(pilha_t));
    p->topo = 0;
    return p;
}

int pilhaVazia(pilha_t* p){
    if(p->topo == 0){
        return 1;
    }
    return 0;
}

int desempilha(pilha_t* p, char *c){
    if(pilhaVazia(p)){
        return 0;
    }
    else{
        *c = p->vet[p->topo-1];
        p->topo--;
        return 1;
    }
}

int pilhaCheia(pilha_t* p){
    if(p->topo == MAX){
        return 1;
    }
    return 0;
}

int empilha(pilha_t* p, char value){
    if(!pilhaCheia(p)){
        p->vet[p->topo] = value;
        p->topo++;
        return 1;
    }
    return 0;
}

void imprime(pilha_t* p){
    for(int i=p->topo-1; i>=0 ; i--){
        printf("%c\n",p->vet[i]);
    }
}

int zera(pilha_t* p){
    p->topo = 0;
    return 1;
}

int tamanhoPilha(pilha_t* p){
    return p->topo;
}


int main() {
    int casos;
    scanf("%d",&casos);
    char vet[MAX], letra;
    pilha_t* p1 = cria();
    for(int j=0 ; j<casos; j++){
        zera(p1);
        scanf(" %[^\n]s", vet);
        int tamanho = strlen(vet);
        for(int i=0; i<tamanho; i++){
            if(vet[i] == ' '){
                int tam = tamanhoPilha(p1);
                //imprime(p1);
                for(int k=tam; k>0; k--){
                    desempilha(p1,&letra);
                    printf("%c",letra);
                }
                printf(" ");
            }
            else if(vet[i] == '.'){
                int tam = tamanhoPilha(p1);
                for(int k=tam; k>0; k--){
                    desempilha(p1,&letra);
                    printf("%c",letra);
                }
                printf("\n");
                break;
             }else{
                empilha(p1,vet[i]);
            }
        }
        
    }
    
    
    
    return 0;
}
