import java.util.*;
public class eleven{
    public static void main(String[] args){
        Scanner st = new Scanner(System.in);
        int a = st.nextInt();
        int b = st.nextInt();
        String str = st.next();
        char c = str.charAt(0);
        switch(c)
        {
            case '+':
            int add =a+b;
            System.out.println(add);
            break;
            case '-':
            int sub =a-b;
            System.out.println(sub);
            break;
            case '*':
            int mul =a*b;
            System.out.println(mul);
            break;
            case '/':
            int div =a/b;
            System.out.println(div);
            break;

        }
    }

}