import java.util.*;
public class six {
    public static void main(String[] args)
    {
        Scanner st = new Scanner(System.in);
        System.out.print("Name:");
        String n = st.nextLine();
        System.out.print("Gender:");
        String str = st.next();
        char g = str.charAt(0);
        System.out.print("DOB:");
        int d = st.nextInt();

        System.out.println("Name:"+n);
        System.out.println("Gender:"+g);
        System.out.println("DOB:"+d);
    }
}
