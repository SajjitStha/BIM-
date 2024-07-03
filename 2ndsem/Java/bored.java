import java.util.*;
class welcome
{
    void wel()
    {
        System.out.println("Welcome to Xten.com");
    }
   
}
class bug{
    void bg()
    {
        System.out.println("Incorrect email or password!! Try again?? "); 
        System.out.println("[1].Yes"); 
        System.out.println("[2].No"); 
        Scanner t = new Scanner(System.in);
        int b = t.nextInt();
        switch(b)
        {
            case 1:
            login log = new login();
            log.login_info();
            break;

            case 2:
            System.out.println("Lazy ass !!");
            break;

            default:
            System.out.println("Invalid choice!!");
            break;

        }
    }
}
class login{
    void login_info()
    {
        Scanner st = new Scanner(System.in);
        System.out.print("Email:");
        String a = st.next();
        System.out.print("Password:");
        String b = st.nextLine();
        if(a=="sajjit"&& b=="sajit12123")
        {
            welcome w = new welcome();
            w.wel();
            
        }
        else{
            bug bt = new bug();
            bt.bg();
        }
    }
}
public class bored {
    public static void main(String[] args)
    {
        login  l = new login();
        l.login_info();
        
    }
    
}
