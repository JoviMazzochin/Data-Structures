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
    char opcao;
    int casos,valor;
    fila_t* f = cria();
    scanf("%d",&casos);
    
    for(int i=0; i<casos; i++){
        zerar(f);
        
        do{
            scanf(" %c",&opcao);
            if(opcao == 'X'){
                break;
            }
            
            else{
                switch (opcao){
                    case 'I':
                        scanf("%d",&valor);
                        inserir(f,valor);
                        //imprime(f);
                        break;
                    case 'R':
                        remover(f);
                        break;
                    case 'K':
                        printf("Total elementos: %d\n",numElementos(f));
                        break;
                    case 'V':
                        if(vazia(f)){
                            printf("Fila vazia!\n");
                        }
                        else{
                            printf("Fila nao vazia!\n");
                        }
                        break;
                    case 'C':
                        if(cheia(f)){
                            printf("Fila cheia!\n");
                        }
                        else{
                            printf("Fila nao cheia!\n");
                        }
                        break;
                    case 'P':
                        imprime(f);
                        break;
                }
            }
            
        }while(opcao != 'X');
        
    if(i < casos-1){
         printf("\n");   
    }
       
    }
       
    return 0;
}
