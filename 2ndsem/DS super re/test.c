#include<stdio.h>
extend(int a,int b,int*x,int*y,int*gcd)
{
	if(b==0)
	{
		*gcd = a;
		*x = 1;
		*y = 0;
	}
	else
	{
		extend(b,a%b,y,x,gcd);
		*y-=a/b**x;
	}
}
void main()
{
	int a,b,x,y,gcd;
	scanf("%d %d",&a,&b);
	extend(a,b,&x,&y,&gcd);
	printf("GCd:%d\n",gcd);
	printf("%dX%d+%dx%d",a,x,b,y);
}


