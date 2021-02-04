#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*head=NULL,*cur, *temp,*t1,*t2;
void create()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter cur data");
	scanf("%d",&cur->data);
	cur->link=cur;
	if(head==NULL)
		head=cur;
	else
	{
		temp=head;
		while(temp->link!=head)
			temp=temp->link;
		temp->link=cur;
		cur->link=head;
	}
}

void insert_at_begin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter cur data");
	scanf("%d",&cur->data);
	temp=head;
	while(temp->link!=head)
		temp=temp->link;
	temp->link=cur;
	cur->link=head;
	head=cur; //not required for insert at end 
}
void insert_at_pos()
{
	int c=1,pos;
	printf("enter position of insertion");
	scanf("%d",&pos);
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter cur data");
	scanf("%d",&cur->data);
	t1=head;
	while(c<pos)
	{
		t2=t1;
		t1=t1->link;
		c++;
	}
	t2->link=cur;
	cur->link=t1;
}
void delete_at_begin()
{
	cur=temp=head;
	while(temp->link!=head)
		temp=temp->link;
	temp->link=cur->link;
	head=cur->link;
	cur->link=NULL;
	printf("deleted element %d",cur->data);
	free(cur);
}
void delete_at_end()
{
	t1=head;
	while(t1->link!=head)
	{
		t2=t1;
		t1=t1->link;
	}
		t2->link=head;
		t1->link=NULL;
		printf("deleted element %d",t1->data);
		free(t1);
}
void delete_at_pos()
{
	int c=1,pos;
	printf("enter position of deletion");
	scanf("%d",&pos);
	t1=head;
	while(c<pos)
	{
		t2=t1;
		t1=t1->link;
		c++;
	}
	t2->link=t1->link;
	t1->link=NULL;
	printf("deleted element %d",t1->data);
	free(t1);
}
void display()
{
	if(head==NULL)
	printf("CLL is empty");
	else
	{
		temp=head;
		while(temp->link!=head)
		{
			printf("%d->",temp->data);
			temp=temp->link;
		}
			printf("%d",temp->data);
	}
}	
int main()
{
	int ch;
	while(1)
	{
	printf("1-create\n2-insert at begin\n3-insert at pos\n4-delete at begin\n5-delete at end\n6-delete at pos\n7-traversal\n8-exit\n");
	printf("enter yr choice");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: create();
		break;
	case 2: insert_at_begin();
		break;
	case 3: insert_at_pos();
		break;
	case 4: delete_at_begin();
		break;
	case 5: delete_at_end();
		break;
	case 6: delete_at_pos();
		break;
	case 7:display();
		break;
	case 8: exit(0);
	}
	}
}
