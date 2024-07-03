class gcd {
    static int gcdImplement(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcdImplement(b, a % b);
    }

    public static void main(String[] args) {
        int a = 12;
        int b = 24;

        int gcd = gcdImplement(a, b);
        System.out.println("The GCD of " + a + " & " + b + " = " + gcd);
    }
}