#include <stdio.h>

void InfImp () {
    int vetor[10];
  
  printf("Informe 10 valores p/ armanezar (separados por espaco): ");
    scanf("%d %d %d %d %d %d %d %d %d %d", &vetor[0], &vetor[1], &vetor[2], &vetor[3], &vetor[4], &vetor[5], &vetor[6], &vetor[7], &vetor[8], &vetor[9]);
    
    printf("\n\nResultado:\n");
     for (int i=0; i<10; i++) {
      printf("Vetor [%d]: %d\n", i+1, vetor[i]);
    }
}

int main () {

    InfImp ();
    
  return 0;
  
 
}