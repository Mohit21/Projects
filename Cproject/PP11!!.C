#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>


void header();
void login();
//login
struct login
{
char inst[10];
char uid[12];
char bh[5];
char pass[20];
};

//-----------------------------------------------------------------------
//PERSONAL INFO
void display();
void personal();
//----------------------------------------------------------------
struct stu
{
	char name[20];
	char fname[20];
	char mname[20];
	char address[50];
	char course[5];
	char smail[40];
	char pmail[40];
	char dob[15];
	char mob[12];
	char enr[10];
	int sem;
};
struct stu s;
//----------------------------------------------------------------------
//ACADEMIC INFO

//---------------------------------------------------------------------------
//ATTENDANCE
struct attend
{
char sub[15];
float ptt,pt,pl,pp;
};

struct attend1
{
struct attend sub1;
struct attend1 *next;
}*temp;
typedef struct attend1 node;//name changed to node
node *start,*trav;
void displaya();
//----------------------------------------------------------------------------
//TIME TABLE
struct time_t
{
	char batch[5];
	char mths[10];
	char phys[10];
	char bedc[10];
	char ds[10];
	char gncp[10];
	char dslab[10];
	char physlab[10];
	char bedclab[10];
	char day[10];
};
struct time_t1
{
struct time_t tab;
struct time_t1 *next;
}*temp1;
typedef struct time_t1 node1;
node1 *start1,*trav1;
void displayt();
//----------------------------------------------------------------------------
void academic();
//----------------------------------------------------------------------------
//Xam Info
struct marks
{
	char sub3[20];
	float mr;
};

struct marks1
{
struct marks mar;
struct marks1 *next;
}*temp3;
typedef struct marks1 node3;
void exam();
void displaym();
node3 *start3,*trav3;
//-----------------------------------------------------------------------------
void header()
{
	int gd,gm,x=60,y=8,p=155,q=35;
	int left,top,bottom,right;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi" );
	left = getmaxy() / 1 - 500 ;
top = getmaxy() / 2 - 1000;
right = getmaxx() / 2 + 500;
bottom = getmaxy() / 2-180;
setfillstyle(1,6);
rectangle(top,left,right,bottom);
floodfill(getmaxx()/3,getmaxy()/100,15);
settextstyle(3,0,3);
outtextxy(x,y,"JAYPEE INSTITUTE OF INFORMATION TECHNOLOGY");
settextstyle(3,0,1);
outtextxy(p,q,"Deemed to be University under section 3 of UCG Act");
getch();
    // closegraph();
	      }

void main()
{
int i;			//,counter=0,flag=0;
char ch2,ch3;
//-----------------------------------------------------
login();
//clrscr();
header();
printf("\n\n\n\n\n\n\t\t1.PERSONAL INFO");
//delay(500);
printf("\n\n\t\t2.ACADEMIC INFO");
//delay(500);
printf("\n\n\t\t3.EXAM INFO");
//delay(500);
printf("\n\n\t\t4.SIGNOUT");
//delay(500);
printf("\nEnter Your Choice:");
do
{
fflush(stdin);
scanf("%c",&ch2);
 switch(ch2)
 {
 case '1':
	  personal();
	  break;

 case '2':academic();
	  break;

 case '3':exam();
	  break;

 case '4':printf("\nBREAKING!!");
	  exit(0);
	  break;
 default:printf("\n\tYou Entered Wrong Choice!!");
	printf("\nWant to Enter Again(Y/N):");
	scanf("%c",&ch3);
	if(ch3=='y'||ch3=='Y')
	{
	printf("\n\tAgain Enter Your Choice:");
	}
	break;
 }
 }
 while(ch3=='y'||ch3=='Y');

getch();
}
//---------------------------------------------------------------------
void main1()
{
char ch2,ch3;
//header();
printf("\n\n\n\n\n\n\t\t1.PERSONAL INFO");
//delay(500);
printf("\n\n\t\t2.ACADEMIC INFO");
//delay(500);
printf("\n\n\t\t3.EXAM INFO");
//delay(500);
printf("\n\n\t\t4.SIGNOUT");
//delay(500);
printf("\nEnter Your Choice:");
do
{
fflush(stdin);
scanf("%c",&ch2);
 switch(ch2)
 {
 case '1':
	  personal();
	  break;

 case '2':academic();
	  break;

 case '3':exam();
	  break;

 case '4':printf("\nBREAKING!!");
	  exit(0);
	  break;
 default:printf("\n\tYou Entered Wrong Choice!!");
	printf("\nWant to Enter Again(Y/N):");
	scanf("%c",&ch3);
	if(ch3=='y'||ch3=='Y')
	{
	printf("\n\tAgain Enter Your Choice:");
	}
	break;
 }
 }
 while(ch3=='y'||ch3=='Y');


}
//---------------------------------------------------------------------
void academic()
{
FILE *fp,*fp1;
int d=7,i,m;
int k=0,l=0;                    //k==0-> node //l==0->node1
char ch,ch1;
struct time_t  t;
struct attend at;
textcolor(BLACK);
//textbackground(GREEN);
clrscr();
//header();
fp=fopen("TimeTable.txt","r+");
fp1=fopen("Attend.txt","r+");
//delay(1000);
printf("\n\n\n\t\t1.TIME TABLE");
//delay(500);
printf("\n\n\n\t\t2.ATTENDENCE");
//delay(500);
printf("\n\n\n\t\t3.HOME");
//delay(500);
printf("\n\n\nEnter your choice to proceed(1-3):");
fflush(stdin);
scanf("%c",&ch);
//Palce here a line with help and further instructions!
switch(ch)
{
case '1':
	clrscr();
       //header();
	printf("\n\n\t\t1.ADD");                //change
	printf("\n\t\t2.VIEW");
	printf("\n\t\t3.BACK");                   //   change
	printf("\nEnter ur choice(1-3):");
	fflush(stdin);
	scanf("%c",&ch1);
	switch(ch1)
	{

case '1':clrscr();
		       //	 header();
			 fseek(fp,0,SEEK_END);  		//TO APPEND THE FILE
			 i=1;
			 printf("\n\tEnter the Batch:");
			 fflush(stdin);
			 gets(t.batch);
			while(d>1)                                 //for 6 days
			{
			printf("\n\t\tEnter day%d:\t",i);
			fflush(stdin);
			gets(t.day);
			printf("\nEnter subjects:");
			printf("\n\nSubject1:");
			fflush(stdin);
			gets(t.mths);
			printf("\nSubject2:");
			fflush(stdin);
			gets(t.phys);
			printf("\nSubject3:");
			fflush(stdin);
			gets(t.bedc);
			printf("\nSubject4:");
			fflush(stdin);
			gets(t.ds);
			printf("\nSubject5:");
			fflush(stdin);
			gets(t.gncp);
			printf("\nSubject6:");
			fflush(stdin);
			gets(t.dslab);
			printf("\nSubject7:");
			fflush(stdin);
			gets(t.physlab);
			printf("\nSubject8:");
			fflush(stdin);
			gets(t.bedclab);
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",t.day,t.mths,t.phys,t.bedc,t.ds,t.gncp,t.dslab,t.physlab,t.bedclab);
			d--;
			i++;
			}
			d=6;
			break;

		case '2':

			clrscr();
	     //		header();
			fseek(fp,0,SEEK_SET);
			  //rewind(fp);
		//	delay(1000);
			printf("\n\n\t\tThe time table is as follows....");
			delay(5000);
			printf("\n\n\t\t9-10\t10-11\t11-12\t12-13\t13-14\t14-15\t15-16\t16-17\n");
			for(m=0;m<8;m++)
		       {
			while(fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",t.day,t.mths,t.phys,t.bedc,t.ds,t.gncp,t.dslab,t.physlab,t.bedclab)!=EOF)
			{
			//	 printf("%s",t.batch);
			 temp1=(node1*)malloc(sizeof(node1));
			 temp1->tab=t;
			 temp1->next=NULL;
			 if(l==0)
			 {
			 start1=temp1;
			 trav1=temp1;
			 }
			 else
			 {
			  trav1->next=temp1;
			  trav1=trav1->next;
			 }
			l++;
			}

			}
			displayt();
			break;

		case '3':
			 clrscr();
			 academic();
			 break;
		default:printf("Wrong choice!!");
			break;
			}
	break;
case '2':
       clrscr();
       //	header();
	printf("\n\n\t\t1.ADD");                        // change
	printf("\n\t\t2.VIEW");                          //   change
	printf("\n\t\t3.BACK");
	printf("\nEnter ur choice(1-3):");
	fflush(stdin);
	scanf("%c",&ch1);
	switch(ch1)
	{
case '1':
	clrscr();
   //	header();
	fseek(fp1,0,SEEK_END);                    //TO APPEND THE FILE
	i=1;
	d=8;
	while(d>=1)                                 //for 6 days
	{
	printf("\n\t\tEnter subject%d:",i);
	fflush(stdin);
	gets(at.sub);
	if(strlen(at.sub)>7)
	{
	printf("\nEnter the Practical Lab Attendance:");
	fflush(stdin);
	scanf("%f",&at.pp);
	}
	else
	{

	printf("\nEnter the percentage attendance for Lecture:");
	fflush(stdin);
	scanf("%f",&at.pl);
	printf("\nEnter the percentage attendance for Tutorial:");
	fflush(stdin);
	scanf("%f",&at.pt);
	at.ptt=((at.pl*(75/100))+(at.pt*(25/100)));
	}
	fprintf(fp1,"%s\t\t%0.2f\t\t%0.2f\t\t%0.2f\t\t%0.2f\n",at.sub,at.ptt,at.pl,at.pl,at.pp);
	d--;
	i++;
	}

	break;
case '2':

	 clrscr();

      //	header();
	fseek(fp1,0,SEEK_SET);
	//rewind(fp1);
	delay(1000);
	printf("\n\n\t\tThe attendence is as follows.....");
	delay(3000);
	printf("\n\nSUBJECT    LECTURE+TUTORIAL\tLECTURE \tTUTORIAL \tPRACTICAL\n\n");
	while(fscanf(fp1,"%s%f%f%f%f",at.sub,&at.ptt,&at.pl,&at.pt,&at.pp)!=EOF)
	{

	 temp=(node*)malloc(sizeof(node));
	 temp->sub1=at;
	 temp->next=NULL;

	  if(k==0)
	  {
	  start=temp;
	  trav=temp;
	  }
	  else
	  {
	  trav->next=temp;
	  trav=trav->next;
	  }
	  k++;
	}
	displaya();

	break;
case '3':clrscr();
	 academic();
	 break;

default:printf("Wrong choice!!");
	break;
	}

	break;

case '3':clrscr();
	 main1();
	 break;
default:printf("\nWrong choice entered");
	break;

}                             //complete switch
fclose(fp);
fclose(fp1);

getch();
}


void login()
{
	struct login log;
	int gd,gm,x=60,y=8,p=155,q=35;
	int i,a=190,bo=50,d=90,c=75;
	int left, top, right, bottom;
       //	int points[]={620,150,620,400,20,400,320,150};
	int l,t,r,b;
       /*	int counter=0,flag=0;
	char uid[25],pwd[25],s_uid[][25]={"9913103538"};
       char s_pwd[][25]={"qwerty"},ch='a',bb[5],inst[5];
       //	int pa;
       //	char arr[20]={"abc"};
	int j=0;                                        */
	int j,counter=0,flag=0;
	char uid[25],pwd[25],abc[10],s_uid[][25]={"9913103563"},inst[5];
	char s_pwd[][25]={"qwerty"},ch='a',bb[5];

	char ch4;
	gd=DETECT;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	{
	delay(500);

	setcolor(YELLOW);
	settextstyle(1,HORIZ_DIR,4);
       outtextxy(a,bo,"JAYPEE INSTITUTE");
      settextstyle(1,HORIZ_DIR,4);
      outtextxy(c,d," OF INFORMATION TECHNOLOGY");
      settextstyle(8,0,3);
      outtextxy(200,130,"SECTOR-128,NOIDA");
      setcolor(CYAN);
       settextstyle(1,0,4);
      outtextxy(232,170,"INFO-KIOSK");


	for(i=0;i<=360;i++)
	{
		circle(300,330,8);
		if(i<=90)
		continue;
		else if(i>90&&i<=180)
		{
		setcolor(CYAN);

		}
		else if(i>180&&i<=270)
		{
		setcolor(YELLOW);

		}
		else
		{
		setcolor(RED);
		}
		pieslice(300,330,0,i,80);
		settextstyle(3,0,2);
		outtextxy(215,410,"Loading....please Wait");
		delay(10);
	}
	closegraph();
	}
	initgraph(&gd,&gm,"c:\\turboc3\\bgi" );
	left = getmaxy() / 1 - 500 ;
top = getmaxy() / 2 - 1000;
right = getmaxx() / 2 + 500;
bottom = getmaxy() / 2-180;
setfillstyle(1,6);
rectangle(top,left,right,bottom);
floodfill(getmaxx()/3,getmaxy()/100,15);
       settextstyle(3,0,3);
       outtextxy(x,y,"JAYPEE INSTITUTE OF INFORMATION TECHNOLOGY");
       settextstyle(3,0,1);
       outtextxy(p,q,"Deemed to be University under section 3 of UCG Act");
     //	int gd=DETECT,gm,
	delay(500);
	     //	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
l = getmaxy() / 1 - 350 ;
t = getmaxy() / 2 - 240;
r = getmaxx() / 2 + 340;
b = getmaxy() / 1-60;
setfillstyle(1,6);
rectangle(t,l,r,b);
floodfill(getmaxx()/2,getmaxy()/2,15);
setcolor(BLACK);
settextstyle(1,0,9);
outtextxy(15,140,"LOGIN");
settextstyle(1,0,9);
outtextxy(22,240,"PAGE");


//fseek(fl,0,SEEK_END);
gotoxy(45,13);
printf("Institue:");
fflush(stdin);
gets(inst);
gotoxy(45,15);
printf("User-Id:");
fflush(stdin);
gets(uid);
gotoxy(45,17);
printf("Batch:");
fflush(stdin);
gets(bb);
gotoxy(45,19);
printf("Password:");
fflush(stdin);
j=0;
while(1)
{
	ch=getch();
	if(ch==13)
	break;
	else if(ch==8)
	{       if(j!=0) /*this is for avoiding the ENTER instructions getting deleted */
		{
			printf("\b");  /*printing backspace to move cursor 1 pos back*/
			printf("%c",32);/*making the char invisible which is already on console*/
			printf("\b"); /*printing backspace to move cursor 1 pos back*/
			i--;
			pwd[j]='\0';
		}
		else
		continue;
	}
	else
	{
	putchar('*');/* char - '*' will be printed instead of the character */
	pwd[j]=ch;
	j++;
	}
}
pwd[j]='\0';
for(j=0;j<=2;j++)
{
	if((strcmp(pwd,s_pwd[j])==0) && (stricmp(uid,s_uid[j]))==0)
	{
		flag=1;
		break;
	}
}
if(flag)
{gotoxy(45,21);
printf(" USER AUTHENTICATED ");
}
else
{
gotoxy(45,21);
printf("DENIED");
getch();
exit(0);
}
	getch();
	closegraph();
}

//Exam--------------------------------------------------
void exam()
{
struct marks m;
int n=0,o=0;
FILE *fm;
char ch;
clrscr();
//cleardevice();
do
{
printf("\n\n\t\t1.Enter");
//delay(1000);
printf("\n\n\t\t2.View");
//delay(1000);
printf("\n\n\t\t3.BACK");
printf("\n\n\nEnter your choice to proceed(1-3):");
fflush(stdin);
scanf("%c",&ch);

switch(ch)
{
	case '1':
	{       fm=fopen("Marks1.txt","w");
	       clrscr();
	       //cleardevice();
		while(n!=8)
		{
		fseek(fm,0,SEEK_END);
		printf("Enter Subject %d:",n+1);
		fflush(stdin);
		gets(m.sub3);
		if(strlen(m.sub3)>7)
		{
		printf("Enter Lab Marks:");
		fflush(stdin);
		scanf("%f",&m.mr);
		}
		else
		{
		printf("Enter Marks:");
		fflush(stdin);
		scanf("%f",&m.mr);
		}
		fprintf(fm,"\n%s\t%f\n",m.sub3,m.mr);
		n++;
		}
	}
	 fclose(fm);

	break;
	case '2':
	{
	fm=fopen("Marks1.txt","r");
	clrscr();
      //	fseek(fm,0,SEEK_SET);
     // cleardevice();

			printf("\n\t\tMarks are as follows......\n");
			delay(1000);
			printf("\nSubjects\t\tMarks \t\t\tLab-Marks");
			 rewind(fm);
			while(fscanf(fm,"\n%s\t%f\n",m.sub3,&m.mr)!=EOF)
			{
				temp3=(node3*)malloc(sizeof(node3));
				temp3->mar=m;
				temp3->next=NULL;
				if(o==0)
				{
				start3=temp3;
				trav3=temp3;
				}
				else
				{
				trav3->next=temp3;
				trav3=trav3->next;
				}
				o++;

			}
			displaym();
	}
	fclose(fm);
	break;
	case '3':clrscr();
		main1();
	//exit(0);
	//fclose(fm);
	break;
	}
	getch();
	clrscr();
	}while(ch!=0);

}
//PERSONAL
void display()
{
	int gd = DETECT, gm=0;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	clrscr();
	line(125,25,125,450);
	line(525,25,125,25);
	line(525,450,525,25);
	line(525,63,125,63);
	line(125,450,525,450);
	line(300,25,300,450);
	line(525,101,125,101);
	line(525,139,125,139);
	line(525,177,125,177);
	line(525,223,125,223);
	line(525,261,125,261);
	line(525,299,125,299);
	line(525,337,125,337);
	line(525,337,125,337);
	line(525,375,125,375);
	line(525,413,125,413);
	line(525,451,125,451);

	gotoxy(25,3);
	printf("NAME");
	gotoxy(21,6);
	printf("FATHER'S NAME");
	gotoxy(21,8);
	printf("MOTHER'S NAME");
	gotoxy(20,10);
	printf("DATE OF BIRTH");
	gotoxy(24,13);
	printf("ADDRESS");
	gotoxy(21,16);
	printf("MOBILE NUMBER");
	gotoxy(21,18);
	printf("STUDENT'S EMAIL");
	gotoxy(21,20);
	printf("PARENT'S EMAIL");
	gotoxy(21,23);
	printf("ENROLLMENT NO.");
	gotoxy(21,25);
	printf("COURSE");
	gotoxy(21,26);
	printf("\n\n\n\t\t     SEMESTER");

	getch();
	closegraph();
}
void personal()
{
struct stu s;
char ch1,ch,add,name[20];
int p=1;
long int recsize;
FILE *fpp,*fpp1;
clrscr();
printf("\n\n\t\t1.Personal Info");
printf("\n\n\t\t2.List Records");
printf("\n\n\t\t3.Modify Records");
printf("\n\n\t\t4.Home");
printf("\n\n\t\tEnetr your Choice(1-4):");
fflush(stdin);
scanf("%c",&ch);
switch(ch)
{
case '1':			clrscr();
				fpp=fopen("Personal_Info.txt","w");
				fseek(fpp,0,SEEK_END);
					printf("\nEnter Name:");
					fflush(stdin);
					gets(s.name);
					printf("Enter Father's Name:");
					fflush(stdin);
					gets(s.fname);
					printf("Enter  Mother's Name:");
					fflush(stdin);
					gets(s.mname);
					printf("Enter Date Of Birth(dd/mm/yyyy):");
					fflush(stdin);
					gets(s.dob);
					printf("Enter Address:");
					fflush(stdin);
					gets(s.address);
					printf("Enter Mobile Number:");
					fflush(stdin);
					gets(s.mob);
					printf("Enter Student's Email:");
					fflush(stdin);
					gets(s.smail);
					printf("Enter Parent's Email:");
					fflush(stdin);
					gets(s.pmail);
					printf("Enter Enrollment Number:");
					fflush(stdin);
					gets(s.enr);
					printf("Enter Course:");
					fflush(stdin);
					gets(s.course);
					printf("Enter Semester:");
					fflush(stdin);
					scanf("%d",&s.sem);
					fprintf(fpp,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",s.name,s.fname,s.mname,s.dob,s.address,s.mob,s.smail,s.pmail,s.enr,s.course,s.sem);
				      //	fclose(fpp);
					printf("\nContinue Further(Y/N):");
 fflush(stdin);
 scanf("%c",&ch1);
 if(ch1=='y'||ch1=='Y')
 {
 clrscr();
 personal();

 }
 else
 {
 exit(0);
 }

					break;



case '2':
		 fpp1=fopen("Personal_Info.txt","r");

				clrscr();
				p=1;
			       rewind(fpp1);
			       fseek(fpp1,0,SEEK_SET);

				while(fscanf(fpp1,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",s.name,s.fname,s.mname,s.dob,s.address,s.mob,s.smail,s.pmail,s.enr,s.course,&s.sem)!=EOF)
				{
					if(p==1)
					{
			rewind(fpp1);
       //	gotoxy(25,3);
	printf("\n\n\tNAME:");
      //	gotoxy(21,6);
      printf("%s",s.name);
	printf("\n\tFATHER'S NAME:");
       printf("%s",s.fname);
//s.name,,s.,s.address,s.mob,s.smail,s.pmail,s.enr,s.course,s.sem
       //	gotoxy(21,8);
	printf("\n\tMOTHER'S NAME:");
	printf("%s",s.mname);
       //	gotoxy(20,10);
	printf("\n\tDATE OF BIRTH:");
	printf("%s",s.dob);
       //	gotoxy(24,13);
	printf("\n\tADDRESS:");
	printf("%s",s.address);
       //	gotoxy(21,16);
	printf("\n\tMOBILE NUMBER:");
	printf("%s",s.mob);
       //	gotoxy(21,18);
	printf("\n\tSTUDENT'S EMAIL:");
	printf("%s",s.smail);
      //	gotoxy(21,20);
	printf("\n\tPARENT'S EMAIL:");
	printf("%s",s.pmail);
       //	gotoxy(21,23);
      // enr,s.course,s.sem
	printf("\n\tENROLLMENT NO.:");
	printf("%s",s.enr);
      //	gotoxy(21,25);
	printf("\n\tCOURSE:");
       printf("%s",s.course);
      //	gotoxy(21,26);
	printf("\n\tSEMESTER:");
       printf("%s",s.sem);

				    //	printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",);
      getch();
      }
      else
     {
	break;
	}
	p++;
}

				  fclose(fpp);
				  fclose(fpp1);
				  printf("\nContinue Further(Y/N):");
 fflush(stdin);
 scanf("%c",&ch1);
 if(ch1=='y'||ch1=='Y')
 {
 clrscr();
 personal();

 }
 else
 {
 exit(0);
 }

				  break;

case '3' :
fpp=fopen("Personal_Info.txt","r");
fpp1=fopen("Personal_Info.txt","w");
	add='y';
				while(add=='y')
				{
					printf("Enter Name Of The Student:");
					fflush(stdin);
					gets(name);
					rewind(fpp);
					while(fscanf(fpp,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",s.name,s.fname,s.mname,s.dob,s.address,s.mob,s.smail,s.pmail,s.enr,s.course,&s.sem)!=EOF)
					{
						if(strcmp(s.name,name)==0)
						{
							printf("\nEnter New Name:");
							fflush(stdin);
							gets(s.name);
							printf("\nDate Of Birth:");
							fflush(stdin);
							gets(s.dob);
							printf("\nMobile Number:");
							fflush(stdin);
							printf("\nAddress:");
							fflush(stdin);
							gets(s.address);
							printf("\nEmail:");
							fflush(stdin);
							gets(s.smail);
							fseek(fpp,-recsize,SEEK_CUR);
							fprintf(fpp1,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",s.name,s.fname,s.mname,s.mob,s.address,s.mob,s.smail,s.pmail,s.enr,s.course,s.sem);
							break;
						}
					}
					printf("Do You Want to Modify Another:");
					fflush(stdin);
					scanf("\t%c",&add);
				}
				fclose(fpp);
				fclose(fpp1);
				printf("\nContinue Further(Y/N):");
 fflush(stdin);
 scanf("%c",&ch1);
 if(ch1=='y'||ch1=='Y')
 {
 clrscr();
 personal();

 }
 else
 {
 exit(0);
 }

				break;
				case '4':
				clrscr();
				main1();
				break;
				default:
				exit(0);
			}
		}




 void displaya()
 {
 char ch;
 node *temp11;
 temp11=start;

 while(temp11!=NULL)
 {
 if(strlen(temp11->sub1.sub)>7)
	 {
	 printf("%s \t\t\t\t\t\t\t%.2f",temp11->sub1.sub,temp11->sub1.pp);
	 printf("\n");
	 }
	 else
	 {
	 printf("%s\t\t%.2f\t\t%.2f\t\t%.2f",temp11->sub1.sub,temp11->sub1.ptt,temp11->sub1.pl,temp11->sub1.pt,temp11->sub1.pp);
	 printf("\n");
	 }
 temp11=temp11->next;
 }
 printf("\nContinue Further(Y/N):");
 fflush(stdin);
 scanf("%c",&ch);
 if(ch=='y'||ch=='Y')
 {
 clrscr();
 main1();

 }
 else
 {
 exit(0);
 }

 }

 void displayt()
 {
 char ch;
 node1 *temp2;
 temp2=start1;
 while(temp2!=NULL)
 {

			 if(strlen(temp2->tab.day)>7)
			 {
				 printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",temp2->tab.day,temp2->tab.mths,temp2->tab.phys,temp2->tab.bedc,temp2->tab.ds,temp2->tab.gncp,temp2->tab.dslab,temp2->tab.physlab,temp2->tab.bedclab);
			 }
			 else if(strlen(temp2->tab.day)>8)
			 {
				 printf("%s   %s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",temp2->tab.day,temp2->tab.mths,temp2->tab.phys,temp2->tab.bedc,temp2->tab.ds,temp2->tab.gncp,temp2->tab.dslab,temp2->tab.physlab,temp2->tab.bedclab);
			 }
			 else if(strlen(temp2->tab.day)==7)
			 {
			  printf("%s    \t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",temp2->tab.day,temp2->tab.mths,temp2->tab.phys,temp2->tab.bedc,temp2->tab.ds,temp2->tab.gncp,temp2->tab.dslab,temp2->tab.physlab,temp2->tab.bedclab);//t.day,t.mths,t.phys,t.bedc,t.ds,t.gncp,t.dslab,t.physlab,t.bedclab);
			 }
			 else
			 {
			   printf("%s\t\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",temp2->tab.day,temp2->tab.mths,temp2->tab.phys,temp2->tab.bedc,temp2->tab.ds,temp2->tab.gncp,temp2->tab.dslab,temp2->tab.physlab,temp2->tab.bedclab);//t.day,t.mths,t.phys,t.bedc,t.ds,t.gncp,t.dslab,t.physlab,t.bedclab);
			 }
//printf("\n");
temp2=temp2->next;

 }
 printf("\nContinue Further(Y/N):");
 fflush(stdin);
 scanf("%c",&ch);
 if(ch=='y'||ch=='Y')
 {
 clrscr();
 main1();

 }
 else
 {
 exit(0);
 }

}

void displaym()
{
char ch;
node3 *temp4;
temp4=start3;

while(temp4!=NULL)
{         if(strlen(temp4->mar.sub3)>7)
				{

					printf("\n%s\t\t\t\t\t%.1f",temp4->mar.sub3,temp4->mar.mr);
				}
				else
				{
				printf("\n%s\t\t\t%.1f",temp4->mar.sub3,temp4->mar.mr);
				}
    temp4=temp4->next;
}
printf("\nContinue Further(Y/N):");
 fflush(stdin);
 scanf("%c",&ch);
 if(ch=='y'||ch=='Y')
 {
 clrscr();
 main1();

 }
 else
 {
 exit(0);
 }
}