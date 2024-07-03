#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	int num,maxsize,i,a;
	printf("\nHow many random numbers:");
	scanf("%d",&num);
	printf("\nEnter the max digit of random numbers:");
	scanf("%d",&maxsize);
	maxsize= pow(10,maxsize);
	int random;
	printf("\nRandom Numbers:\n");
	for(i=1;i<=num;i++)
	{
		random = rand()%maxsize;
		printf("%d\n",random);
	}
}
