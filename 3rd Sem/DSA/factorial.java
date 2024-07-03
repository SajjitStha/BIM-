public class factorial {
    static int fact(int a) {
        if (a <= 1)
            return 1;
        else
            return (a * fact(a - 1));
    }

    public static void main(String[] args) {
        int a = 4;
        int fact = fact(a);
        System.out.println("The factorial of " + a + " = " + fact);
    }
}