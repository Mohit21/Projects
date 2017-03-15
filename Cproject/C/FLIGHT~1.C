//**************************************
//
//INCLUDE files for :FLIGHT MANAGER
//**************************************
//
//author:Jose Ivo Fernandes
//GNU license
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define Empty(m) (m == NULL)

typedef char string[30];
typedef struct travel {
  int ticket_travel;
  string Name;
  struct travel *prox;
} *List;

typedef struct travel2 {
  int number;
  string Itinerary;
  List passageiros;
  struct travel2 *prox;
} *Flight;

int numFlight=0,numpassangers=0;
int numticket_travel=0,flag=0,ok=0;
 string Namepassangers;

  List deletar(string Name, List l) {
  List aux;
  int comp;

  if (Empty(l)) return (l);
  comp = strcmp(Name, l->Name);
  if (comp < 0) {
    return (l);
  } else {
    if (comp > 0) {
      l->prox = deletar(Name, l->prox);
      return (l);
    } else {
      aux = l->prox;
      free(l);
      return(aux);
    }
  }
}

void imprimir(List l) {
  List temp = l;
  while (!Empty(temp)) {
    numpassageiros++;
    printf("\t %s: Ticket Travel %.2d \n", temp->Name,temp->ticket_travel);
    temp=temp->prox;
  }
}

void ListrFlight(Flight v, int controle) {
  Flight aux=v;
  while (!Empty(aux)) {
     printf("\n Flight %.4d - %s \n", aux->number, aux->Itinerary);
     numpassageiros=0;
       if(controle==0)
       imprimir(aux->passageiros);
     aux=aux->prox;
   }
   getch();
}

List insereprimeiro(int n, string Name, List l) {
  List aux;
  aux = malloc ( sizeof(struct travel) );
  strcpy(aux->Name, Name);
  aux->ticket_travel=n;
  aux->prox = l;
  return (aux);
}

List insereordenado (int numticket_travel ,string Name, List l) {
  int cmp;

  if (Empty(l)) {
    return (insereprimeiro(numticket_travel, Name, l));
  }
  cmp = strcmp(Name, l->Name);
  if (cmp < 0) {
    return (insereprimeiro(numticket_travel, Name, l));
  } else {
    if (cmp > 0) {
      l->prox = insereordenado(numticket_travel, Name, l->prox);
      return (l);
    } else {
      return (l);
    }
  }
}

Flight Reservaticket_travel(Flight v) {
  Flight aux=v;
  Flight aux2=v;
  List x=NULL;;
// int numFlight=0,numticket_travel=0,flag=0,ok=0;
// string Namepassageiros;
  printf("number do Flight :");
  scanf("%d",&numFlight);
  while(!Empty(aux)){
    if(aux->number==numFlight)
    {
      printf("Digite o Name: " );
      getchar();
      gets(Namepassageiros);
      do{
	ok=1;
	printf("Digite o number do ticket_travel: " );
	scanf("%d",&numticket_travel);
	x=aux->passageiros;
	while(!Empty(x)){
	   if (x->ticket_travel==numticket_travel){
	     printf("Poltrona Ocupada \n");
	     ok=0;
	   }
	 x=x->prox;
       }
     }while(ok==0);

      aux->passageiros = insereordenado (numticket_travel,Namepassageiros,aux->passageiros);
      flag=1;
      return(aux);
    }
    aux=aux->prox;
  }
  if (flag==0){
    printf("Inexiste Flight!");
    aux=aux2;return(aux);
  }
}

Flight ExcluirReserva(Flight v) {
  Flight aux=v;
  Flight aux2=v;
  int numFlight=0,numticket_travel,flag=0;
  string Namepassageiros;
  printf("number do Flight :");
  scanf("%d",&numFlight);
  while(!Empty(aux)){
    if(aux->number==numFlight)
    {
      printf("Digite o Name do Passageiro: " );
      getchar();
      gets(Namepassageiros);
      aux->passageiros = deletar(Namepassageiros,aux->passageiros);
      flag=1;
      return(aux);
    }
    aux=aux->prox;
  }
  if (flag==0){
    printf("Flight nao localizado");
    aux=aux2;return(aux);
  }
}


void verificapassageiros(List l, string no, int num, string Itinerary) {
  List temp = l;
  int flag=0;
  string Name;
  int nFlight = num;
  string dest;

  strcpy(Name,no);
  while (!Empty(temp)) {
     if(strcmp(Name,temp->Name)==0){
	 printf("Flight %.4d - Itinerary : %s - ticket_travel %.2d - %s \n", num,Itinerary,temp->ticket_travel,temp->Name);
      //	 printf("\n%s- Itinerary :",Itinerary);
     }
    temp=temp->prox;
  }

}

void checkin(Flight v) {
  Flight aux=v;
  string Name="";

  if(Empty(aux)){printf(" No have Programmed Flight! ");}
  else{
  printf("Enter Name : ");
  getchar();
  gets(Name);
  while (!Empty(aux)) {
     verificapassageiros(aux->passageiros,Name,aux->number,aux->Itinerary);
     aux=aux->prox;
   }
  }
   getch();
}

Flight insereFlight(Flight v) {
  Flight aux;
  List auxN=NULL;

  string Itinerary;
  aux = malloc ( sizeof(struct travel2) );
  printf("Itinerary->: ");
  getchar();
  gets(Itinerary);numFlight++;
  printf("Flight Number->: %d ",numFlight);
  getchar();
  aux->number = numFlight;
  strcpy(aux->Itinerary,Itinerary);
  aux->passageiros = auxN;
  aux->prox = v;
  return(aux);
}

 char opcao(){
	char op=' ';
		printf("\nEnter your Choice!: ");
		scanf("%c",&op);
	return op;
}
void menu(){
	textattr(48);
	clrscr();
	printf("\n   <----FLIGHT MANAGER----> ");
	printf("\n 1 <-Flight Insert! ->");
	printf("\n 2 <-Flight List!-> ");
	printf("\n 3 <-Ticket Travel Reserve!->");
	printf("\n 4 <-List Reserve! ->");
	printf("\n 5 <-Research Reserve !->  ");
	printf("\n 6 <-Reserve Exclude!->  ");
	printf("\n 7 <-Exit->");




}
int main(){
Flight v=NULL;
string no;
int num,Flight;
     char op;
      do{
		menu();
		op=opcao();
		switch (op){

			case '1':  v=insereFlight(v);
			break;
			case '2':  ListrFlight(v,1);
			break;
			case '3':  Reservaticket_travel(v);
			break;
			case '4':  ListrFlight(v,0);
			break;
			case '5':  checkin(v);
			break;
			case '6':  ExcluirReserva(v);
			break;
			case '7':
			break;

		}
	 }
	while (op!='7');
  }
