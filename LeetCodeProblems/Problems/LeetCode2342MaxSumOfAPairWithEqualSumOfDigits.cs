namespace LeetCodeProblems.Problems;

public class LeetCode2342MaxSumOfAPairWithEqualSumOfDigits
{
    public int MaximumSum(int[] nums)
    {
        Dictionary<int, PriorityQueue<int, int>> map = [];
        int length = nums.Length;
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum=GetDigitsSum(nums[i]);
            if(!map.ContainsKey(sum))
                map[sum] = new PriorityQueue<int, int>();
            map[sum].Enqueue(nums[i],nums[i]);
        }

        int maxSum = 0;
        int currentSum = 0;
        foreach (var pair in map)
        {
            if(pair.Value.Count < 2)
                continue;
            currentSum=pair.Value.Dequeue()+pair.Value.Dequeue();
            if(currentSum>maxSum)
                maxSum = currentSum;
        }
        return maxSum>0?maxSum:-1;
    }

    int GetDigitsSum(int num)
    {
        int result = 0;
        while (num>0)
        {
            result += num % 10;
            num /= 10;
        }
        return result;
    }
}