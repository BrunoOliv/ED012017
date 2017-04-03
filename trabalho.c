#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


void impInf () {
  printf("                               Bem-vindo à Batalha Naval!\n\n\n");
  printf("Descricao: Batalha naval eh um jogo de tabuleiro de\ndois jogadores, no qual os jogadores tem de adivinhar\nem que quadrados estao os navios do oponente.\n\n");

}

void matNull (char camp1 [][8], char  camp2 [][8]) {

  for(int i=0; i<5; i++) {
    for(int j = 0; j < 8; j++) {

     camp1[i][j] = 'a';
     camp2[i][j] = 'a';
    }
  }
}

void impCamp (char camp1 [][8], char  camp2 [][8]) {
  printf("                    JOGADOR 1                         JOGADOR 2\n");
    for(int i = 0; i < 5; i++) {
     printf("             |%c||%c||%c||%c||%c||%c||%c||%c|         |%c||%c||%c||%c||%c||%c||%c||%c|\n", camp1[i][0], camp1[i][1], camp1[i][2], camp1[i][3], camp1[i][4], camp1[i][5], camp1[i][6], camp1[i][7], camp2[i][0], camp2[i][1], camp2[i][2], camp2[i][3], camp2[i][4], camp2[i][5], camp2[i][6], camp2[i][7]);
  }
}

void gerarNav (char camp1 [][8], char  camp2 [][8]) {
    int cont = 0;
    srand(time(NULL));

    for(int i=0; i <= 7 ; i++) {

    int x = rand() % 5;
    int y = rand() % 8;

    camp1[x][y] = 'N';
    }

do{
    int h = rand() % 5;
    int z = rand() % 8;

    if (z <= 4) {
    for (int p = 0; p < 4; p++) {
        if (camp1[h][z] != 'N') {
        cont = cont + 1;
        }
    z++;
    }

    if (cont == 4) {
        for (int k = 0; k < 4; k++) {
        camp1[h][z] = 'E';
        z++;
        }
    }
}
} while(cont != 4);

    /*camp2[w][z] = 'N';

    printf("\n\nLinha - x = %d\n", x);
    printf("Coluna - y = %d\n", y);*/

  printf("\n\n");

}

void resp (int *eixoX, int *eixoY) {
  printf("Informe a coordenada de X e Y (separados por espaço): ");
  scanf("%d %d", eixoX, eixoY);

}

void respComp (int eixoX, int eixoY, char camp1 [][8], int *cont) {
    if (camp1[eixoX][eixoY] == 'N') {
      printf("Voce acertou!");
      cont = cont + 1;
    }
    else
      printf("Errou!");
}

int main () {
  char camp1 [5][8];
  char camp2 [5][8];
  int eixoX, eixoY, cont=0;

  impInf ();

  matNull (camp1, camp2);

  impCamp (camp1, camp2);

  gerarNav (camp1, camp2);

  impCamp (camp1, camp2);

/*
  resp (&eixoX, &eixoY);

  printf("\nValores: %d %d\n", eixoX, eixoY);

  respComp (eixoX, eixoY, camp1, &cont);
  */
  return 0;
}
