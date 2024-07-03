class Simple{
    Simple()
    {
        this(5);
        System.out.println("This is Default Constructor");
    }
    Simple(int a)
    {
        System.out.println("This is Parameterized Constructor");
    }
}

public class thisconstructor {
    public static void main(String args[])
    {
        Simple s1 =  new Simple();
    }
}
