import java.util.*;
public class array {
    public static void main(String[] args)
    {
        int[] a = new int[30];
        Scanner st =new Scanner(System.in);
       for(int i=0;i<30;i++)
        {
            a[i] = st.nextInt();
            
        }
       for(int i=0;i<30;i++)
       {
        if(a[i]>16 && a[i]<47)
        {
            System.out.println("Value ="+a[i]);
        }
       }
    }
    

}

