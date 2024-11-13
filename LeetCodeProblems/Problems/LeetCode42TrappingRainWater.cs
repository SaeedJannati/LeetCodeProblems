namespace LeetCodeProblems.Problems;

public class LeetCode42TrappingRainWater : BaseProblemClass
{
    public int Trap(int[] height)
    {
        int length = height.Length;
        List<PointInfo> points = new List<PointInfo>(length);
        int max = -1;
        for (int i = 0; i < length; i++)
        {
            points.Add(new());
            points[^1].leftHighest = max;
            if(height[i] >max)
                max = height[i];

        }

        max = -1;
        for (int i = length - 1; i >= 0; i--)
        {
            points[i].rightHighest = max;
            if(height[i] >max)
                max = height[i];
        }
        int water = 0;
        int minMaxHight = 0;
        for (int i = 0; i < length; i++)
        {
            if (points[i].rightHighest == -1 || points[i].rightHighest == -1)
                continue;
            minMaxHight = Math.Min(points[i].rightHighest, points[i].leftHighest);
            if (minMaxHight <= height[i])
                continue;
            water += minMaxHight - height[i];
        }

        return water;
    }

    public class PointInfo
    {
        public int leftHighest;
        public int rightHighest;
    }

    public override void Run()
    {
        int[] heights = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1];
        Console.WriteLine(Trap(heights));
    }
}