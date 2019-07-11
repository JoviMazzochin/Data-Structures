#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 50

typedef struct fila{
    int inicio;
    int fim;
    int numElem;
    int vet[MAX];
}fila_t;

fila_t* cria(){
    fila_t* f = (fila_t*) malloc(sizeof(fila_t));
    f->inicio = 0;
    f->fim = 0;
    f->numElem = 0;
    return f;
}

int cheia(fila_t* f){
    if (f->numElem == MAX)
        return 1;
    else
        return 0;
}

int vazia(fila_t* f){
    if(f->numElem == 0){
        return 1;
    }
    return 0;
}

int inserir(fila_t* f, int value){
    if(cheia(f)){
        return 0;
    }
    f->vet[f->fim] = value;
    f->numElem++;
    f->fim = (f->fim+1) % MAX;
    return 1;
}

int remover(fila_t* f){
    if(!vazia(f)){
        int aux = f->vet[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        f->numElem--;
        return aux;
    }
    return 0;
}

int numElementos(fila_t* f){
    return f->numElem;
}

void imprime(fila_t* f){
    int i=f->inicio;
    int t = f->numElem;
    while (t>0){
        printf("%d ",f->vet[i]);
        t--;
        i = (i+1) % MAX;
    }
    printf("\n");
}

void zerar(fila_t* f){
    f->inicio = 0;
    f->fim = 0;
    f->numElem = 0;
}

int main() {
    int n;
    fila_t* f = cria();
    
    
    do{
        zerar(f);
        scanf("%d",&n);
        if(n == 0){
            break;
        }
        for(int i=1 ; i<=n ; i++){
            inserir(f,i);
        }
        
        printf("Discarded cards: ");
        while(numElementos(f) >= 2){
            int descarte = remover(f);
            if(numElementos(f) == 1){
                printf("%d ",descarte);
            }else{
                printf("%d, ",descarte);
            }
            int valor = remover(f);
            inserir(f,valor);
        }
        
        
        printf("\n");
        
        
        printf("Remaining card: ");
        imprime(f);
        
    }while(n != 0);
      
    return 0;
}

