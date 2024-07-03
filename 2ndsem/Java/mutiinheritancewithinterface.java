interface one
{
    public void show();
}
interface two{
    public void display();
}
class test implements one,two{
    public void show()
    {
        System.out.println("Show Function");
    }
    public void display()
    {
        System.out.println("Display Function");
    }
}
public class mutiinheritancewithinterface {
    public static void main(String[] args)
    {
        test t1 = new test();
        t1.show();
        t1.display();
    }
    
}
