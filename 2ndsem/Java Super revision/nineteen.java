public class nineteen 
{
    public static void main(String[] args)
    {
        int[] a ={44,45,34,23,12,1};
        int i,j,temp,flag = 0;
        for(i=0;i<6;i++)
        {
            for(j=i+1;j<6;j++)
            {
                if(a[i]>a[j])
                {
                    temp =a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
        
            }

        

        }
        for(i=0;i<6;i++)
        {
            System.out.println(a[i]);
        

        }
    }
}