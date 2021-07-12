/**
Instituto Federal do Ceará
Nome: Jefferson Santos do Nascimento 
Matricula: 20182013020064

1) Faça um programa que elabore um jogo simples da loteria que foi sorteado para você
	 e salve os números de forma ordenada num arquivo texto.
	 Obs1.: Descreva para o usuário o funcionamento da sua loteria sorteada.
**/
//Programa elelaborador da Itália - SuperEnalotto.
#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
void explicajogo(void)
{ // Esta função descreve para o usuário o funcionamento da Itália - SuperEnalotto.
	printf("Explicando o Jogo ...\n");
	printf("--------------------\n");
	printf(" É necessário acertar pelo menos 2 números para ganhar.\n O objetivo do jogo é acertar 6 números(Main Numbers) com números entre 1 e 90.\n");
	printf(" Se um jogador acertar todos eles, ele/ela ganha o Jackpot.\n\n");
	printf(" Fora os 6 principais há o número 'Jolly',ele dá uma chance adicional somente para aqueles que acertaram 5 números.\n");
	printf(" Se eles também corresponderem ao número 'Jolly', ganharão um prêmio '5 + 1'.\n\n");
	printf(" Também há o número 'SuperStar' que é um número adicional que tem um custo extra para jogar.\n");
	printf(" Nesse caso iremos adotar o SuperStar em todos os jogos.\n\n");
}
void ordena(int x[], int n)
{ // Esta função faz a ordenação do vetor que é destinado ao Main Numbers
		int aux,posicao,j,i;
    for(j=0;j<(n-1);j++)
    { posicao=j;
      for(i=j+1;i<n;i++)
       if(x[i]<x[posicao])
          posicao=i;
       aux=x[j];
	   x[j]=x[posicao];
	   x[posicao]=aux;
    }
}
void ordena1(int x[], int n)
{ // Esta função faz a ordenação das duas ultimas posições do vetor destinadas a jolly e a superstar
		int aux,posicao,j,i;
    for(j=7;j<(n-1);j++)
    { posicao=j;
      for(i=j+1;i<n;i++)
       if(x[i]<x[posicao])
          posicao=i;
       aux=x[j];
	   x[j]=x[posicao];
	   x[posicao]=aux;
    }
}
void GeraJogo(void)
{ // Esta é a função principal que realiza a geração do jogo.
	 FILE *arquivo;
   int i,x[9],repetiu=1,j;
   srand(time(NULL));
   while(repetiu)
   {   for(i=0;i<9;i++)
         x[i]=1+(rand()%90);
       for(repetiu=0,i=0;i<8;i++)
         for(j=i+1;j<9;j++)
           if(x[i]==x[j])
             repetiu=1;
   }  
   ordena(x,6);
   printf("\nJogo ordenado:\n");
   printf("\t\tMain Numbers\t\t Jolly\t\tSuperStar\n");
   for(i=0;i<6;i++)
		printf("%6d",x[i]);
   ordena1(x,9);
	 printf("%8d",x[7]);
   printf("%17d",x[8]);  
   if((arquivo=fopen("jogo.txt","w"))==NULL) 
     printf("Erro na criação do arquivo!\n");
     else
     {    for(i=0;i<6;i++) 
           fprintf(arquivo,"%4d",x[i]);
           fprintf(arquivo,"%8d",x[7]);
           fprintf(arquivo,"%17d",x[8]);         
     }
}
main()
{  setlocale(LC_ALL,"portuguese");
   explicajogo();
   system("pause");
   system("cls");
	 printf("Este programa gera um jogo simples da Itália - SuperEnalotto e grava num arquivo texto: jogo.txt.\n");
   printf("Para verificar quantos pontos fez, acione o programa verificador.c\n");
   printf("Fim.\n");
   GeraJogo();
}
