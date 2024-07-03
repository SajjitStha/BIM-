import java.util.Scanner;

public class TowerOfHanoi{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the  number of disk");
        int n = sc.nextInt();
        TOH(n, 'S', 'D', 'T');

    }

    static void TOH(int n, char A, char B, char C) {

        if (n == 1) {
            System.out.println("From " + A + " to " + B);
        } else {
            TOH(n - 1, A, C, B);
            TOH(1, A, B, C);
            TOH(n - 1, C, B, A);
        }
    }
}