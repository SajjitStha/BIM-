import java.util.*;
class simp
{
    Scanner st = new Scanner(System.in);
    double simple()
    {
        double p,t,r,si=0;
        p = st.nextDouble();
        t = st.nextDouble();
        r = st.nextDouble();
        si = p*t*r/100;
        return si;

    }
   

}
public class fournum {
    public static void main(String[] args)
    {
        simp t = new simp();
        double sii = t.simple();
        System.out.println("Simple Interest = "+sii+"%");
    }
}
