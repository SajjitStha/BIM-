import java.util.*;
public class Time
{
    int hr;
    int min;
    int sec;
    Time Sum(Time t1,Time t2)
    {
        Time + Sum = new Time();
        t.sum.sec = t1.sec + t2.sec;
        if(tsum.sec>60)
        {
            tsum.mint = 1;
            tsum.sec - 60 - tsum.sec;
        } 
        
    }
}
public class TimeDemo {
    public static void main(String args[])
    {
        Time x = new Time();
        x.hr = 5;
        x.min = 40;
        x.sec = 40;
        Time y = new Time();
        y.hr = 4;
        y.min = 40;
        y.sec = 50;
        Time t = new Time();
        
        int a = t.Sum(5,4);
        System.out.println(a);

    }
}
