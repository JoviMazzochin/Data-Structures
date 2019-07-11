#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 5
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
    char cliente;
    int num, a;
    fila_t* fN = cria();
    fila_t* fP = cria();
    
    do{
        scanf(" %c",&cliente);
        switch(cliente){
            case 'N':
                scanf("%d",&num);
                a = inserir(fN,num);
                break;
            case 'I': 
                scanf("%d",&num);
                a = inserir(fP,num);
                break;
            case 'G':
                scanf("%d",&num);
                a = inserir(fP,num);
                //printf("%d ",fP->numElem);
                break;
            case 'C':
                if(fP->numElem != 0){
                    printf("%d ",remover(fP));
                }else if(fN->numElem != 0){
                    printf("%d ",remover(fN));
                }
                break;
            case 'F':
               //imprime(fN);
               //printf("\n");
               //imprime(fP);
                break;
        }
    }while (cliente != 'F');
    printf("\nRestaram %d pessoas na fila",numElementos(fN) + numElementos(fP));
    
    
    return 0;
}
