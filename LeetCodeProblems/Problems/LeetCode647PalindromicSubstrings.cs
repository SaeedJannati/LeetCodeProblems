namespace LeetCodeProblems.Problems;

public class LeetCode647PalindromicSubstrings: BaseProblemClass
{
    #region O(n) memory

    public int CountSubstrings(string s)
    {
        var length = s.Length;
        if (length == 0)
            return 0;
        if (length == 1)
            return 1;
        bool[][] dp = new bool[2][];

        for (int i = 0; i < 2; i++)
        {
            dp[i] = new bool[length];
        }
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            dp[0][i] = true;
            count++;
            if (i >= length - 1) 
                continue;
            if (s[i] != s[i + 1]) 
                continue;
            dp[1][i] = true;
            count++;
        }

        for (int j = 2; j < length; j++)
        {
            for (int i = 0; i < length; i++)
            {
                if(i+j>length-1)
                    break;
                if (!dp[0][i + 1])
                {
                    dp[0][i] = false;
                    continue;
                }
              
                if (s[j + i] != s[i])
                {
                    dp[0][i] = false;
                    continue;
                }
                dp[0][i] =true;
                count++;
            }

            (dp[0], dp[1]) = (dp[1], dp[0]);
        }
        return count;
    }

    #endregion
    #region O(n^2) memory

    // public int CountSubstrings(string s)
    // {
    //     var length = s.Length;
    //     if (length == 0)
    //         return 0;
    //     if (length == 1)
    //         return 1;
    //     var dp=new bool[length, length];
    //     int count = 0;
    //     for (int i = 0; i < length; i++)
    //     {
    //         dp[i, i] = true;
    //         count++;
    //         if (i >= length - 1) 
    //             continue;
    //         if (s[i] != s[i + 1]) 
    //             continue;
    //         dp[i, i + 1] = true;
    //         count++;
    //     }
    //
    //     for (int j = 2; j < length; j++)
    //     {
    //         for (int i = 0; i < length; i++)
    //         {
    //             if(i+j>length-1)
    //                 break;
    //             if(!dp[i+1,j+i-1])
    //                 continue;
    //             if(s[j+i] != s[i])
    //                 continue;
    //             dp[i, j+i] =true;
    //             count++;
    //         }
    //     }
    //     return count;
    // }

    #endregion
 

    public override void Run()
    {
        var input = "xkjkqlajprjwefilxgpdpebieswu";
        Console.WriteLine(CountSubstrings(input));
    }
}