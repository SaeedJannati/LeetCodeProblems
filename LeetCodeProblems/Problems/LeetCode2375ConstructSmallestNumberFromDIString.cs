namespace LeetCodeProblems.Problems;

public class LeetCode2375ConstructSmallestNumberFromDIString : BaseProblemClass
{
    public string SmallestNumber(string pattern)
    {
        int maxNum = pattern.Length + 1;
        int[] resultNum = new int[maxNum];
        bool[] visited = new bool[maxNum + 1];
        for (int i = 1; i <= maxNum; i++)
        {
            resultNum[0] = i;
            if (BackTrack(pattern, resultNum, visited, maxNum, 1, i))
                break;
        }

        return string.Join("", resultNum);
    }

    bool BackTrack(string pattern, int[] nums, bool[] visited, int maxNum, int index, int lastNum)
    {
        if (index == maxNum)
            return true;
        visited[lastNum] = true;
        for (int i = 1; i <= maxNum; i++)
        {
            if (visited[i])
                continue;
            if (pattern[index - 1] == 'I')
            {
                if (nums[index - 1] >= i)
                    continue;
            }
            else
            {
                if (nums[index - 1] <= i)
                    continue;
            }

            nums[index] = i;
            if (BackTrack(pattern, nums, visited, maxNum, index + 1, i))
                return true;
        }

        visited[lastNum] = false;
        return false;
    }

    public override void Run()
    {
        string pattern = 
            // "DDD";
        "IIIDIDDD";
        Console.WriteLine(SmallestNumber(pattern));
    }
}