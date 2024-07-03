public class constructoroverloading 
{
       public static void main(String args[])
       {
        Area a1 = new Area(15); 
        Area a2 = new Area(4,5); 
        Area a3 = new Area(13); 
       }
       

}

class Area
{
    Area(double r)
    {
        double a=r*r*3.14;
        System.out.println("Area of Circle:"+a);

    }

    Area(int l,int b)
    {
        double a= l*b;
        System.out.println("Area of Rectangle:"+a);
    }

    Area(int l)
    {
        double a= l*l;
        System.out.println("Area of Square:"+a);
    }
}
