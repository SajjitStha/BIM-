import java.util.*;
public class four {
    public static void main(String[] args)
    {
        Scanner st = new Scanner(System.in);
        double p,t,r,si = 0;
        p = st.nextDouble();
        t = st.nextDouble();
        r = st.nextDouble();
        si = (p*t*r)/100;
        System.out.println("SI is "+si+"%");

    }
}
