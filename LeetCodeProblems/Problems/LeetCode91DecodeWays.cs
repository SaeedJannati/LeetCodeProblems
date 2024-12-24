namespace LeetCodeProblems.Problems;

public class LeetCode91DecodeWays: BaseProblemClass
{
    // public int NumDecodings(string s)
    // {
    //     int length = s.Length;
    //
    //     if (length <= 2)
    //     {
    //         var i = int.Parse(s);
    //         return i switch
    //         {
    //             0 => 0,
    //             <= 9 or 10 or 20 => 1,
    //             < 27 => 2,
    //             _ => 1
    //         };
    //     }
    //     else
    //     {
    //         return NumDecodings(s.Substring(0, length - 1)) + NumDecodings(s.Substring(length - 1)) +
    //                NumDecodings(s.Substring(0, 1)) + NumDecodings(s.Substring(1, length - 1));
    //     }
    // }
    public int NumDecodings(string s) {
        int length=s.Length;
        if (length == 0)
            return 0;
        if (s[0] == '0')
            return 0;
        if (length == 1)
            return 1;
        int[]dp=new int[length+1];
        dp[0]=1;
        dp[1] = 1;
        for (int i = 2,e=length+1; i < e ; i++)
        {
            if (s[i-1] =='0' )
            {
                if (s[i - 2] is '1' or '2')
                {
                    dp[i] = dp[i - 2];
                    continue;
                }
    
                return 0;
            }
            if (   s[i - 2] == '1')
            {
                dp[i]=dp[i-2]+dp[i-1];
                continue;
            }
            if (s[i-1] < '7' &&   s[i - 2] == '2')
            {
                dp[i]=dp[i-2]+dp[i-1];
                continue;
            }
    
            dp[i] = dp[i - 1];
    
        }
    
        return dp[^1];
    }

    public override void Run()
    {
        var input = "2101";
        Console.WriteLine(NumDecodings(input));
    }
}