interface Shape{
    void area();
    void perimeter();
}
class Circle implements Shape
{
    double pi = 3.14;
    double r = 14.80;
    public void area()
    {
        double a = pi*r*r;
        System.out.println(a);
    }
    public void perimeter()
    {
        double p = 2*pi*r;
        System.out.println(p);
    }

}
class Rectangle implements Shape{
    double l = 5.6;
    double b = 2.3;
    public void area(){
        double a = l*b;
        System.out.println(a);
    }
    public void perimeter()
    {
        double p = 2*(l+b);
        System.out.println(p);
    }

    }



public class testedbaba{
    public static void main(String[] args)
    {
         Circle c = new Circle();
         Rectangle r = new Rectangle();
         c.area();
         c.perimeter(); 
         r.area();
         r.perimeter();  
    }
    
}
