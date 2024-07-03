#include<stdio.h>
#include<stdlib.h>
int Add(int a, int b){
    while(b!=0){
        int c  = (a & b) << 1; //CARRY
        a = (a ^ b);
        b = c;
    }
    return a; 
}

int Subtraction(int a, int b){
    b = ~b + 1;
    return Add(a, b);
}

int Multiply(int a, int b){
	int i;
    int sum = a;
    for(i = 0; i<(b-1); i++){
        sum = Add(sum, a);
    }
    return sum;
}

int Division(int a, int b){
    if(b == 0){
        printf("\nDivision Error!!!");
        exit (1);
    }
    else{
        int count = 0, rem = a;
        while(rem >= b){
            rem = Subtraction(rem, b);
            count++; 
        }
        return count;
    }
}
void main(){
    int a, b;
    printf("\nEnter any two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Sum = %d", Add(a, b));
    printf("\nMul = %d", Multiply(a, b));
    printf("\nSubtraction = %d", Subtraction(a, b));
    printf("\nQuotient = %d", Division(a, b));
}  
