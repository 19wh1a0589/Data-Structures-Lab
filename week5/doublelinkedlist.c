#include<stdio.h>
#include<stdlib.h>
struct node
{
	float data;
	struct node*prev;
	struct node*next;
};
struct node *head = NULL,*tail = NULL,*cur,*next,*prev,*t1,*t2;
void create()
{
	int n;
	printf("ENTER THE NUMBER OF NODES\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cur = (struct node*)malloc(sizeof(struct node));
		printf("ENTER CURRENT NODE DATA\n");
		scanf("%f",&(cur->data));
		cur->prev = NULL;
		cur->next = NULL;
		if(head == NULL)
		{
			head = tail = cur;
		}
		else
		{
			tail->next = cur;
			cur->prev = tail;
			tail = cur;
		}
	}
}
void insert_at_begin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("ENTER CURRENT NODE DATA\n");
	scanf("%f",&(cur->data));
	cur->prev = NULL;
	cur->next = head;
	head->prev = cur;
	head=cur;
}
void insert_at_end()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("ENTER CURRENT NODE DATA\n");
	scanf("%f",&(cur->data));
	cur->next = NULL;
	cur->prev= tail;
	tail->next = cur;
	tail=cur;
}
void insert_at_pos()
{
	int c=1,pos;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER CURRENT NODE DATA\n");
	scanf("%f",&(cur->data));
	printf("enter position");
	scanf("%d",&pos);
	t1=head;
	while(c<pos && t1 != NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}
void insert_before_node()
{
	float value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("ENTER CURRENT NODE DATA\n");
	scanf("%f",&(cur->data));
	printf("Enter the data before which node we need to insert\n");
	scanf("%f",&value);
	t1=head;
	while(t1 != NULL && t1->data != value)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}
void insert_after_node()
{
	float value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("ENTER CURRENT NODE DATA\n");
	scanf("%f",&(cur->data));
	printf("enter the data after which node we need to insert");
	scanf("%f",&value);
	t1=head;
	while(t1 != NULL && t1->data!=value)
	{
		t1=t1->next;
	}
	cur->next=t1->next;
	t1->next->prev=cur;
	t1->next=cur;
	cur->prev=t1;
	
}
void delete_at_begin()
{
	cur=head;
	head=head->next;
	head->prev=NULL;
	cur->next=NULL;
	printf("Deleted element %f",cur->data);
	free(cur);
}
void delete_at_end()
{
	cur=tail;
	tail=tail->prev;
	tail->next=NULL;
	cur->prev=NULL;
	printf("Deleted element %f",cur->data);
	free(cur);
}
void delete_at_pos()
{
	int c=1,pos;
	printf("enter the position of deletion");
	scanf("%d",&pos);
	t1=head;
	while(c<pos && t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("deletion data is %f",t1->data);
	free(t1);
}
void delete_before_node()
{
	float value;
	printf("enter the data  of a node to perform delete before");
	scanf("%f",&value);
	t1=head;
	while(t1->data!=value && t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("delete a element %f",t2->data);
	free(t2);
}	
void delete_after_node()
{
	float value;
	printf("enter the data  of a node to perfom delete after");
	scanf("%f",&value);
	t1=head;
	while(t1->data != value && t1 != NULL)
	{
		t1=t1->next;
	}
	t2=t1->next;
	t1->next=t2->next;
	t2->next->prev=t1;
	printf("delete a element %f\n",t2->data);
	free(t2);
}	
void display_forward()
{
	if(head == NULL)
		printf("DLL is empty");
	else
	{
		cur = head;
		printf("elements of DLL are\n");
		while(cur!=NULL)
		{
			printf("%f<->",cur->data);
			cur=cur->next;
		}
	}
}
void display_reverse()
{
	
	if(head == NULL)
		printf("DLL is empty");
	else
	{
		cur = tail;
		printf("elements of the DLL are\n");	
		while(cur!=NULL)
		{
			printf("%f<->",cur->data);
			cur=cur->prev;
		}
	}
}
void searching()
{
	float value;
	int flag=0,c=1;
	printf("enter the value to be searched\n");
	scanf("%f",&value);
	t1 = head;
	while(t1->next != NULL)
	{
		if(t1->data == value)
		{
			flag == 1;
			printf("element is found at %d\n",c);
			break;
		}
		t1=t1->next;
		c++;
	}
	if(flag==0)
	{
		printf("element not found\n");
	}
}

void sorting()
{
	struct node *p1,*p2,*last=NULL;int t;
	int c;
	do	
	{
		c=0;
		p1=head;
		while(p1->next != last)
		{
			if(p1->data > p1->next->data)
			{
				t=p1->data;
				p1->data = p1->next->data;
				p1->next->data = t;
				c=1;
			}
			p1= p1->next;
		}
		last = p1;
	}
	while(c);
}
int main()
{
	int ch;
	while(1)
	{
		printf("program for double linked list\n");
		printf("1-create\n2-insert at begin\n3-insert at position\n4-insert at end\n5-insert before\n");
		printf("6-insert after\n7-delete at begin\n8-delete at end\n9-delete at pos\n10-delete before\n");
		printf("11-delete after\n12-display\n13-display in reverse\n14-search\n15-sort\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert_at_begin();
				break;
			case 3: insert_at_pos();
				break;
			case 4: insert_at_end();
				break;
			case 5: insert_before_node();
				break;
			case 6: insert_after_node();
				break;
			case 7: delete_at_begin();
				break;
			case 8: delete_at_end();
				break;
			case 9: delete_at_pos();
				break;
			case 10: delete_before_node();
				 break;
			case 11: delete_after_node();
				 break;
			case 12: display_forward();
				 break;
			case 13: display_reverse();
				 break;
			case 14: searching();
				 break;
			case 15: sorting();
				 break;
			case 16: exit(0);
		}
	}
	return 0;
}

	
	
		