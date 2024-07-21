namespace LeetCodeProblems.Problems;

public class LeetCode4MedianOfTwoSortedArrays : BaseProblemClass
{
    public override void Run()
    {
        int[] firstArray = {1, 3};
        int[] secondArray = {2};
       var median= FindMedianSortedArrays(firstArray, secondArray);
        Console.WriteLine(median);
    }

    public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    {
        var firstLength = nums1.Length;
        var secondLength = nums2.Length;
        var firstPointer = 0;
        var secondPointer = 0;
        var mergedArray = new int[firstLength + secondLength];

        var currentValue = 0;
        var currentIndex = 0;
        while (firstPointer<firstLength || secondPointer<secondLength)
        {
            if (firstPointer < firstLength && secondPointer < secondLength)
            {
                if (nums1[firstPointer] > nums2[secondPointer])
                {
                    currentValue = nums2[secondPointer];
                    secondPointer++;
                }
                else
                {
                    currentValue = nums1[firstPointer];
                    firstPointer++;
                }
            }
            else if(firstPointer<firstLength)
            {
                currentValue = nums1[firstPointer];
                firstPointer++;
            }
            else
            {
                currentValue = nums2[secondPointer];
                secondPointer++;
            }
            mergedArray[currentIndex]=currentValue;
            currentIndex++;
        }

        var length = mergedArray.Length;
        if (length % 2 == 1)
            return mergedArray[length / 2 ];
        return (double)(mergedArray[length / 2 - 1] + mergedArray[length / 2]) / 2;
    }
}