class base
{
    
    void baba()
    {
        System.out.println("This is feature of parent");
        

    }
    

}
class child extends base{
    void baba1(String name)
    {
        
        System.out.print(name);
    }
    

}
public class SimpleInheritance {
    public static void main(String args[])
    {
        child n =new child();
        n.baba();
        n.baba1("Sajjit");
    }
}
