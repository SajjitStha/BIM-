import java.util.*;
class Student {
    private String name;
    private double percentage;
    void set(String name,double percentage)
    {
        this.name = name;
        this.percentage = percentage;
       

    }
    void display()
    {
        System.out.println(name);
        System.out.println(percentage);        
    }
    
    public String getName()
    {
        return name;
    }

    public double getPercentage()
    {
        return percentage;
        
    }


}
class test{
    
        public static void main(String[] args) {
            Student[] students = new Student[10];
    
            // Set the values for the 10 students
            students[0] = new Student();
            students[0].setName("Alice");
            students[0].setPercentage(80.5);
    
            students[1] = new Student();
            students[1].setName("Bob");
            students[1].setPercentage(75.0);
    
            students[2] = new Student();
            students[2].setName("Charlie");
            students[2].setPercentage(90.0);
    
            students[3] = new Student();
            students[3].setName("David");
            students[3].setPercentage(70.0);
    
            students[4] = new Student();
            students[4].setName("Emma");
            students[4].setPercentage(85.0);
    
            students[5] = new Student();
            students[5].setName("Frank");
            students[5].setPercentage(95.0);
    
            students[6] = new Student();
            students[6].setName("Grace");
            students[6].setPercentage(77.5);
    
            students[7] = new Student();
            students[7].setName("Harry");
            students[7].setPercentage(82.0);
    
            students[8] = new Student();
            students[8].setName("Isabel");
            students[8].setPercentage(89.5);
    
            students[9] = new Student();
            students[9].setName("Jack");
            students[9].setPercentage(78.0);
    
            // Find the student(s) with the highest percentage
            int i;
            for(i=0;i<10;i++)
            {
                if(students[i].)

            }
    }

        

    }
}