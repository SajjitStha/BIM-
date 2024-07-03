import java.util.*;
class add{
    int tt()
    {
        int a,b,sum=0;
    Scanner st = new Scanner(System.in);
    a = st.nextInt();
    b = st.nextInt();
    sum = a+b;
    return sum;
    }
    

}
public class threenum {
    public static void main(String[] args)
    {
        add t = new add();
        int a =t.tt();
        System.out.println("Sum = "+a);
    }
}
