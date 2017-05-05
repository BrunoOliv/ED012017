#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista {
    ListaNo* prim;
};

struct listano {
    int val;
    ListaNo* prox;
};

Lista* criaLista () {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
}

void insereLista (Lista* l, int v) {
    ListaNo* novo = (ListaNo*) malloc (sizeof(ListaNo));
    novo->val = v;
    novo->prox = l->prim;
    l->prim = novo;
}

void imprimeLista (Lista* l) {
    for (ListaNo* p=l->prim; p!=NULL; p=p->prox)
        printf("Valor= %d\n", p->val);
}

int main () {
    Lista* l = criaLista();

    insereLista(l, 1);
    insereLista(l, 2);
    insereLista(l, 3);
    insereLista(l, 4);
    insereLista(l, 5);
    insereLista(l, 6);
    insereLista(l, 7);
    insereLista(l, 8);
    insereLista(l, 9);
    insereLista(l, 10);

    imprimeLista(l);


    return 0;
}
