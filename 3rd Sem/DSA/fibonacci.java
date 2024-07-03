import java.util.Scanner;

public class fibonacci{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i;
        System.out.println("enter the number for fibonanci till nth term ");
        int a = sc.nextInt();
        for (i = 1; i <= a; i++) {

            System.out.print(fib(i)+"\t");
        }
        
    }

    static int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return fib(n - 1) + fib(n - 2);
        }
    }
}