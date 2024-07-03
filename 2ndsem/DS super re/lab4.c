#include<stdio.h>
int gcd(a,b)
{
	while(b!=0)
	{
		int r = a%b;
		a=b;
		b=r;
	}
	return a;
}

void main()
{
	int x,y;
	printf("Enter X:");
	scanf("%d",&x);
	printf("Enter Y:");
	scanf("%d",&y);
	int c = gcd(x,y);
	printf("GCD = %d",c);
	
	
}
