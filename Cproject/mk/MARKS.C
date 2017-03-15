#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
struct marks
{
	char sub3[20];
	float mr;
};

void main()
{
struct marks m;
int n=0;
FILE *fm;
char ch;
clrscr();
do
{
printf("\n\n\t\t1.Enter");
//delay(1000);
printf("\n\n\t\t2.View");
//delay(1000);
printf("\n\n\t\t3.EXIT");
printf("\n\n\nEnter your choice to proceed(1-3):");
fflush(stdin);
scanf("%c",&ch);

switch(ch)
{
	case '1':
	{       fm=fopen("Marks1.txt","w");
		clrscr();
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

			printf("\n\t\tMarks are as follows......\n");
			delay(1000);
			printf("\nSubjects\t\tMarks \t\t\tLab-Marks");
			 rewind(fm);
			while(fscanf(fm,"\n%s\t%f\n",m.sub3,&m.mr)!=EOF)
			{
				if(strlen(m.sub3)>7)
				{

					printf("\n%s\t\t\t\t\t%.1f",m.sub3,m.mr);
				}
				else
				{
				printf("\n%s\t\t\t%.1f",m.sub3,m.mr);
				}
			}
	}
	fclose(fm);
	break;
	case '3':
	exit(0);
	fclose(fm);
	break;
	}
	getch();
	clrscr();
	}while(ch!=0);
	getch();
}
