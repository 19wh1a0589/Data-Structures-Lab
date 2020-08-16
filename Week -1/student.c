#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct student
{
	int roll;
	char name[30];
	int m[3];
};
int main()
{
	struct student s[20];
	int n,i,j;
	float sum,avg;
	char grade;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		sum = 0;
		scanf("%d",&s[i].roll);
		scanf("%s",&s[i].name);
		for(j=0;j<3;j++)
		{
			scanf("%d",&s[i].m[j]);
			sum += s[i].m[j];
		}
		avg = sum/3.0;
		if(avg>=75)
			grade = 'A';
		else if(avg>=50)
			grade = 'B';
		else
			grade = 'C';
		printf("%d %s %f %c\n",s[i].roll,s[i].name,avg,grade);
	}
} 