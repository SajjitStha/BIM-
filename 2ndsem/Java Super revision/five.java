import java.util.*;
public class five {
    public static void main(String[] args)
    {
        Scanner st = new Scanner(System.in);
        double p,t,r,a,ci;
        p = st.nextDouble();
        t = st.nextDouble();
        r = st.nextDouble();
        a =p*((100+r)/100);
        ci=(Math.pow(a,t))-1; 
        System.out.println("CI:"+ci);
    }
}
