import java.io.*;
import java.util.*;
class create{
public static void main(String[] args)
{
File f = new File("C:\\Users\\Ripple\\Documents\\2ndsem\\Java\\filetest.txt");
try
{
if(f.createNewFile())
{
System.out.println("File Created...");
}
else
{
System.out.println("Already exsists...");
Scanner st =new Scanner(System.in);
System.out.println("Enter your Choice:\n\n[1].Write\n\n[2].File Info\n\n[3].Copy");
int n = st.nextInt();
switch(n)
{
case 1:
FileWriter fw = new FileWriter("C:\\Users\\Ripple\\Documents\\2ndsem\\Java\\filetest.txt");
try
{
fw.write("This place is noice but not noice enough to die in....!!!");
}
finally
{
fw.close();
}
System.out.println("Successfully written...!!");
break;

case 2:
if(f.exists())
{
System.out.println("File Name:"+f.getName());
System.out.println("File Location:"+f.getAbsolutePath());
System.out.println("File Writable:"+f.canWrite());
System.out.println("File Readble:"+f.canRead());
System.out.println("Size:"+f.length());

}
else
{
System.out.println("File doesnot exists");
}
break;
default:
System.out.println("Invalid choice:");
break;
}
}
}
catch(IOException i)
{
System.out.println(i);
}





}

}
