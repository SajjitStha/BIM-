import java.util.*;
class bird{
    void eat(){
        System.out.println("Bird eats something");
    }
}
class parrot extends bird{
    void eat(){
        System.out.println("Parrot eats chilly");
    }
}
class vulture extends bird{
    void eat()
    {
        System.out.println("Vulture eats flesh");
    }
}
class dynamicmethod{

    public static void main(String[] args)
    {
        bird b1 = new parrot();
        bird b2 = new vulture();
        System.out.println("Choose:\n[1]Parrot\n[2]Vulture");
        Scanner st = new Scanner(System.in);
        int n = st.nextInt();
        if(n==1)
        {
            b1.eat();
        }
        else if(n==2)
        {
            b2.eat();
        }
    }
}
