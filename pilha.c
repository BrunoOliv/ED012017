#include <stdio.h>
#include <stdlib.h>

struct pilha {
    int topo;
    int capc;
    float *tElem;
};

void criarPilha(struct pilha *p, int v) {
    p->topo = -1;
    p->capc = v;
    p->tElem = (float*) malloc (v * sizeof(float));
}

int verifCheia (struct pilha *p) {
    if (p->topo == p->capc - 1)
        return 1;

    else
        return 0;
}

void push (struct pilha *p, int valor) {
    p->topo++;
    p->tElem[p->topo] = valor;
    }

int verifVazia (struct pilha *p) {
    if (p->topo == -1)
        return 1;

    else
        return 0;
}

float pop ( struct pilha *p ){
   p->topo--;
   return p->tElem [p->topo + 1];
}

int main () {
    int valor=10;
    float valorAux;
    struct pilha pilha1;

    criarPilha(&pilha1, valor);

    if(verifCheia(&pilha1) == 1)
        printf("\nPILHA CHEIA! \n");

    else{
        push(&pilha1, 1);
        push(&pilha1, 2);
        push(&pilha1, 3);
        push(&pilha1, 4);
        push(&pilha1, 5);
        push(&pilha1, 6);
        push(&pilha1, 7);
        push(&pilha1, 8);
        push(&pilha1, 9);
        push(&pilha1, 10);
    }

    if(verifVazia(&pilha1) == 1)
        printf("\nPILHA VAZIA! \n");

    else {
      do{
        valorAux = pop (&pilha1);
        printf("\nDesempilhado: %.1f", valorAux);
        } while(pilha1.topo != -1);
    }

    free(pilha1.tElem);

    return 0;
}
