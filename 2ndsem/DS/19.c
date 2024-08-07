#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int start, int end) {
	int i;
    if (start == end) {
        printf("%s\n", str);
    } else {
        for ( i = start; i <= end; i++) {
            swap((str + start), (str + i));
            permute(str, start+1, end);
            swap((str + start), (str + i));
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int n = strlen(str);
    printf("Permutations:\n");
    permute(str, 0, n-1);
    return 0;
}
