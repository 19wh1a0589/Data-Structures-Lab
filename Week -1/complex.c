#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct complex
{
	int real;
	int imag;
}c1,c2,c3;
struct complex addition(struct complex s1,struct complex s2)
{
	struct complex s3;
	s3.real = s1.real + s2.real;
	s3.imag = s1.imag + s2.imag;
	return s3;
}
struct complex subtraction(struct complex s1,struct complex s2)
{
	struct  complex s3;
	s3.real = s1.real - s2.real;
	s3.imag = s1.imag - s2.imag;
	return s3;
}
struct complex multiplication(struct complex s1,struct complex s2)
{
	struct complex s3;
	s3.real = (s1.real*s2.real) - (s1.imag*s2.imag);
	s3.imag = (s1.real*s2.imag) + (s2.real*s1.imag);
	return s3;
}
int main()
{
	scanf("%d%d%d%d",&c1.real,&c1.imag,&c2.real,&c2.imag);
	c3 = addition(c1,c2);
	printf("addition = %d + i%d\n",c3.real,c3.imag);
	c3 = subtraction(c1,c2);
	printf("subtraction = %d + i%d\n",c3.real,c3.imag);
	c3 = multiplication(c1,c2);
	printf("multiplication = %d + i%d\n",c3.real,c3.imag);
	return 0;
}