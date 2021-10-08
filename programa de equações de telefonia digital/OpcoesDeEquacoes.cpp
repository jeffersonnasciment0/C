/**
Nome: Jefferson santos do Nascimento

Este programa aux�lia o usu�rio na disciplina de Telefonia Digital com o conte�do de PCM30

Abrevia��es em vari�veis:
n_canais -> n�mero de canais
n_bitsquadro -> n�mero de canais do quadro
n_bits -> n�mero de bits
tq -> tempo de quadro
t_multiquadro -> tempo de multiquadro
t_quadro -> tempo de quadro
tslot -> timeslot
tbit -> tempo de bit
multi_tq -> Multiplica��o usando o valor de tempo de quadro
n_bits_sinalizacao -> N�mero de bits da sinaliza��o
taxa_sincro -> taxa de sincroniza��o.
op -> op��o
**/
#include<stdio.h>
#include<locale.h>
#include<math.h> 
#include<stdlib.h> 
#include<conio.h> 

void descreve (void)
{ // Esta fun��o descreve o problema a ser resolvido para o usu�rio do programa. 
	printf("Este programa aux�lia o usu�rio na disciplina de Telefonia digital no conte�do de sistema PCM30.\n");
	printf("Tendo os valores tempo de multiquadro, n�mero de canais e bits, voc� conseguir� aqui as seguintes caracter�sticas:\n");
	printf("1) - n� de bit's por quadro;\n");
	printf("2) - Tempo de quadro;\n");
	printf("3) - Timeslot;\n");
	printf("4) - Tbit;\n");
	printf("5) - Taxa de canal;\n");
	printf("6) - Taxa de sistema;\n");
	printf("7) - Taxa de sincronismo;\n");
	printf("8) - Taxa de sinaliza��o.\n");
	system("pause");
	system("cls");
}
void itens(void)
{ // Esta fun��o mostra ao usu�rio os itens para as op��es de escolha que ele tem.
	printf("Selecione uma op��o:\n");
	printf("1) - n� bit's quadro:\n");
	printf("2) - T quadro:\n");
	printf("3) - timeslot:\n");
	printf("4) - tbit:\n");
	printf("5) - taxa canal:\n");
	printf("6) - Taxa sistema:\n");
	printf("7) - Taxa sincronismo:\n");
	printf("8) - Taxa sinaliza��o:\n");
	printf("9) - Todos os itens:\n");
	printf("-------------------------\n");
	printf("a - Salvar todos resultados em um arquivo:\n");
	printf("b - sair do programa\n");
	printf("-------------------------\n");
}

int n_bits_quadro (int n_canais, int n_bits)
{	// Esta fun��o define o n�mero de bits do quadro. N�mero de bits do quadro = n�mero de canais * n�mero de bits do canal.
	int adicao_canais_adicionais, n_bitsquadro;
	adicao_canais_adicionais = n_canais + 2;
	n_bitsquadro = adicao_canais_adicionais * n_bits;
	return n_bitsquadro;
}

float t_quadro(int t_multiquadro,int n_canais)
{	// Esta fun��o define o tempo de quadro. 
	float tq,resultado_div;
	int adicao_canais_adicionais;
	adicao_canais_adicionais = n_canais + 2;
	resultado_div=adicao_canais_adicionais/2;
	tq=t_multiquadro/resultado_div;
	return tq;
}

float func_timeslot(int t_multiquadro,int n_canais)
{	// Esta fun��o define o timeslot. ttime slot = tquadro/ n�mero de canais
	int adicao_canais_adicionais;
	float tq, timeslot;
	adicao_canais_adicionais = n_canais + 2;
	tq=t_quadro(t_multiquadro,n_canais);
	timeslot = tq/adicao_canais_adicionais;	
	return timeslot;
}

float tbit(int t_multiquadro,int n_canais,int n_bits)
{	// Esta fun��o define o tempo de bit. tbit= ttime slot/ n�mero de bits
	float tbit,tslot;
	tslot=func_timeslot(t_multiquadro,n_canais);
	tbit=tslot/n_bits;	
	return tbit;
}

float func_taxa_canal(int t_multiquadro,int n_canais,int n_bits)
{	// Esta fun��o define a taxa do canal. taxa canal = N� de bits do canal/tq
	float taxa_canal,tq;
	tq=t_quadro(t_multiquadro,n_canais);
	taxa_canal=n_bits/tq;
	return taxa_canal;
}

float func_taxa_sistema(int t_multiquadro,int n_canais, int n_bits)
{	// Esta fun��o define a taxa do sistema. taxa sistema = N� de bits do quadro/tq
	float n_bitsquadro, tq, taxa_sistema; 
	n_bitsquadro=n_bits_quadro (n_canais,n_bits);
	tq=t_quadro(t_multiquadro,n_canais);
	taxa_sistema=n_bitsquadro/tq;	
	return taxa_sistema;
}

float taxa_sincronismo(int t_multiquadro,int n_canais, int n_bits)
{	// Esta fun��o define a taxa de sincronismo. taxa de sincronismo = N� de bits do sincronismo/2*tq
	float tq, multi_tq, taxa_sincronismo;
	tq=t_quadro(t_multiquadro,n_canais);
	multi_tq=2*tq;
	taxa_sincronismo=n_bits/multi_tq;
	return taxa_sincronismo;
}

float func_taxa_sinalizacao(int t_multiquadro, int n_bits)
{	// Esta fun��o define a taxa de sinaliza��o. taxa sinaliza��o = N� de bits da sinaliza��o de um canal/tmultiquadro
	float n_bits_sinalizacao,taxa_sinalizacao;
	n_bits_sinalizacao=n_bits/2;
	taxa_sinalizacao=n_bits_sinalizacao/t_multiquadro;
	return taxa_sinalizacao;
}

main()
{
  setlocale(LC_ALL,"Portuguese");
  FILE *arquivo;
	char op;
  int n_bits,n_canais,n_bitsquadro,t_multiquadro; 
  float tq,tempo_quadro,timeslot,t_bit,taxa_canal,taxa_sistema,taxa_sincro,taxa_sinalizacao;
  descreve(); 
  printf("Digite o 'tempo de multiquadro' o 'numero de canais' de voz e o 'n�mero de bits':\nEXE.: 10 16 12\n");
	scanf("%d%d%d",&t_multiquadro,&n_canais,&n_bits);
do	
 {	system("cls");
    itens(); 
		op=getch();
		switch (op) // Utiliza o caracter lido pelo getch para iniciar a case.
	{ 
case '1':
	  {	n_bitsquadro=n_bits_quadro(n_canais,n_bits);
			printf("N�mero de bits por quadro -> %d bits\n",n_bitsquadro);
			break;
		}
case '2':
	  {	tq=t_quadro(t_multiquadro,n_canais);
			printf("Tempo quadro -> %f s\n",tq);
			break;
	  }	  
case '3':
    {	timeslot=func_timeslot(t_multiquadro,n_canais);	
			printf("Timeslot -> %f s\n",timeslot);
			break;
	  }	
case '4':
	  {	t_bit=tbit(t_multiquadro,n_canais,n_bits);
			printf("tbit -> %f s\n",t_bit);
			break;
		}
case '5':
	  {	taxa_canal=func_taxa_canal(t_multiquadro,n_canais,n_bits);
			printf("Taxa canal -> %f bps\n",taxa_canal);
			break;
		}		
case '6':
	  {	taxa_sistema=func_taxa_sistema(t_multiquadro,n_canais,n_bits);
			printf("Taxa sistema -> %f bps\n",taxa_sistema);
			break;
		}
case '7':
	  {	taxa_sincro=taxa_sincronismo(t_multiquadro,n_canais,n_bits);
			printf("Taxa de Sincronismo -> %f bps\n",taxa_sincro);
			break;
		}
case '8':
	  {	taxa_sinalizacao=func_taxa_sinalizacao(t_multiquadro,n_bits);
			printf("Taxa de sinaliza��o -> %f bps\n",taxa_sinalizacao);
			break;
		}
case '9':
	  {	n_bitsquadro=n_bits_quadro(n_canais,n_bits);
			printf("N�mero de bits por quadro -> %d bits\n",n_bitsquadro);				
			tq=t_quadro(t_multiquadro,n_canais);
			printf("Tempo quadro -> %f s\n",tq);
			timeslot=func_timeslot(t_multiquadro,n_canais);	
			printf("Timeslot -> %f s\n",timeslot);
			t_bit=tbit(t_multiquadro,n_canais,n_bits);
			printf("tbit -> %f s\n",t_bit);
			taxa_canal=func_taxa_canal(t_multiquadro,n_canais,n_bits);
			printf("Taxa canal -> %f bps\n",taxa_canal);	
			taxa_sistema=func_taxa_sistema(t_multiquadro,n_canais,n_bits);
			printf("Taxa sistema -> %f bps\n",taxa_sistema);
			taxa_sincro=taxa_sincronismo(t_multiquadro,n_canais,n_bits);
			printf("Taxa de Sincronismo -> %f bps\n",taxa_sincro);
			taxa_sinalizacao=func_taxa_sinalizacao(t_multiquadro,n_bits);
			printf("Taxa de sinaliza��o -> %f bps\n",taxa_sinalizacao);	
			break;
		}
case 'a':
		{ if((arquivo=fopen("Resultado_PCM30.txt","w"))==NULL) 
      printf("Erro na cria��o do arquivo!\n");
      else
      { n_bitsquadro=n_bits_quadro(n_canais,n_bits);
				fprintf(arquivo,"N�mero de bits por quadro -> %d bits\n",n_bitsquadro);				
				tq=t_quadro(t_multiquadro,n_canais);
				fprintf(arquivo,"Tempo quadro -> %f s\n",tq);
				timeslot=func_timeslot(t_multiquadro,n_canais);	
				fprintf(arquivo,"Timeslot -> %f s\n",timeslot);
				t_bit=tbit(t_multiquadro,n_canais,n_bits);
				fprintf(arquivo,"tbit -> %f s\n",t_bit);
				taxa_canal=func_taxa_canal(t_multiquadro,n_canais,n_bits);
				fprintf(arquivo,"Taxa canal -> %f bps\n",taxa_canal);	
				taxa_sistema=func_taxa_sistema(t_multiquadro,n_canais,n_bits);
				fprintf(arquivo,"Taxa sistema -> %f bps\n",taxa_sistema);
				taxa_sincro=taxa_sincronismo(t_multiquadro,n_canais,n_bits);
				fprintf(arquivo,"Taxa de Sincronismo -> %f bps\n",taxa_sincro);
				taxa_sinalizacao=func_taxa_sinalizacao(t_multiquadro,n_bits);
				fprintf(arquivo,"Taxa de sinaliza��o -> %f bps\n",taxa_sinalizacao); 
				printf("Cria��o de arquivo realizada com sucesso !\n Acesse o arquivo Resultado_PCM30.txt e para ver os resultados armazenados !\n");      
      }
			break;
		}
case 'b':
    {	printf("Fim");
		 	exit(1);
		 	break;
	  }
default: 
	    {  printf("Op��o inv�lida!");
	       break;
	    }
   }
	getch();
 }while(op != 'b'); 
}
