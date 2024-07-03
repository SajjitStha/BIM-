import java.util.*;
class main
{
   
    public static void main(String[] args)
    {
        Scanner fac = new Scanner(System.in);
        Factorial st = new Factorial();
        int x = fac.nextInt();
        int a = st.FindFact(x);
        System.out.println(a);
    }
}