#include <stdio.h>
#include <locale.h>
main()
{
	int a=1, b=0, c, x;
	setlocale(LC_ALL,"Portuguese");
	
	
	printf("Escreve o menor número de Fibonacci ímpar maior do que o valor de X:\n");
	
	do
	{	printf("X? ");
		scanf("%d",&x);
		if(x<10)
		{
			printf("\nAtenção ! Não digite nenhum numero menor que 10 !\n");
			printf("Por favor, digite outro número para que possa ser calculado.\n");
		}
	}while(x<10);
	
		do{
			c=a+b;
			a=b;
			b=c;
		}while(c<x);
		
			if(((c%2)!=0))
			printf("\nO menor número de Fibonacci ímpar maior do que o valor de X(%i): %i", x, c);
		
}