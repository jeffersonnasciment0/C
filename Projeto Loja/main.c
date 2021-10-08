#include "entities.h"


int pergunta (char *resposta){
	if((*resposta) == "s" || (*resposta) == "S")
		return 1;
	else
		return 0;
}

int main()
{
  int nome, idade,resp;
  cliente Jefferson;

  Jefferson.idade = 22;

  if (!Jefferson.idade){
  	    printf("Erro na gravacao de idade !");
	}else{
  	printf("Idade de Jefferson gravada com sucesso !\n");
  	printf("Deseja verificar ?(s/n)");
  	scanf("%c",&resp);
  	
  }
		pergunta(resp);
  	if(pergunta(resp)){
  		printf("Ok... passando informações de Jefferson");
  		printf("%i",);
		}
  
    

}
