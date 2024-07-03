#include<stdio.h>
int fibo(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return ( fibo(n-1) + fibo(n-2));
    }

}

void main(){
    int num, count = 0;
    printf("\nEnter last number: ");
    scanf("%d", &num);

    while(fibo(count) <= num){
        printf("%d\t", fibo(count));
        count++;
    }
}

