#include<stdio.h>
void insertion_sort(int a[100],int n)
{
	int i,j,index;
	for(i=1;i<n;i++)
	{
		index =a[i];
		j=i;
		while((j>0) && (a[j-1]  > index))
		{
			a[j] = a[j-1];
			j=j-1;
		}
		a[j] = index;
	}
}
int main()
{
	int n,a[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertion_sort(a,n);
	printf("elements after sorting\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}