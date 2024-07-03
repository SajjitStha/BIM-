import java.util.*;
class student{
    int age;
    String name;
    void input()
    {
        Scanner st = new Scanner(System.in);
        name = st.nextLine();
        age = st.nextInt();
       

    }

}
public class threeeone {
    public static void main(String[] args)
    {
        student[] stu = new student[5];
        int i;
        for(i=0;i<5;i++)
        {
            stu[i] =new student();
            stu[i].input();
           
        } 
        for(i=0;i<5;i++)
        {
            if(stu[i].age>=24)
            {
                System.out.println(stu[i].name);
            }
           
        } 


    }
    
}
