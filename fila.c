#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int fila[10], i, aux, x, frente=0, tras=0;

int filafull();
int filaemp();
void in(int x);
int out();

int main()
{
	do
	{
	   printf("\nInsira um valor: ");
	   scanf("%d", &x);
	   in(x);
	}while(tras<MAX);

	x=tras;

	for(i=0;i<x;i++)
	{
		printf("\n%d valor desenfileirado: %d",i+1,out());
	}

	return 0;
}

int filafull()
{
	return (tras==MAX);
}

int filaemp()
{
	return(frente==tras);
}

void in(int x)
{
	if(! filafull())
	{
		fila[tras++]=x;
	}

	else
	{
		printf("\nFILA CHEIA");
	}
}

int out()
{
	if(! filaemp())
	{
		aux=fila[frente];
		frente++;
		return aux;
	}

	else
	{
		printf("\nFILA VAZIA");
	}

}
