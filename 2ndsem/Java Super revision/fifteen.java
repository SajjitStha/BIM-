public class fifteen {
    public static void main(String[] args)
    {
        int i,j;
        for(i=1;i<=10;i++)
        {
            for(j=1;j<=10;j++)
            {
                if(i==7 || j==7)
                {
                    continue;
                }
                System.out.println(i+"x"+j+"="+i*j);
            }
        }
    }
    
}
