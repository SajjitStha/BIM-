#include<stdio.h>

void main(){

    char ch;
    int key;

    printf("Enter a character: ");
    scanf("%c", &ch);
    printf("Enter the key: ");
    scanf("%d", &key);

    int enc = (ch + key) % 128; //128 is the number of ascii characters
    char dec = ((enc - key) + 128) % 128;

    printf("enc: %c\ndec: %c", (char)enc, dec);

}

