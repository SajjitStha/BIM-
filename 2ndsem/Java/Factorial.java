class Factorial
{
    int result=1;
    int FindFact(int n)
    {
        for(int i=1;i<=n;i++)
        {
            result = result*i;
        }
        return result;
    }
}