using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode90SubsetsII: BaseProblemClass
{
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        IList <IList<int>> result=[];
        Array.Sort(nums);
        result.Add([]);
        int length = nums.Length;
        List<int> current=[];
        BackTrack(result, nums, current, -1, length);
        return result;
    }
    void BackTrack(IList <IList<int>> result, int[] nums, List<int> current, int index, int numLength)
    {
        if (index == numLength)
            return;
        int lastNumber = -11;
        for (int i = index + 1; i < numLength; i++)
        {
            if (nums[i]==lastNumber)
                continue;
            lastNumber=nums[i];
            current.Add(nums[i]);
            result.Add([..current]);
            BackTrack(result, nums, current, i, numLength);
            current.RemoveAt(current.Count-1);
        }
    }
    public override void Run()
    {
        int[] nums=[4,4,4,1,4];
        var result = SubsetsWithDup(nums);
        HashSet<IList<int>> resultSet = [..result];
        result=resultSet.ToList();
        Console.WriteLine(JsonSerializer.Serialize(result));
    }
}