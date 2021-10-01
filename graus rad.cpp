// 	INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊCIA E TECNOLOGIA DO CEARÁ
//	CURSO DE TECNOLOGIA EM TELEMÁTICA
//	ALUNO: JEFFERSON SANTOS DO NASCIMENTO 
// 	DATA: 28/03/2021

#include <stdio.h>
#include <locale.h>
#include <math.h>

main(){
	setlocale(LC_ALL,"portuguese");
	float grau,rad,pi=3.14159;
	
	
	printf("Digite O valor do Ângulo em grau: ");
	scanf("%f",&grau);
	
	printf("\nProcessando resultado ...\n");
	rad = grau*pi/180;

	printf("\nO resultado em radianos é: %f", rad);
}
