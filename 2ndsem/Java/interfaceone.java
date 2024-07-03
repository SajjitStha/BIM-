interface one{
    public void show();
    public void display();
}

class test implements one{
        public void show()
        {
            System.out.println("Show function");
        }
        public void display()
        {
            System.out.println("Display function");
        }

    
}

class interfaceone
{
    public static void main(String[] args)
    {
        test t1 = new test();
        t1.show();
        t1.display();
    }
}
