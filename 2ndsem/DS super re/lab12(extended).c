#include <stdio.h>
void Extend(int a, int b, int *x, int *y, int *gcd) {
    if (b == 0) {
        *gcd = a;
        *x = 1;
        *y = 0;
    } 
    else {
        Extend(b, a % b, y, x, gcd);
        *y -= a / b * *x;
    }
}

void main() {
    int a, b, x, y, gcd;
    printf("\nEnter two integers: ");
    scanf("%d %d", &a, &b);

    Extend(a, b, &x, &y, &gcd);

    printf("gcd(%d, %d) = %d\n\n%d * %d + %d * %d\n", a, b, gcd, a, x, b, y);
}
