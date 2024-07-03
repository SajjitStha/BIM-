interface one  {
    public void show();
    interface two{
        public void display();         
    }
    
}

class test implements one.two{
      
        public void display()
        {
            System.out.println("Display function");
        }

    
}

public class nestedinterface {
    public static void main(String[] args)
    {
        test t1 = new test();
        t1.display();

    }
    
}
