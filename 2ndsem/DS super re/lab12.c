#include<stdio.h>
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}
void main()
{
	int a,b;
	printf("Enter values of A and B:");
	scanf("%d %d",&a,&b);
	printf("GCD:%d",gcd(a,b));
}
