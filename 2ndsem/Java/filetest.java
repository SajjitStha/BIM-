import java.util.*;
import java.io.*;
public class filetest {
    public static void main(String[] args)throws IOException
    {

        File f = new File("C:\\Users\\Ripple\\Documents\\2ndsem\\Java\\filetest1.txt");
       
                System.out.println("Successfully done..!!");

            
        
    
        FileInputStream r = new FileInputStream("C:\\Users\\Ripple\\Documents\\2ndsem\\Java\\filetest.txt");
        FileOutputStream o = new FileOutputStream("C:\\Users\\Ripple\\Documents\\2ndsem\\Java\\filetest1.txt");
        
            
            int i;
            while((i=r.read())!=-1)
            {
                o.write((char)i);
                System.out.println((char)i);
            }
        



    
}
}
