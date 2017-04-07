#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


void impInf () {
  printf("                               Bem-vindo a Batalha Naval!\n\n\n");
  printf("Descricao: Batalha naval eh um jogo de tabuleiro de\ndois jogadores, no qual os jogadores tem de adivinhar\nem que quadrados estao os navios do oponente.\n\nO jogo termina quando o primeiro jogador atingir 10 pontos.\n\n");

}

void matNull (char camp1 [][8], char  camp2 [][8]) {
    int i, j;

  for(i=0; i<5; i++) {
    for(j=0; j<8; j++) {

     camp1[i][j] = 'a';
     camp2[i][j] = 'a';
    }
  }
}

void impCamp (char camp1 [][8], char  camp2 [][8]) {
    int i;
        printf("                    JOGADOR 1                         JOGADOR 2\n");
        for(i=0; i < 5; i++) {
        printf("             |%c||%c||%c||%c||%c||%c||%c||%c|         |%c||%c||%c||%c||%c||%c||%c||%c|\n", camp1[i][0], camp1[i][1], camp1[i][2], camp1[i][3], camp1[i][4], camp1[i][5], camp1[i][6], camp1[i][7], camp2[i][0], camp2[i][1], camp2[i][2], camp2[i][3], camp2[i][4], camp2[i][5], camp2[i][6], camp2[i][7]);
  }
}

void gerarNav (char camp1 [][8], char  camp2 [][8]) {
    int cont = 0, i, p, k, h, z;
    srand(time(NULL));

    for(i=0; i<8 ; i++) {

    int x = rand() % 5;
    int y = rand() % 8;
    int x2 = rand() % 5;
    int y2 = rand() % 8;

    camp1[x][y] = 'N';
    camp2[x2][y2] = 'N';
    }

do{ //gera encouraçado camp1
    h = rand() % 4;
    z = rand() % 7;
    cont = 0;

    if (z < 5) {
    for (p = 0; p < 4; p++) {
        if (camp1[h][z] == 'a' && camp1[h][z] != 'N') {
        cont = cont + 1;
        }
    z++;
    }

    if (cont == 4) {
        for (k = 0; k < 4; k++) {
        camp1[h][z] = 'E';
        z++;
            }
        }
    }
} while(cont != 4);

  printf("\n\n");

  do{ //gera encouraçado camp2
    h = rand() % 4;
    z = rand() % 7;
    cont = 0;

    if (z < 5) {
    for (p = 0; p < 4; p++) {
        if (camp2[h][z] == 'a' && camp2[h][z] != 'N') {
        cont = cont + 1;
        }
    z++;
    }

    if (cont == 4) {
        for (k = 0; k < 4; k++) {
        camp2[h][z] = 'E';
        z++;
            }
        }
    }
} while(cont != 4);

  printf("\n\n");
}

void respCompJog1 (int *eixoX, int *eixoY, char camp2 [][8], int *cont) {
    printf("Jogador 1 - Ultima jogada: %d %d\n", *eixoX, *eixoY);
    printf("Jogador 1 - Informe a coordenada de X e Y (separados por espaço): ");
    scanf("%d %d", eixoX, eixoY);

    if (camp2[*eixoX][*eixoY] == 'N') {
      printf("Voce acertou um navio!");
      *cont = *cont + 1;
    }

    else if (camp2[*eixoX][*eixoY] == 'E') {
      printf("Voce acertou parte do encouracado!");
      *cont = *cont + 1;
    }
    else
      printf("Errou!");

    printf("\nPontuacao: %d\n\n", *cont);
}

void respCompJog2 (int *eixoX2, int *eixoY2, char camp1 [][8], int *cont2) {
    printf("Jogador 2 - Ultima jogada: %d %d\n", *eixoX2, *eixoY2);
    printf("Jogador 2 - Informe a coordenada de X e Y (separados por espaço): ");
    scanf("%d %d", eixoX2, eixoY2);

    if (camp1[*eixoX2][*eixoY2] == 'N') {
      printf("Voce acertou um navio!");
      *cont2 = *cont2 + 1;
    }
      else if (camp1[*eixoX2][*eixoY2] == 'E') {
      printf("Voce acertou parte do encouracado!");
      *cont2 = *cont2 + 1;
    }
    else
      printf("Errou!");

    printf("\nPontuacao: %d\n\n", *cont2);
}

int main () {
  char camp1 [5][8];
  char camp2 [5][8];
  int eixoX = 0, eixoY = 0, eixoX2 = 0, eixoY2 = 0, cont=0, cont2=0;

  impInf ();

  matNull (camp1, camp2);

  impCamp (camp1, camp2);

  gerarNav (camp1, camp2);

  do{
  respCompJog1 (&eixoX, &eixoY, camp2, &cont);

  respCompJog2 (&eixoX2, &eixoY2, camp1, &cont2);
  } while(cont != 10 && cont2 != 10);

  if (cont == 10) {
    printf("\nGanhou: Jogador 1!\n");
  }
  else
    printf("\nGanhou: Jogador 2!\n");

  return 0;
}
