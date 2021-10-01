// programa ax + b = 0 


#include <stdio.h>
#include <locale.h>
#include <math.h>



main()
{
	setlocale(LC_ALL,"portuguese");
	int a,b;
	
	printf("Digite o Valor de 'a' e 'b' na expressão 'ax + b = 0':\n");
	scanf("%f%f",&a,&b);
		
	if((a == 0) && (b==0)){
		printf("Pode-se declarar essa função como indeterminada!\n");
	}
	else if (a == 0){
		printf("Pode-se declarar essa função como impossível !\n");
	}
	else{
		float x = -b /a;
	printf("O valor de x é: %f",x);	
	}

}
