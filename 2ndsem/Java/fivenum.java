import java.util.*;
import java.lang.Math;
class compund
{
    Scanner st = new Scanner(System.in);
    
    double comp()
    {
        double p,t,r,ci=0;
        p = st.nextDouble();
        t = st.nextDouble();
        r = st.nextDouble();
        double a = ((100+r)/100);
        ci = p*Math.pow(a,t)-1;
        return ci;
    }
}
public class fivenum {
    public static void main(String[] args)
    {
        compund t =new compund();
        double d = t.comp();
        System.out.println("Compund Interest = "+d);
    }
}
