#include <stdio.h>
int gcd(int a, int b) {
if (b == 0) {
return a;
}
return gcd(b, a % b);
}
int main(void) {
int a, b;
printf("Enter two integers: ");
scanf("%d %d", &a, &b);
printf("The greatest common divisor of %d and %d is %d.\n", a, b, gcd(a, b));
return 0;
}
