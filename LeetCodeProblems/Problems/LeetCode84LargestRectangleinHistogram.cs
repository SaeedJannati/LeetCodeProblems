namespace LeetCodeProblems.Problems;

public class LeetCode84LargestRectangleinHistogram : BaseProblemClass
{
    public int LargestRectangleArea(int[] heights)
    {
        int length = heights.Length;
        if (length == 0)
            return 0;
        if (length == 1)
            return heights[0];
        Stack<(int height, int index)> monotoniqueStack = [];
        int[] nextLesserLeft = new int[length];
        int[] nextLesserRight = new int[length];
        for (int i = 0; i < length; i++)
        {
            while (monotoniqueStack.Count > 0 && monotoniqueStack.Peek().height >= heights[i])
            {
                monotoniqueStack.Pop();
            }

            if (monotoniqueStack.Count == 0)
                nextLesserLeft[i] = -1;
            else
                nextLesserLeft[i] = monotoniqueStack.Peek().index;

            monotoniqueStack.Push((heights[i], i));
        }

      
        monotoniqueStack = [];
        for (int i = length - 1; i >= 0; i--)
        {
            while (monotoniqueStack.Count > 0 && monotoniqueStack.Peek().height >= heights[i])
            {
                monotoniqueStack.Pop();
            }

            if (monotoniqueStack.Count == 0)
                nextLesserRight[i] = -1;
            else
                nextLesserRight[i] = monotoniqueStack.Peek().index;
            monotoniqueStack.Push((heights[i], i));
        }

        int maxArea = int.MinValue;
        int right = 0;
        int left = 0;
        int area = 0;
        for (int i = 0; i < length; i++)
        {
            right = nextLesserRight[i] == -1 ? length-1 : nextLesserRight[i]-1;
            left = nextLesserLeft[i] == -1 ? 0 : nextLesserLeft[i]+1;
            area = heights[i] * (right - left + 1);
            if (area > maxArea)
                maxArea = area;
        }

        return maxArea;
    }

    public override void Run()
    {
        int[] heights = [1,1];
        Console.WriteLine(LargestRectangleArea(heights));
    }
}