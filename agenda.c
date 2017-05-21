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

    novo->prox = l->prim;
    l->prim = novo;
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
        ret = strncmp(p->nome, nome, 7);
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

//opção 4 do menu()
void editRemov (Lista* l){
    int opc;
    printf("Informe 1 p/ editar ou 2 p/ excluir um contato: ");
    scanf("%d", &opc);

    ListaNo* p = l->prim;

    if (opc == 1) {
    char nome[40];
    int cont=1, ret;
        printf("\nInforme o nome do contato para editar: ");
        getchar();
        scanf("%[^\n]", &nome);
        getchar();

    do {
        ret = strncmp(p->nome, nome, 7);
        if(ret == 0){
        printf("\nInforme o nome novo: ");
        getchar();
        scanf("%[^\n]", p->nome);
        getchar();

        printf("\nInforme o email novo: ");
        scanf("%[^\n]", p->email);
        getchar();

        printf("\nInforme o telefone novo: ");
        scanf("%[^\n]", p->telefone);
        getchar();

        cont=0;
        }
        else
        p=p->prox;
    }while(cont != 0 && p != NULL);
        if(cont == 1)
        printf("\n\nNome nao encontrado!\n\n");

    }

    else if (opc == 2) {
        char nome[40];
        int cont=1, ret;
        ListaNo* ant = NULL;

        printf("\nInforme o nome do contato para excluir: ");
        getchar();
        scanf("%[^\n]", &nome);
        getchar();

    while(p != NULL && ret != 0){
        ret = strncmp(p->nome, nome, 7);
        ant = p;
        p = p->prox;
    }

            if(p != NULL){
                if(ant == NULL) {
                    l->prim = p->prox;
                }
                else {
                    ant->prox = p->prox;
                }
                free(p);
            }
    }

    else
    printf("\nOpcao invalida!\n");
}

int menu () {
    int opt;

	printf("\nEscolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Inserir contato\n");
	printf("2. Listar contatos\n");
	printf("3. Buscar e mostrar contato\n");
	printf("4. Editar e remover contato\n");

	printf("Opcao: ");
	scanf("%d", &opt);

    return opt;
}


void opcao(Lista *l, int opt) {
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
}

int main () {
    Lista* l = criaLista();
    int opt;


    do{
    opt = menu ();
    opcao (l, opt);
    }while (opt != 0);


    return 0;
}
