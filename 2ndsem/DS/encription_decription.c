#include<stdio.h>
#include<ctype.h>

void main(){
    char c;
    int key;
    printf("\nEnter a character: ");
    scanf("%c", &c);
    printf("Enter the key: ");
    scanf("%d", &key);
    char c1 = toupper(c);
    int C = c1 - 65;	
    
    int cipher = (C + key) % 26;
    int c11 = cipher + 65;
    printf("Enc = %c", c11);

    int org = (cipher - key) % 26;
    org = org + 65;
    printf("\nDec = %c", org);
}
