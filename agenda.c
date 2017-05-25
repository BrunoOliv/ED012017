/*Alunos: Bruno Oliveira da Silva  16/0003580
          Matheus
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista {
    ListaNo* prim;
};

struct listano {
    char nome[40];
    char email[40];
    char telefone[20];
    ListaNo* prox;
};

Lista* criaLista () {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
}

//opção 0 do menu()
void liberaAgenda(Lista *l){

    if(l->prim == NULL)
        printf("\nA agenda esta vazia!\n");

    else {
        ListaNo* p = l->prim;
        while(p != NULL) {
            ListaNo* t = p->prox;
            free(p);
            p = t;
        }
    free(l);
    }
}

//opção 1 do menu()
void insereContato (Lista* l) {
    ListaNo* novo = (ListaNo*) malloc (sizeof(ListaNo));
    ListaNo* anterior;
    ListaNo* atual;


    printf("\nInforme o nome do novo contato: ");
    getchar();
    scanf("%[^\n]", novo->nome);
    getchar();

    printf("\nInforme o email do novo contato: ");
    scanf("%[^\n]", novo->email);
    getchar();

    printf("\nInforme o telefone do novo contato: ");
    scanf("%[^\n]", novo->telefone);
    getchar();

    atual = l->prim;
    anterior = NULL;

    if(atual == NULL){
        novo->prox = NULL;
        l->prim = novo;
    }
    else{
        while(atual != NULL && strcmp(atual->nome, novo->nome) < 0){
            anterior = atual;
            atual = atual->prox;
        }
        novo->prox = atual;

        if(anterior == NULL)
            l->prim = novo;
        else
            anterior->prox = novo;
    }
}

//opção 2 do menu()
void imprimeContatos (Lista* l) {
    printf("\n\nNOME(s)                         EMAIL(s)                        TELEFONE(s)\n\n");
    for (ListaNo* p=l->prim; p!=NULL; p=p->prox)
    printf("%s                  %s                  %s\n", p->nome, p->email, p->telefone);
}

//opção 3 do menu()
void busImp (Lista* l) {
    char nome[40];
    int cont=1, ret;
    printf("\nInforme o nome: ");
    getchar();
    scanf("%[^\n]", &nome);
    getchar();

    ListaNo* p = l->prim;
    do {
        ret = strcmp(p->nome, nome);
        if(ret == 0){
            printf("\n\nNOME(s)                         EMAIL(s)                        TELEFONE(s)\n\n");
            printf("%s                  %s                  %s\n", p->nome, p->email, p->telefone);
            cont=0;
        }
        else
        p=p->prox;
    }while(cont != 0 && p != NULL);
    if(cont == 1)
        printf("\n\nNome nao encontrado!\n\n");
}

//função verifica char: sim ou não - usada por editCont()
void verif (char *editar) {
    while(*editar != 'S' && *editar != 's' && *editar != 'N' && *editar != 'n'){
            printf("\n\nErro! Digite S para sim ou N para nao: ");
            scanf("%c", editar);
            getchar();
        }
}

//função para editar contato(nome, email e telefone) - usada por editRemov()
void editCont (ListaNo* p) {
    char editar = NULL;

//edNome-------------------------------------------------------------------
        printf("\nEditar o nome (S/N): ");
        scanf("%c", &editar);
        getchar();

        verif(&editar);

        if(editar == 'S' || editar == 's') {
        printf("\nInforme o nome novo: ");
        scanf("%[^\n]", p->nome);
        getchar();
        }
//edEmail---------------------------------------------------------------------
        printf("\nEditar o email (S/N): ");
        scanf("%c", &editar);
        getchar();

        verif(&editar);

        if(editar == 'S' || editar == 's') {
        printf("\nInforme o email novo: ");
        scanf("%[^\n]", p->email);
        getchar();
        }
//edTel---------------------------------------------------------------------
        printf("\nEditar o telefone (S/N): ");
        scanf("%c", &editar);
        getchar();

        verif(&editar);

        if(editar == 'S' || editar == 's') {
        printf("\nInforme o telefone novo: ");
        scanf("%[^\n]", p->telefone);
        getchar();
        }
}

//opção 4 do menu()
void editRemov (Lista* l){
    int opc;
    char nome[40];
    ListaNo* p;

    printf("\nInforme 1 p/ editar ou 2 p/ excluir um contato: ");
    scanf("%d", &opc);

//opção 1 editar----------------------------------------------------------------------------
    if (opc == 1) {
    int comp;
    char editar = NULL;
    p = l->prim;

        printf("\nInforme o nome do contato para editar: ");
        getchar();
        scanf("%[^\n]", &nome);
        getchar();
    do {
        comp = strcmp(p->nome, nome);
            if(comp == 0){
            editCont(p);
        }
        else
        p=p->prox;
    }while(comp != 0 && p != NULL);

        if(comp != 0)
        printf("\n\nNome nao encontrado!\n\n");
    }

//opção 2 excluir---------------------------------------------------------------------------
    else if (opc == 2) {
        ListaNo* ant = NULL;
        p = l->prim;

        printf("\nInforme o nome do contato para excluir: ");
        getchar();
        scanf("%[^\n]", &nome);
        getchar();

    while(p != NULL && strcmp(p->nome, nome) != 0){
        ant = p;
        p = p->prox;
    }

        if(p == NULL)
            printf("\n\nNome nao encontrado!\n\n");

        else{
                if(ant == NULL) {
                    l->prim = p->prox;
                }
                else {
                    ant->prox = p->prox;
                }
                free(p);
                printf("\n\nContato excluido!\n");
            }
        }

    else
    printf("\nOpcao invalida!\n");
}

void menu (Lista *l) {
    int opt;
    system("color 03");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("* * * * * * * * * * * * * * * * * *  AGENDA ELETRONICA  * * * * * * * * * * * * * * *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    do{

    printf("\n                                * * * * * * * * * * * * * * * * *\n");
	printf("                                *  ESCOLHA A OPCAO              *\n");
	printf("                                *  0. SAIR                      *\n");
	printf("                                *  1. INSERIR CONTATO           *\n");
	printf("                                *  2. LISTAR CONTATOS           *\n");
	printf("                                *  3. BUSCAR E MOSTRAR CONTATO  *\n");
	printf("                                *  4. EDITAR E REMOVER CONTATO  *\n");
	printf("                                      Opcao: ");
	scanf("%d", &opt);

	switch(opt){
		case 0:
            liberaAgenda(l);
			break;

		case 1:
			insereContato(l);
			break;

		case 2:
			imprimeContatos(l);
			break;

		case 3:
            busImp(l);
			break;

		case 4:
            editRemov(l);
			break;

		default:
			printf("Comando invalido\n\n");
        }
	}while (opt != 0);
}

int main () {
    Lista* l = criaLista();

    menu (l);

    return 0;
}
