import java.util.*;

class Student
{

    String name;
    String gender;
    String DOB;
}
class detail
{
    Scanner st= new Scanner(System.in);
    Student details()
    {

        Student s  =new Student();
        s.name = st.nextLine();
        
        s.gender = st.nextLine();
        System.out.println();
        s.DOB = st.nextLine();
        return(s);

    }

}
public class sixnum {
    public static void main(String[] args)
    {
        detail d = new detail();
        String b = d.details();
        System.out.println(b);
    }
}
