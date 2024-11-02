namespace LeetCodeProblems.Problems;

public class LeetCode28FindTheIndexOfTheFirstOccurrenceInAString
{
    public int StrStr(string haystack, string needle) {
        int  needleLength = needle.Length;
        bool areSame = true;
        for (int i = 0; i <= haystack.Length-needleLength; i++)
        {
            if(haystack[i] != needle[0])
                continue;
            if(haystack[i+needleLength-1] != needle[^1])
                continue;
            areSame = true;
            for (int j = 1; j < needleLength - 1; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    areSame = false;
                    break;
                }
                
            }

            if (areSame)
                return i;
        }

        return -1;
    }
}