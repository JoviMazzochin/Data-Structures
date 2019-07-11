#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10
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
        f->inicio = (f->inicio + 1) % MAX;
        f->numElem--;
        return 1;
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
        if(t!=1){
            printf("%d * ",f->vet[i]);
        }else{
            printf("%d",f->vet[i]);
        }
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

void fatora(fila_t* f, int n){
    int d = 2;
        do{
            if(n % d == 0){
                inserir(f,d);
                n = n/d;
            }else{
                d++;
            }
        }while(n != 1);
}
int main() {
    int casos;
    fila_t* f;
    f = cria();

    scanf("%d",&casos);
    for (int p=0; p<casos; p++){
        zerar(f);
        int n;
        scanf("%d",&n);

        fatora(f,n);
        imprime(f);

    }

    return 0;
}
