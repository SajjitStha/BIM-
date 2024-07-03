#include <stdio.h>
#include <string.h>

void generate_combinations(char *sequence, int start, int end, char *result, int index, int k) {
    if (index == k) {
        result[index] = '\0';
        printf("%s\n", result);
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= k - index; i++) {
        result[index] = sequence[i];
        generate_combinations(sequence, i + 1, end, result, index + 1, k);
    }
}

int main() {
    char sequence[100], result[100];
    int k;

    printf("Enter a string: ");
    scanf("%s", sequence);

    printf("Enter the length of combinations (k): ");
    scanf("%d", &k);

    int n = strlen(sequence);

    generate_combinations(sequence, 0, n - 1, result, 0, k);

    return 0;
}
