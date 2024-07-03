#include<stdio.h>
void main()
{
	int i,a,b,temp;
	printf("A\tB\tA+B\tA.B\t!(A.B)\n");
	for(i=0;i<4;i++)
	{
		a=i%2;
		b=i%2;
		printf("%d\t%d\t%d\t%d\t%d\n",a,b,a||b,a&&b,!(a&&b));
	}
}


