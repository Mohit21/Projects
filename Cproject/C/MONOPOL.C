#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>

struct player *create();

void play(struct player *);

struct player
{
 char colour[10];
 int sno;
 long amount;
 int chance;
 int jail;
 int jail1;
 struct player *next;
};
struct player *ticket[30];
int a[30];
int h1[30];
int q[30];

long *bank;
void display(struct player *);


void main()
{
struct player *p1;
int i;
int j, m=9, n=2;
initgraph(&m,&n,"c:\\tc\\bgi");   /* Graphics drive path */
settextstyle(7,0,3);
 for(j=480;j>=50;j-=5)
 {
  cleardevice();
  setcolor(j/4);
  sound(j*10);
  outtextxy(j,j+20,"Welcome to an monopoly gaming experience !!");
  delay(40);
 }
 delay(2000);
 nosound();
 closegraph();
*bank=1000000;
clrscr();
for(i=0;i<30;i++)
{
a[i]=0;
h1[i]=0;
q[i]=0;
}
printf("bank has %lu money\n\n",*bank);
p1=create();
display(p1);
play(p1);
display(p1);
getch();
}


struct player *create()
{
 struct player *p1,*head,*back;
 int n,i;
 printf("Enter number of players want to play\n\n");
 printf("Maximum number should be less than equal to 10............");
 scanf("%d",&n);
 head=(struct player *)malloc(sizeof(struct player));
 printf("Enter player NAME........");
 fflush(stdin);
 gets(head->colour);
 printf("Enter player number.........");
 scanf("%d",&head->sno);
 head->amount=50000;
 head->chance=1;head->jail=0;head->jail1=0;
 head->next=NULL;
 back=head;
 for(i=1;i<n;i++)
  {
   p1=(struct player *)malloc(sizeof(struct player));
   printf("Enter player NAME..........");
   fflush(stdin);
   gets(p1->colour);
   printf("Enter player number..........");
   scanf("%d",&p1->sno);
   p1->amount=50000;
   p1->chance=1;p1->jail=0;p1->jail1=0;
   back->next=p1;
   back=p1;
  }
   back->next=head;
   return head;
}


void bombay(struct player *);
void ahmdabad(struct player *);
void indore(struct player *);
void jaipur(struct player *);
void delhi(struct player *);
void chandi(struct player *);
void shimla(struct player *);
void amrit(struct player *);
void shri(struct player *);
void agra(struct player *);
void kanpur(struct player *);
void patna(struct player *);
void darj(struct player *);
void calc(struct player *);
void hyd(struct player *);
void madras(struct player *);
void goa(struct player *);
void water(struct player *);
void rail(struct player *);
void jail(struct player *);
void rest(struct player *,int );
void club(struct player *,int );



void play(struct player *p1)
{
 struct player *p;
 int dice=0;
 int i=0;
 char ch,d;
 p=p1;
 while(p->next==p1)
 {
 i++;
 }
 randomize();
 turn:
 fflush(stdin);
 clrscr();
 printf("%s player's turn\n\n",p->colour);
 if(p->jail==1)
  {
   printf("player is at jail\n");
   if(p->jail1==0)
     {
      printf("player has to skip 2 more turns\n");
     p->jail1++; p=p->next;
      goto turn;
      }
   if(p->jail1==1)
     {
      printf("player has to skip 1 more turns\n");
      p->jail1++; p=p->next;
      goto turn;
      }
   if(p->jail1==2)
     {
      printf("player has to skip no more turns\n");
      p->jail1=0;
      p->jail=0;p=p->next;
      goto turn;
      }
   }

 while(1)
 {
 printf("Press D to throw dice\n\n");
 scanf("%c",&d);
 if(d=='d'||d=='D')
  {
   dice=random(6)+1;
   printf("You got %d....\n",dice);
   break;
  }
 }
 p->chance=p->chance+dice;
 if(p->chance>23)
  {
   printf("You have completed one complete round\n");
   printf("You will get Rs.1500 \n\n");
   p1->amount=p1->amount+1500;
   printf("Your amount increased to Rs.%lu\n\n",p1->amount);
   p->chance=p->chance-23;
  }
 switch(p->chance)
  {
   case 1:
	  printf("You reached START\n\n");
	  printf("JUST REST\n\n");
	  break;
   case 2:
	  printf("You reached bombay\n\n");
	  bombay(p);
	  break;
   case 3:
	  printf("You reached waterworks\n\n");
	  water(p);
	  break;
   case 4:
	  printf("You reached ahmedabad\n\n");
	  ahmdabad(p);
	  break;
   case 5:
	  printf("You reached indore\n\n");
	  indore(p);
	  break;
   case 6:
	  printf("You reached jaipur\n\n");
	  jaipur(p);
	  break;
   case 7:
	  printf("You reached jail\n\n");
	  jail(p);
	  break;
   case 8:
	  printf("You reached delhi\n\n");
	  delhi(p);
	  break;
   case 9:
	  printf("You reached chandigarh\n\n");
	  chandi(p);
	  break;
   case 10:
	  printf("You reached railways\n\n");
	  rail(p);
	  break;
   case 11:
	  printf("You reached shimla\n\n");
	  shimla(p);
	  break;
   case 12:
	  printf("You reached amritsar\n\n");
	  amrit(p);
	  break;
   case 13:
	  printf("You reached shrinagar\n\n");
	  shri(p);
	  break;
   case 14:
	  printf("You reached rest house\n\n");
	  rest(p,i);
	  break;
   case 15:
	  printf("You reached agra\n\n");
	  agra(p);
	  break;
   case 16:
	  printf("You reached kanpur\n\n");
	  kanpur(p);
	  break;
   case 17:
	  printf("You reached patna\n\n");
	  patna(p);
	  break;
   case 18:
	  printf("You reached darjeeling\n\n");
	  darj(p);
	  break;
   case 19:
	  printf("You reached calcutta\n\n");
	  calc(p);
	  break;
   case 20:
	  printf("You reached hyderabad\n\n");
	  hyd(p);
	  break;
   case 21:
	  printf("You reached club\n\n");
	  club(p,i);
	  break;
   case 22:
	  printf("You reached madras\n\n");
	  madras(p);
	  break;
   case 23:
	  printf("You reached goa\n\n");
	  goa(p);
	  break;
	}
   printf("do you want to play next turn\n\n");
   do
   {
   printf("Press Y for yes and N for no.........");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='y' || ch=='Y')
    {
     p=p->next;
     goto turn;
    }
   else if(ch=='n' || ch=='N')
   {
   clrscr();
     printf("\n \t \t !!!!EXITING THE GAME!!!! ");
     getch();
     exit(0);
     break;
     }
    }while(1);
 }

int house(int ,struct player *);

void bombay(struct player *p1)
{

 char ch;
 if(a[1]==0)
  {

   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[1]=p1;
     q[1]=ticket[1]->sno;
     a[1]++;
     ticket[1]->amount=ticket[1]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[1]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[1]=house(h1[1],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[1]->colour);
   switch(h1[1])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
	    ticket[1]->amount=ticket[1]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[1]->colour,ticket[1]->amount);
	    break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
	    p1->amount=p1->amount-1000;
	    ticket[1]->amount=ticket[1]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[1]->colour,ticket[1]->amount);
	    break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
	    p1->amount=p1->amount-2000;
	    ticket[1]->amount=ticket[1]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[1]->colour,ticket[1]->amount);
	    break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
	    p1->amount=p1->amount-3000;
	    ticket[1]->amount=ticket[1]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[1]->colour,ticket[1]->amount);
	    break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
	    p1->amount=p1->amount-4000;
	    ticket[1]->amount=ticket[1]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[1]->colour,ticket[1]->amount);
	    break;
    }
  }
 x:
}


void ahmdabad(struct player *p1)
{

 char ch;
 if(a[2]==0)
  {

   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[2]=p1;
     q[2]=ticket[2]->sno;
     a[2]++;
     ticket[2]->amount=ticket[2]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[2]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[2]=house(h1[2],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[2]->colour);
   switch(h1[2])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
	    ticket[2]->amount=ticket[2]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[2]->colour,ticket[2]->amount);
	    break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
	    p1->amount=p1->amount-1000;
	    ticket[2]->amount=ticket[2]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[2]->colour,ticket[2]->amount);
	    break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
	    p1->amount=p1->amount-2000;
	    ticket[2]->amount=ticket[2]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[2]->colour,ticket[2]->amount);
	    break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
	    p1->amount=p1->amount-3000;
	    ticket[2]->amount=ticket[2]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[2]->colour,ticket[2]->amount);
	    break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
	    p1->amount=p1->amount-4000;
	    ticket[2]->amount=ticket[2]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[2]->colour,ticket[2]->amount);
	    break;
    }
  }
 x:
}


void indore(struct player *p1)
{

 char ch;
 if(a[3]==0)
  {

   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[3]=p1;
     q[3]=ticket[3]->sno;
     a[3]++;
     ticket[3]->amount=ticket[3]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[3]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[3]=house(h1[3],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[3]->colour);
   switch(h1[3])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
	    ticket[3]->amount=ticket[3]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[3]->colour,ticket[3]->amount);
	    break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
	    p1->amount=p1->amount-1000;
	    ticket[3]->amount=ticket[3]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[3]->colour,ticket[3]->amount);
	    break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
	    p1->amount=p1->amount-2000;
	    ticket[3]->amount=ticket[3]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[3]->colour,ticket[3]->amount);
	    break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
	    p1->amount=p1->amount-3000;
	    ticket[3]->amount=ticket[3]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[3]->colour,ticket[3]->amount);
	    break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
	    p1->amount=p1->amount-4000;
	    ticket[3]->amount=ticket[3]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[3]->colour,ticket[3]->amount);
	    break;
    }
  }
 x:
}


void jaipur(struct player *p1)
{

 char ch;
 if(a[4]==0)
  {

   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[4]=p1;
     q[4]=ticket[4]->sno;
     a[4]++;
     ticket[4]->amount=ticket[4]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[4]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[4]=house(h1[4],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[4]->colour);
   switch(h1[4])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
	    ticket[4]->amount=ticket[4]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[4]->colour,ticket[4]->amount);
	    break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
	    p1->amount=p1->amount-1000;
	    ticket[4]->amount=ticket[4]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[4]->colour,ticket[4]->amount);
	    break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
	    p1->amount=p1->amount-2000;
	    ticket[4]->amount=ticket[4]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[4]->colour,ticket[4]->amount);
	    break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
	    p1->amount=p1->amount-3000;
            ticket[4]->amount=ticket[4]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[4]->colour,ticket[4]->amount);
	    break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[4]->amount=ticket[4]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[4]->colour,ticket[4]->amount);
            break;
    }
  }
 x:
}


void delhi(struct player *p1)
{
 
 char ch;
 if(a[5]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[5]=p1;
     q[5]=ticket[5]->sno;
     a[5]++;
     ticket[5]->amount=ticket[5]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[5]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[5]=house(h1[5],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[5]->colour);
   switch(h1[5])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
            ticket[5]->amount=ticket[5]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[5]->colour,ticket[5]->amount);
	    break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
	    p1->amount=p1->amount-1000;
            ticket[5]->amount=ticket[5]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[5]->colour,ticket[5]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
            p1->amount=p1->amount-2000;
            ticket[5]->amount=ticket[5]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[5]->colour,ticket[5]->amount);
	    break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
	    p1->amount=p1->amount-3000;
            ticket[5]->amount=ticket[5]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[5]->colour,ticket[5]->amount);
	    break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
	    ticket[5]->amount=ticket[5]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[5]->colour,ticket[5]->amount);
            break;
    }
  }
 x:
}


void chandi(struct player *p1)
{
 
 char ch;
 if(a[6]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[6]=p1;
     q[6]=ticket[6]->sno;
     a[6]++;
     ticket[6]->amount=ticket[6]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[6]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[6]=house(h1[6],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[6]->colour);
   switch(h1[6])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
            ticket[6]->amount=ticket[6]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[6]->colour,ticket[6]->amount);
	    break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
	    p1->amount=p1->amount-1000;
            ticket[6]->amount=ticket[6]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[6]->colour,ticket[6]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
            p1->amount=p1->amount-2000;
            ticket[6]->amount=ticket[6]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[6]->colour,ticket[6]->amount);
	    break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
	    p1->amount=p1->amount-3000;
            ticket[6]->amount=ticket[6]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[6]->colour,ticket[6]->amount);
	    break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[6]->amount=ticket[6]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[6]->colour,ticket[6]->amount);
            break;
    }
  }
 x:
}


void shimla(struct player *p1)
{
 
 char ch;
 if(a[7]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[7]=p1;
     q[7]=ticket[7]->sno;
     a[7]++;
     ticket[7]->amount=ticket[7]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[7]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[7]=house(h1[7],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[7]->colour);
   switch(h1[7])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
            ticket[7]->amount=ticket[7]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[7]->colour,ticket[7]->amount);
	    break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
	    p1->amount=p1->amount-1000;
            ticket[7]->amount=ticket[7]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[7]->colour,ticket[7]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
            p1->amount=p1->amount-2000;
            ticket[7]->amount=ticket[7]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[7]->colour,ticket[7]->amount);
	    break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
	    p1->amount=p1->amount-3000;
	    ticket[7]->amount=ticket[7]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[7]->colour,ticket[7]->amount);
	    break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[7]->amount=ticket[7]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[7]->colour,ticket[7]->amount);
            break;
    }
  }
 x:
}


void amrit(struct player *p1)
{
 
 char ch;
 if(a[8]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[8]=p1;
     q[8]=ticket[8]->sno;
     a[8]++;
     ticket[8]->amount=ticket[8]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[8]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[8]=house(h1[8],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[8]->colour);
   switch(h1[8])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
            ticket[8]->amount=ticket[8]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[8]->colour,ticket[8]->amount);
	    break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
	    p1->amount=p1->amount-1000;
            ticket[8]->amount=ticket[8]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[8]->colour,ticket[8]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
            p1->amount=p1->amount-2000;
            ticket[8]->amount=ticket[8]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[8]->colour,ticket[8]->amount);
	    break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
	    p1->amount=p1->amount-3000;
            ticket[8]->amount=ticket[8]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[8]->colour,ticket[8]->amount);
	    break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[8]->amount=ticket[8]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[8]->colour,ticket[8]->amount);
            break;
    }
  }
 x:
}




void shri(struct player *p1)
{
 
 char ch;
 if(a[9]==0)
  {

   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[9]=p1;
     q[9]=ticket[9]->sno;
     a[9]++;
     ticket[9]->amount=ticket[9]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[9]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[9]=house(h1[9],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[9]->colour);
   switch(h1[9])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
            p1->amount=p1->amount-500;
            ticket[9]->amount=ticket[9]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[9]->colour,ticket[9]->amount);
            break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
            p1->amount=p1->amount-1000;
	    ticket[9]->amount=ticket[9]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[9]->colour,ticket[9]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
            p1->amount=p1->amount-2000;
            ticket[9]->amount=ticket[9]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[9]->colour,ticket[9]->amount);
            break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
            p1->amount=p1->amount-3000;
            ticket[9]->amount=ticket[9]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[9]->colour,ticket[9]->amount);
            break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[9]->amount=ticket[9]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[9]->colour,ticket[9]->amount);
            break;
    }
  }
 x:
} 


void agra(struct player *p1)
{
 
 char ch;
 if(a[10]==0)
  {

   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[10]=p1;
     q[10]=ticket[10]->sno;
     a[10]++;
     ticket[10]->amount=ticket[10]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[10]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[10]=house(h1[10],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[10]->colour);
   switch(h1[10])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
            p1->amount=p1->amount-500;
            ticket[10]->amount=ticket[10]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[10]->colour,ticket[10]->amount);
            break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
            p1->amount=p1->amount-1000;
	    ticket[10]->amount=ticket[10]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[10]->colour,ticket[10]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
            p1->amount=p1->amount-2000;
            ticket[10]->amount=ticket[10]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[10]->colour,ticket[10]->amount);
            break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
            p1->amount=p1->amount-3000;
            ticket[10]->amount=ticket[10]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[10]->colour,ticket[10]->amount);
            break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[10]->amount=ticket[10]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[10]->colour,ticket[10]->amount);
            break;
    }
  }
 x:
} 


void kanpur(struct player *p1)
{
 
 char ch;
 if(a[11]==0)
  {

   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[11]=p1;
     q[11]=ticket[11]->sno;
     a[11]++;
     ticket[11]->amount=ticket[11]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[11]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[11]=house(h1[11],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[11]->colour);
   switch(h1[11])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
            p1->amount=p1->amount-500;
            ticket[11]->amount=ticket[11]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[11]->colour,ticket[11]->amount);
            break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
            p1->amount=p1->amount-1000;
	    ticket[11]->amount=ticket[11]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[11]->colour,ticket[11]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
            p1->amount=p1->amount-2000;
            ticket[11]->amount=ticket[11]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[11]->colour,ticket[11]->amount);
            break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
            p1->amount=p1->amount-3000;
            ticket[11]->amount=ticket[11]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[11]->colour,ticket[11]->amount);
            break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[11]->amount=ticket[11]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[11]->colour,ticket[11]->amount);
            break;
    }
  }
 x:
} 


void patna(struct player *p1)
{

 char ch;
 if(a[12]==0)
  {

   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[12]=p1;
     q[12]=ticket[12]->sno;
     a[12]++;
     ticket[12]->amount=ticket[12]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[12]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[12]=house(h1[12],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[12]->colour);
   switch(h1[12])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
            p1->amount=p1->amount-500;
            ticket[12]->amount=ticket[12]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[12]->colour,ticket[12]->amount);
            break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
            p1->amount=p1->amount-1000;
	    ticket[12]->amount=ticket[12]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[12]->colour,ticket[12]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
            p1->amount=p1->amount-2000;
            ticket[12]->amount=ticket[12]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[12]->colour,ticket[12]->amount);
            break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
            p1->amount=p1->amount-3000;
            ticket[12]->amount=ticket[12]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[12]->colour,ticket[12]->amount);
            break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[12]->amount=ticket[12]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[12]->colour,ticket[12]->amount);
            break;
    }
  }
 x:
} 

void darj(struct player *p1)
{
 
 char ch;
 if(a[13]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[13]=p1;
     q[13]=ticket[13]->sno;
     a[13]++;
     ticket[13]->amount=ticket[13]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[13]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[13]=house(h1[13],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[13]->colour);
   switch(h1[13])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
            ticket[13]->amount=ticket[13]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[13]->colour,ticket[13]->amount);
            break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
            p1->amount=p1->amount-1000;
            ticket[13]->amount=ticket[13]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[13]->colour,ticket[13]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
	    p1->amount=p1->amount-2000;
            ticket[13]->amount=ticket[13]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[13]->colour,ticket[13]->amount);
            break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
            p1->amount=p1->amount-3000;
            ticket[13]->amount=ticket[13]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[13]->colour,ticket[13]->amount);
            break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[13]->amount=ticket[13]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[13]->colour,ticket[13]->amount);
	    break;
    }
  }
 x:
} 


void calc(struct player *p1)
{
 
 char ch;
 if(a[14]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[14]=p1;
     q[14]=ticket[14]->sno;
     a[14]++;
     ticket[14]->amount=ticket[14]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[14]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[14]=house(h1[14],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[14]->colour);
   switch(h1[14])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
            p1->amount=p1->amount-500;
            ticket[14]->amount=ticket[14]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[14]->colour,ticket[14]->amount);
            break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
            p1->amount=p1->amount-1000;
            ticket[14]->amount=ticket[14]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[14]->colour,ticket[14]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
	    p1->amount=p1->amount-2000;
            ticket[14]->amount=ticket[14]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[14]->colour,ticket[14]->amount);
            break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
            p1->amount=p1->amount-3000;
            ticket[14]->amount=ticket[14]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[14]->colour,ticket[14]->amount);
            break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[14]->amount=ticket[14]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[14]->colour,ticket[14]->amount);
	    break;
    }
  }
 x:
} 


void hyd(struct player *p1)
{
 
 char ch;
 if(a[15]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[15]=p1;
     q[15]=ticket[15]->sno;
     a[15]++;
     ticket[15]->amount=ticket[15]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[15]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[15]=house(h1[15],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[15]->colour);
   switch(h1[15])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
            p1->amount=p1->amount-500;
            ticket[15]->amount=ticket[15]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[15]->colour,ticket[15]->amount);
            break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
            p1->amount=p1->amount-1000;
            ticket[15]->amount=ticket[15]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[15]->colour,ticket[15]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
	    p1->amount=p1->amount-2000;
            ticket[15]->amount=ticket[15]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[15]->colour,ticket[15]->amount);
            break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
            p1->amount=p1->amount-3000;
            ticket[15]->amount=ticket[15]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[15]->colour,ticket[15]->amount);
            break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[15]->amount=ticket[15]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[15]->colour,ticket[15]->amount);
	    break;
    }
  }
 x:
} 

void madras(struct player *p1)
{
 
 char ch;
 if(a[16]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[16]=p1;
     q[16]=ticket[16]->sno;
     a[16]++;
     ticket[16]->amount=ticket[16]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[16]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[16]=house(h1[16],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[16]->colour);
   switch(h1[16])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
            ticket[16]->amount=ticket[16]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[16]->colour,ticket[16]->amount);
	    break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
	    p1->amount=p1->amount-1000;
            ticket[16]->amount=ticket[16]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[16]->colour,ticket[16]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
            p1->amount=p1->amount-2000;
	    ticket[16]->amount=ticket[16]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[16]->colour,ticket[16]->amount);
	    break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
	    p1->amount=p1->amount-3000;
            ticket[16]->amount=ticket[16]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[16]->colour,ticket[16]->amount);
	    break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[16]->amount=ticket[16]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[16]->colour,ticket[16]->amount);
            break;
    }
  }
 x:
}


void goa(struct player *p1)
{
 
 char ch;
 if(a[17]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[17]=p1;
     q[17]=ticket[17]->sno;
     a[17]++;
     ticket[17]->amount=ticket[17]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[17]==p1->sno)
  {
   printf("It is your ticket\n\n");
   h1[17]=house(h1[17],p1);
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[17]->colour);
   switch(h1[17])
    {
     case 0:
	    printf("player has no house standing\n\n");
	    printf("You have to pay Rs.500\n\n");
	    p1->amount=p1->amount-500;
            ticket[17]->amount=ticket[17]->amount+500;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[17]->colour,ticket[17]->amount);
	    break;
     case 1:
	    printf("player has first house standing\n\n");
	    printf("You have to pay Rs.1000\n\n");
	    p1->amount=p1->amount-1000;
            ticket[17]->amount=ticket[17]->amount+1000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[17]->colour,ticket[17]->amount);
            break;
     case 2:
	    printf("player has second house standing\n\n");
	    printf("You have to pay Rs.2000\n\n");
            p1->amount=p1->amount-2000;
	    ticket[17]->amount=ticket[17]->amount+2000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[17]->colour,ticket[17]->amount);
	    break;
     case 3:
	    printf("player has third house standing\n\n");
	    printf("You have to pay Rs.3000");
	    p1->amount=p1->amount-3000;
            ticket[17]->amount=ticket[17]->amount+3000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	    printf("%s amount increased to %lu\n\n",ticket[17]->colour,ticket[17]->amount);
	    break;
     case 4:
	    printf("player has hotel standing\n\n");
	    printf("You have to pay Rs.4000\n\n");
            p1->amount=p1->amount-4000;
            ticket[17]->amount=ticket[17]->amount+4000;
	    printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
	   printf("%s amount increased to %lu\n\n",ticket[17]->colour,ticket[17]->amount);
            break;
    }
  }
 x:
}


void water(struct player *p1)
{
 
 char ch;
 if(a[18]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[18]=p1;
     q[18]=ticket[18]->sno;
     a[18]++;
     ticket[18]->amount=ticket[18]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[18]==p1->sno)
  {
   printf("It is your ticket\n\n");
   printf("just rest\n\n");
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[18]->colour);
   printf("You have to pay Rs.1200\n\n");
   p1->amount=p1->amount-1200;
   ticket[18]->amount=ticket[18]->amount+1200;
   printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
   printf("%s amount increased to %lu\n\n",ticket[18]->colour,ticket[18]->amount);
  }
 x:
}



void rail(struct player *p1)
{

 char ch;
 if(a[19]==0)
  {
   
   printf("do you want to buy the Ticket\n\n");
   printf("You will have to pay Rs.1000\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     ticket[19]=p1;
     q[19]=ticket[19]->sno;
     a[19]++;
     ticket[19]->amount=ticket[19]->amount-1000;
     *bank=*bank+1000;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
    }
   goto x;
  }
 if(q[19]==p1->sno)
   {
   printf("It is your ticket\n\n");
   printf("just rest\n\n");
  }
 else
  {
   printf("Its %s's ticket..\n\n",ticket[19]->colour);
   printf("You have to pay Rs.1200\n\n");
   p1->amount=p1->amount-1200;
   ticket[19]->amount=ticket[19]->amount+1200;
   printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
   printf("%s amount increased to %lu\n\n",ticket[19]->colour,ticket[19]->amount);
  }
 x:
}






int house(int h,struct player *p1)
{
 char ch;
 if(h==0)
  {
   printf("You have no house standing\n\n");
   printf("Do you want first house\n\n ");
   printf("You will have to pay Rs.100\n\n");
   printf("Press Y for yes.......");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     h++;
     p1->amount=p1->amount-100;
     *bank=*bank+100;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
      printf("Bank's amount increased to Rs.%lu\n\n",*bank);
     return h;
    }
  }
 if(h==1)
  {
   printf("You have first house standing\n\n");
   printf("Do you want second house\n\n ");
   printf("You will have to pay Rs.200\n\n");
   printf("Press Y for yes.........");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     h++;
     p1->amount=p1->amount-200;
     *bank=*bank+200;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
     return h;
    }
  }
 if(h==2)
  {
   printf("You have second house standing\n\n");
   printf("Do you want third house\n\n ");
   printf("You will have to pay Rs.300\n\n");
   printf("Press Y for yes........");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     h++;
     *bank=*bank+300;
     p1->amount=p1->amount-300;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
     return h;
    }
  }
 if(h==3)
  {
   printf("You have third house standing\n\n");
   printf("Do you want hotel\n\n ");
   printf("You will have to pay Rs.500\n\n");
   printf("Press Y for yes........");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    {
     h++;
     *bank=*bank+500;
     p1->amount=p1->amount-500;
     printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
     printf("Bank's amount increased to Rs.%lu\n\n",*bank);
     return h;
    }
  }
 if(h==4)
  {
   printf("You have hotel standing\n\n");
   printf("Just Rest\n\n");
   return h;
  }
return h;
}




void display(struct player *p1)
{
 struct player *top;
 clrscr();
 top=p1;
 do
 {
  printf("DETAILS OF PLAYER NO. %d\n\n",p1->sno);
  printf("NAME OF THE PLAYER\n\n");
  puts(p1->colour);
  printf("\n\n");
  printf("AMOUNT THE PLAYER HAS %lu\n\n",p1->amount);
  p1=p1->next;
  getch();
  clrscr();
 }while(p1!=top);
}



void jail(struct player *p1)
{
int i=0;
printf("if u want to play press 1 and pay Rs.500 else skip 3 chances\n\n");
fflush(stdin);
scanf("%d",&i);
if(i==1)
 {
   p1->amount=p1->amount-500;
   *bank=*bank+500;
   printf("Your amount reduced to Rs.%lu\n\n",p1->amount);
   printf("Bank's amount increased to Rs.%lu\n\n",*bank);
 }
else
  {
   p1->jail=1;

}
}



void rest(struct player *p1,int n)
{
  ticket[20]=p1;
  printf("you have to take Rs.100 from every player\n");
  p1->amount=p1->amount+(n*100);
  do
   {
    p1=p1->next;
    p1->amount=p1->amount-100;
   }while(ticket[20]!=p1);
}


void club(struct player *p1,int n)
{
  ticket[21]=p1;
  printf("you have to give Rs.100 from every player\n");
  p1->amount=p1->amount-(n*100);
  do
   {
    p1->amount=p1->amount+100;
    p1=p1->next;
   }while(ticket[20]!=p1);
}























