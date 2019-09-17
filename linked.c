#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE p;
	p=(NODE)malloc (sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf(" No memory allocation\n");
		exit(0);
	}
}
NODE insert_front(NODE head, int item)
{
	NODE p;
	p=getnode();
	p-> data=item;
	p-> next=head;
	head=p;
	return head;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("List is empty\n");
		
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n", p-> data);
		p=p->next;
	}
}
NODE insert_end(NODE head, int item)
{
	NODE p,q;
	q=getnode();
	q-> data=item;
	q-> next =NULL;
	if (head==NULL)
	{
		return q;
	}
	p=head;
	while(p-> next!=NULL)
	p=p->next;
	p-> next=q;
	return head;
}
NODE insert_pos(NODE head,int item,int pos)
{
	NODE curr,prev=NULL,newn;
	int count=1;
	newn=getnode();
	newn->data=item;
	newn->next=NULL;
	if(head==NULL)
	{
		if(pos==1)
			return newn;
		else
		{
			printf("Invalid position\n");
			return 0;
		}
	}
	if(pos==1)
	{
		newn->next=head;
		head=newn;
		return head;
	}
	else
	{
		curr=head;
		while(curr!=NULL&&count!=pos)
		{
			prev=curr;
			curr=curr->next;
			count++;
		}
		if(count==pos)
		{
			prev->next=newn;
			newn->next=curr;
			return head;
		}
		else
		{
			printf("Invalid position\n");
			return head;
		}
	}
}
int main()
{
	NODE head=NULL;
	int option,ele, value;
	do
	{
		printf(" \n1.Insert front\n 2.Insert end\n 3.Display\n 4.Exit\n\n");
		printf("Enter option\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1: printf("Enter the element to be inserted\n");
				scanf("%d", &ele);
				head= insert_front(head, ele);
				break;
			case 2: printf("Enter the element to be inserted\n");
				scanf("%d", &ele);
				head= insert_end(head, ele);
				break; 
			case 3: printf("Elements in the list are\n");
				display(head);
				break;
			case 4: exit(0);
			default: printf("INVALID CHOICE");
		}
	}while(1);
	return 0;
}


		
