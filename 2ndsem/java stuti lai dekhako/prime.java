import java.util.*;
class prime{
    public static void main(String[] args) {
        int lower,upper;
        Scanner st = new Scanner(System.in);
        System.out.println("Enter value of minimum no:");
        lower = st.nextInt();
        System.out.println("Enter value of maximum no:");
        upper = st.nextInt();
        int s,i,count =0;
        System.out.println("Prime number within the range are:");
        for(s = lower;s<upper;s++)
        {
            count = 0;
            for(i = 1;i<=s;i++){
                if(s%i==0)
                {
                    count++;
                }
            }
            if(count==2)
            {
                System.out .println(s);
            }
            
        }    
    }
}