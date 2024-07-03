class seventeen
{
    public static void main(String args[])
    {
        int n;
        int i;
        int count=0;
        for(n=20;n<100;n++)
        {
            count = 0;
            for(i=1;i<n;i++){
                if(n%i==0)
                {
                    count++;
                }
            }
            if(count == 2)
            {
                System.out.println(n +" is prime number");
            } 
           
        }

        
        
    }
}