#include<stdio.h>
int linear_search(int a[50],int n,int key)
{
	static int i=0;
	if(a[i]==key)
	{
	return i;
	}
	else if(i<n)
	 {
		i++;
		linear_search(a,n,key);
	 }
	else
		return -1;
	
	
}
int main()
{
	int i,pos,n,key,a[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&key);
	pos=linear_search(a,n,key);
	if(pos==-1)
		printf("element not present\n");
	else
		printf("element present at %d\n",pos+1);
}