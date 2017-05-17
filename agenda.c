#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista {
    ListaNo* prim;
};

struct listano {
    char nome[60];
    char email[60];
    char telefone[20];
    ListaNo* prox;
};

Lista* criaLista () {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
}

void insereContato (Lista* l) {
    ListaNo* novo = (ListaNo*) malloc (sizeof(ListaNo));

    printf("\nInforme o nome do novo contato: ");
    scanf("%s", novo->nome);


    printf("\nInforme o email do novo contato: ");
    scanf("%s", novo->email);


    printf("\nInforme o telefone do novo contato: ");
    scanf("%s", novo->telefone);


    novo->prox = l->prim;
    l->prim = novo;
}

void imprimeContatos (Lista* l) {
    printf("Nome(s)                    Email(s)                   Telefone(s)");
    for (ListaNo* p=l->prim; p!=NULL; p=p->prox)
    printf("\n%s                  %s                  %s", p->nome, p->email, p->telefone);
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

void opcao(Lista *l, int op) {
	switch(op){
		case 0:

			break;

		case 1:
			insereContato(l);
			break;

		case 2:
			imprimeContatos(l);
			break;

		case 3:

			break;

		case 4:

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
