#include <stdio.h>

void infImp () {
    int vetor[10];

  printf("Informe 10 valores (separados por espaco): ");
    scanf("%d %d %d %d %d %d %d %d %d %d", &vetor[0], &vetor[1], &vetor[2], &vetor[3], &vetor[4], &vetor[5], &vetor[6], &vetor[7], &vetor[8], &vetor[9]);

    printf("\n\nResultado:\n");
     for (int i=0; i<10; i++) {
      printf("Vetor [%d]: %d\n", i+1, vetor[i]);
    }
    printf("\n");
}

void infImpVet () {
    int matriz[3][4], i, j;

    for(i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
        printf("Informe um valor da matriz para a posicao [%d][%d]: ", i+1, j+1);
        scanf("%d", &matriz[i][j]);
        }
    }
    printf("\nValores da matriz: \n");
        for(i=0; i<3; i++) {
            for (int j=0; j<4; j++) {
            printf("Matriz[%d][%d]: %d   ", i+1, j+1, matriz[i][j]);
        }
        printf("\n");
    }
}
int main () {

    infImp ();

    infImpVet ();

  return 0;


}
