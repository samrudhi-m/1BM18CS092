/*STUDENT INFORMATION ENTERING THE AUDITORIUM*/
#include<stdio.h>
#include<conio.h>
#define capacity 50
int top=-1;
struct student{    //to store student information
char name[50];
char id[20];
char email[100];
}info[capacity];
void push ()    //to enter student information
{
if(top == capacity-1)
{
printf("Auditorium is full\n");
 }
 else
 {
 top=top+1;
 printf("Enter name:\n");
 scanf("%s", &info[top].name);
 printf("Enter student ID:\n");
 scanf("%s", &info[top].id);
 printf("Enter email address:\n");
 scanf("%s",&info[top].email);
 }
 }
 void pop() //to exit students
 {
 if(top == -1)
 {
 printf("Auditorium is empty\n");
 }
 else
 {
 printf("The student: %s \n ID: %s has exited\n",info[top].name, info[top].id);
 top=top-1;
 }
 }
 void print() //to display students info
 {
 if(top==-1)
{
printf(" Auditorium is empty\n");
}
else
{int i;
printf("DISPLAY OF STUDENT INFORMATION BASED ON LAST IN FIRST OUT ORDER\n");
for(i=top; i>=0; i--);
{
printf("STUDENT NAME: %s \n", info[i].name);
printf("STUDENT ID: %s \n", info[i].id);
printf("EMAIL ADDRESS: %s \n", info[i].email);
}
}
}
void main()
{ int choice;
do
{
printf("ENTER \n 1:ENTRY OR STUDENT \n 2: EXIT OF STUDENT \n 3:DISPLAY OF STUDENT INFORMATION \n 4: EXIT\n");
scanf("%d", &choice);
switch(choice)
{
case 1:push();
	break;
case 2: pop();
	break;
case 3: print();
	break;
case 4: exit(0);
	break;
default: printf("INVALID CHOICE\n");
}
}while(choice!=4);
getch();
}