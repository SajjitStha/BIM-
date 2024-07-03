import java.util.*;
class rectangle{
    double l,b,a;
    void set()
    {
        Scanner st = new Scanner(System.in);
        System.out.println("L and B:");
        l =st.nextDouble();
        b =st.nextDouble();

    }
    void calculate()
    {
        a = l*b;
        System.out.println("Area:"+a);

    }
}

class twentyfive{
    public static void main(String[] args)
    {
        rectangle r1 = new rectangle();
        r1.set();
        r1.calculate();
    }
}