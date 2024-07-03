#include<stdio.h>
void main()
{
	int a,b,c,i,temp;
	printf("A\tB\tC\tA+B+C\tA.B.C\t!(A.B.C)\n");
	for(i=0;i<8;i++)
	{
		a=i%2;
		temp = i;
		temp=temp/2;
		b=temp%2;
		c=i/4;
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",a,b,c,a||b||c,a&&b&&c,!(a&&b&&c));
		
	}
}
