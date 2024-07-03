#include<stdio.h>
void main()
{
	int a,b,temp,i,res[4],comp[4],flag = 0;
	printf("A\tB\tA->B\t(A'+B)\n");
	for(i=0;i<4;i++)
	{
		a=i%2;
		b=i/2;
		if(a==1 && b==0)
		
			res[i] = 0;
		
		else
		
			res[i] = 1;	
		
		comp[i] = (!a)||b;
		if(comp[i] == res[i])
		{
			flag++;
			
		}
		printf("%d\t%d\t%d\t%d\t%d\n",a,b,res[i],comp[i]);
	}
	if(flag == 4)
	{
		printf("\nThey are equivalent");
		
	}
}
