import java.util.*;
public class eight {
    public static void main(String[] args)
    {
        Scanner st = new Scanner(System.in);
        System.out.println("Enter values of a and b:");
        int a = st.nextInt();
        int b = st.nextInt();
        if(a>b)
        {
            System.out.println("A is greatest i.e"+a);
        }
        else{
            System.out.println("B is greatest i.e"+b);
        }
    }
    
}
