#include<stdio.h>
#include<stdlib.h>
int i,n;
struct node
{
	int data;
	struct node*link;
};
struct node* f= NULL, *r = NULL,*cur;
void enqueue()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to insert\n");
	scanf("%d",&(cur->data));
	cur->link = NULL;
	if(f==NULL)
		f = r = cur;
	else
	{
		r->link = cur;
		r=cur;
	}
}
void dequeue()
{
	if(f == NULL)
		printf("Queue underflow\n");
	else if(f == r)
	{
		printf("Deleted element is %d\n",f->data);
		f=r=NULL;
	}
	else
	{
		cur = f;
		f = f->link;
		printf("deleted element is %d\n",cur->data);
		free(cur);
	}
}
void display()
{
	if(f == NULL)
		printf("Queue is empty\n");
	else
	{
		cur = f;
		while(cur != NULL)
		{
			printf("%d->",cur->data);
			cur = cur->link;
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
	 	printf("\n1-enqueue\n2-dequeue\n3-dispaly\n4-exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	enqueue();
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: exit(0);
				break;
		}
	}
}	