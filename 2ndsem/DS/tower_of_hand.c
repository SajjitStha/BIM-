#include <stdio.h>
void tower_of_hanoi(int n, char from_peg, char to_peg, char aux_peg) {
if (n == 1) {
printf("Move disc 1 from peg %c to peg %c\n", from_peg, to_peg);
return;
}
tower_of_hanoi(n - 1, from_peg, aux_peg, to_peg);
printf("Move disc %d from peg %c to peg %c\n", n, from_peg, to_peg);
tower_of_hanoi(n - 1, aux_peg, to_peg, from_peg);
}
int main(void) {
int n;
printf("Enter the number of discs: ");
scanf("%d", &n);
tower_of_hanoi(n, 'A', 'C', 'B');
return 0;
 }
