#include<stdio.h>

int BinSearch(int se[], int min, int max, int search){
    if(min <= max){
        int mid = min + ((max-min)/2);
        if(se[mid] == search){
            return mid;
        }
        else if(se[mid] < search){
            return (BinSearch(se, (mid+1), max, search));
        }
        else{
            return (BinSearch(se, min, (mid-1), search));
        }
    }
    return -1;
}

void main(){
    int search;
    int arr[8] = {11, 15, 32, 48, 99, 102, 222, 423};
    printf("\nEnter the element to be searched: ");
    scanf("%d", &search);
    int value = BinSearch(arr, 0, 7, search);
    if(value == -1){
        printf("\nValue not found in array");
    }
    else{
        printf("\nValue found at position %d", value);
    }
}
