#include <stdio.h>
void extended_euclidean(int a, int b, int *x, int *y, int *gcd) {
if (b == 0) {
*gcd = a;
*x = 1;
*y = 0;
} else {
extended_euclidean(b, a % b, y, x, gcd);
*y -= a / b * *x;
}
}
int main(void) {
int a, b, x, y, gcd;
printf("Enter two integers: ");
scanf("%d %d", &a, &b);
extended_euclidean(a, b, &x, &y, &gcd);
printf("The extended Euclidean algorithm results:\n");
printf("gcd(%d, %d) = %d = %d * %d + %d * %d\n", a, b, gcd, a, x, b, y);
return 0;
}
