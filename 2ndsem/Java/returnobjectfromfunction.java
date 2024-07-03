class Student
{
    int roll;
    String name;

}

class Operation
{
    Student getStudent()
    { 
        Student s1 = new Student();
        s1.roll = 5;
        s1.name = "Sajjit";
        return s1;
    }
}

public class returnobjectfromfunction {
    public static void main(String args[])
    {
        Operation obj = new Operation();
        Student res = obj.getStudent();
        System.out.println("Your roll is "+res.roll);
        System.out.println("Your name is "+res.name);

    }
}
