#include <stdio.h>
#include <stdlib.h>

int lerTam () {
    int tamV;

    do {
        printf("Informe o tamanho do vetor (<= 20): ");
        scanf("%d", &tamV);

        if (tamV <= 0 || tamV > 20) {
        printf("Erro! Tamanho acima do permitido.\n");
        }
    }while (tamV <= 0 || tamV > 20);
    return tamV;
}

int *alocVet () {

    int *ptrVetor = (int*) malloc (20 * sizeof(int));

    return  ptrVetor;
}

void lerVals (int *ptrVetor, int tamV) {
    for (int i=0; i<tamV; i++) {
        printf("Informe o valor [%d]: ", i+1);
        scanf("%d", &ptrVetor[i]);
    }
}

void medImp(int *ptrVetor, int tamV) {
    int soma=0;
    float med;

    for(int i=0; i<tamV; i++) {
    soma = soma + ptrVetor[i];
    }
    med = soma / tamV;

    printf("Media: %.2f", med);
}

int main () {

    int tamV = lerTam();

    int *ptrVetor = alocVet();

    lerVals (ptrVetor, tamV);

    medImp (ptrVetor, tamV);

    free(ptrVetor);
    return 0;
}
