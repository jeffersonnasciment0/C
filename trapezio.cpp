#include <stdio.h>
#include <locale.h>
#include <math.h>

main(){
	setlocale(LC_ALL,"portuguese");
	
	float base_menor, base_maior, h, A ;
	
	printf("Digite o tamanho da base menor do trapézio:\n");
	scanf("%f", &base_menor);
	
	printf("Digite o tamanho da base maior do trapézio:\n");
	scanf("%f", &base_maior);
	
	printf("Digite a altura do trapézio:\n");
	scanf("%f", &h);
	
	A = ((base_maior + base_menor)*h)/2;
	
	printf("A área do trapezio em questao eh : %.2f m2", A);
	
}
