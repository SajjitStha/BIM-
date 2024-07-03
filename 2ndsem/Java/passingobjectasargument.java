class Student{
    int roll;
    String name;
}

class Operation{
    void display(Student s)
    {
        System.out.println("Your Roll is "+s.roll);
        System.out.println("Your Name is "+s.name);
    }
}

public class passingobjectasargument {
    public static void main(String args[])
    {
       Student s1 = new Student();
       s1.roll = 5;
       s1.name = "Sajjit Shrestha";
       Operation obj = new Operation();
       obj.display(s1);
    }
   
}
