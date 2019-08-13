#include<stdio.h>
#include<conio.h>
# define MAX_SIZE 10
int top=-1;
int i;
int stack[MAX_SIZE];
void push(int x)
{
if( top==MAX_SIZE-1)
printf("Error: Stack is full\n");
else
{
top=top+1;
stack[top]=x;
}
}
void pop()
{
if(top==-1)
printf("Error: Stack is empty\n");
else
{
top=top-1;
}
}
void print()
{
if (top==-1)
{
printf("Error:Stack is empty\n");
}
else
{
printf("Stack\n");
for (i=0; i<=top;i++)
{
printf("%d ", stack[i]);
}
}
}
void main()
{
int choice,num;
clrscr();
do
{
printf("ENTER THE CHOICE");
printf("\nPush:1\n Pop:2\n Print:3\n Exit:4\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("Enter number to be pushed:\n");
	scanf("%d",&num);
	push(num);
	break;
case 2: pop();
	break;
case 3: print();
	break;
case 4: exit(0);
	break;
default: printf("Choice is invalid\n");
}
}while(choice!=4);
getch();
}

