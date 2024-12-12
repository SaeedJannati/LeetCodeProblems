namespace LeetCodeProblems.Problems;

public class LeetCode1071GreatestCommonDivisorofStrings: BaseProblemClass
{
    public string GcdOfStrings(string str1, string str2)
    {
        int maxPossibleLength = 0;
        int firstLength = str1.Length;
        int secondLength = str2.Length;
        int min=Math.Min(firstLength, secondLength);
        for (int i = min; i >= 1; i--)
        {
            if (firstLength % i != 0 || secondLength % i != 0) 
                continue;
            maxPossibleLength = i;
            break;
        }

        for (int i = maxPossibleLength; i >= 1; i--)
        {
            if (firstLength % i != 0 || secondLength % i != 0) 
                continue;
            if(str1[..i] != str2[..i])
                continue;
            bool isIt = true;
            for (int j = 0, e = firstLength / i-1; j < e; j++)
            {
                if(str1[..i]!=str1.Substring(i*(1+j),i))
                    isIt = false;
            }
            if(!isIt)
                continue;
            for (int j = 0, e = secondLength / i-1; j < e; j++)
            {
                if(str2[..i]!=str2.Substring(i*(1+j),i))
                    isIt = false;
            }
            if(isIt)
                return str1[..i];
        }

        return "";
    }

    public override void Run()
    {
        string firstStr ="ABCABC";
        string secondStr = "ABC";
        Console.WriteLine(GcdOfStrings(firstStr, secondStr));
    }
}