import java.util.*;
interface calculate{
    public int add(int x,int y);
    public int diff(int x, int y);
}

class test implements calculate{
   public int add(int x,int y)
   {
    int sum = x+y;
    return sum;

   }
   public int diff(int x,int y)
   {
    int diffe = x-y;
    return diffe;

   }
}
public class threefour {
    public static void main(String[] args)
    {
        test i = new test();
        System.out.println(i.add(10,5));
        System.out.println(i.diff(10,5));
    }
    
}
