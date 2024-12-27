namespace LeetCodeProblems.Problems;

public class LeetCode1004MaxConsecutiveOnesIII : BaseProblemClass
{
    public int LongestOnes(int[] nums, int k)
    {
        int firstPointer = 0;
        int secondPointer = 0;
        int maxLength = 0;
        int currentLength = 0;
        int zeroCount = 0;
        var length = nums.Length;
        if(k>=length)
            return length;
        while (secondPointer < length)
        {
            if (nums[secondPointer] == 0)
                zeroCount++;
            if (zeroCount > k)
            {
                if (secondPointer > 0)
                {
                    secondPointer--;
                    zeroCount = k;
                }
                else
                    zeroCount = 1;
                break;
            }

            secondPointer++;
        }
        if (secondPointer >= length - 1)
            return length;
        if (zeroCount <= k)
        {
            currentLength =secondPointer - firstPointer+1 ;
            if (currentLength > maxLength)
                maxLength = currentLength;
        }

       
        if (secondPointer == firstPointer)
        {
            secondPointer++;
            if (secondPointer == length - 1)
                return maxLength;
            if (nums[secondPointer] == 0)
                zeroCount++;
        }

        while (secondPointer < length - 1)
        {
            firstPointer++;
            secondPointer++;
            if (nums[firstPointer - 1] == 0)
                zeroCount--;
            if (nums[secondPointer] == 0)
                zeroCount++;
            if (zeroCount <= k)
            {
                while (secondPointer < length - 1)
                {
                    secondPointer++;
                    if (nums[secondPointer] == 0)
                        zeroCount++;
                    if (zeroCount > k)
                    {
                        secondPointer--;
                        zeroCount = k;
                        break;
                    }
                }

                currentLength = secondPointer > firstPointer ? secondPointer - firstPointer + 1 : 0;

                if (currentLength > maxLength)
                    maxLength = currentLength;
            }

            
        }

        return maxLength;
    }

    public override void Run()
    {
        int[] input = [1,0,0,0];
        int k = 2;
        Console.WriteLine(LongestOnes(input, k));
    }
}