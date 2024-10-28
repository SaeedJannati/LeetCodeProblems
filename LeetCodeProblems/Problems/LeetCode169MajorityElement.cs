namespace LeetCodeProblems.Problems;

public class LeetCode169MajorityElement: BaseProblemClass
{
    public int MajorityElement(int[] nums)
    {
        if(nums.Length == 1)
            return nums[0];
        int length=nums.Length;
        Dictionary<int,int> numCountDict=new(length);
        for (int i = 0,e=length; i < e; i++)
        {
            if (!numCountDict.ContainsKey(nums[i]))
            {
                numCountDict[nums[i]] = 1;
                continue;
            }
            numCountDict[nums[i]]++;
            if (numCountDict[nums[i]] > length / 2)
                return nums[i];
        }

        return 0;
    }

    public override void Run()
    {
        int[] input = [3,2,3];
        Console.WriteLine(MajorityElement(input));
    }
}