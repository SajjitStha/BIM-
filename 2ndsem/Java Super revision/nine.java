import java.util.*;
public class nine {
    public static void main(String[] args)
    {
        Scanner st =new Scanner(System.in);
        System.out.println("Enter values for a b and c:");
        int a = st.nextInt();
        int b = st.nextInt();
        int c = st.nextInt();
        if(a<b&&a<c)
        {
            System.out.println("A is lowest");
        }
        else if(b<c&&b<a)
        {
            System.out.println("B is lowest");
        }
        else
        {
            System.out.println("C is lowest");
        }

    }
}
