/**
Instituto Federal do Cear�
Nome: Jefferson Santos do Nascimento 
Matricula: 20182013020064

2) Fa�a outro programa que leia o arquivo texto do programa anterior, pe�a ao
   usu�rio os resultados oficiais da sua loteria e escreva quantos pontos foram
   feitos.
**/
//Programa verificador da It�lia - SuperEnalotto.
#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
main()
{  int i,x[8],resultado[8],pontos=0,j;
   FILE *arquivo;
   setlocale(LC_ALL,"portuguese");
   if((arquivo=fopen("jogo.txt","r"))==NULL) 
    printf("Erro na leitura do arquivo!\n");
     else
     { i=0;  
	   while(fscanf(arquivo,"%d",&x[i++])!=EOF);
     }
   printf("Este programa verifica quantos pontos foram feitos na It�lia - SuperEnalotto.\n");
   printf("O arquivo jogo.txt tem o seguinte jogo armazenado\n");
   printf("\nJogo armazenado:\n"); 
   for(i=0;i<8;i++)
    printf("%6d",x[i]);
   printf("\n\nDigite o resultado oficial da It�lia - SuperEnalotto:\n"); 
   printf("\tMain Numbers + Jolly + SuperStar\n\t   ");
   for(i=0;i<8;i++)
    scanf("%d",&resultado[i]);
   printf("\nO resultado oficial da It�lia - SuperEnalotto foi:\n");
   printf("\t\tMain Numbers\t\t Jolly\t\tSuperStar\n");
   for(i=0;i<6;i++)
    printf("%6d",resultado[i]);
    printf("%8d",resultado[6]);
   	printf("%17d",resultado[7]); 
   for(i=0;i<6;i++)
    for(j=0;j<6;j++)
	  if(x[i]==resultado[j])
	    pontos++;  
	  if(pontos!=5 && x[7]==resultado[7])   
   	printf("\n\n Voc� acertou %d pontos + SuperStar\n",pontos);
   	else
   	{if(pontos==5 && x[6]==resultado[6])
	   	{if(x[7]==resultado[7])
			   {
					 printf("\n\nVoc� acertou %d pontos e por isso ser� levado em conta o Jolly como n�mero bonus !\n",pontos);
			   	 printf("Como vc acertou o Jolly e tamb�m a SuperStar, sua pontua��o foi:\n");
			   	 printf("\t\tJackpot\t Jolly\tSuperStar\n");
			   	 printf("\t\t%6d\t+  1  +\t 1",pontos);
			   }else
			   	{
					 printf("\n\nVoc� acertou %d pontos e por isso ser� levado em conta o Jolly como n�mero bonus !\n",pontos);
			   	 printf("Como vc acertou o Jolly tamb�m, sua pontua��o foi:\n");
			   	 printf("\t\tJackpot\tJolly\n");
			   	 printf("\t\t%6d + 1",pontos);
				 	}	   
	   	}else
   		{if(pontos==5 && x[6]!=resultado[6])
   			{
		   	 printf("\n\nVoc� acertou %d pontos e por isso ser� levado em conta o Jolly como n�mero bonus !\n",pontos);
		   	 printf("Como vc n�o acertou o Jolly sua pontua��o foi:\n");
				 printf("\t\t%d pontos\n",pontos);
				}else
					{if(pontos==1)
						printf("\n\n Infelizmente voc� n�o ganhou nada pois acertou apenas %d ponto.\n",pontos);
					 else
					 	printf("\n\n Voc� acertou %d pontos.\n",pontos);
					}	   
			}
		}	 
   printf("\nFim.\n"); 
}
