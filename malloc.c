#include <stdio.h>
#include <stdlib.h>


int main(){
   int n;
   int *p;
   int i;
   int media=0;
   int soma=0;

   printf("Digite o tamanho do vetor: ");
   scanf("%d", &n);

   p=(int*)malloc(n*sizeof(int));

   for(i=0;i<n;i++){
     printf("Vetor: ");
     scanf("%d", &p[i]);

   }

   for(i=0;i<n;i++){
     soma+=p[i];
   }

    media=soma/n;

    printf("Media dos vetores %.d ", media);

    free(p);

    return 0;
}
