namespace LeetCodeProblems.Problems;

public class LeetCode149MaxPointsOnALine : BaseProblemClass
{
    public int MaxPoints(int[][] points)
    {
        if (points.Length == 0)
            return 0;
        if (points.Length == 1)
            return 1;
        Dictionary<decimal, Dictionary<decimal, PointsInLine>> dict = [];
        decimal slope;
        decimal h;
        int maxPoints = 0;
        int precision = 8;
        for (int i = 0, e = points.Length; i < e; i++)
        {
            for (int j = i + 1; j < e; j++)
            {
                if (points[i][0] == points[j][0])
                {
                    slope = decimal.MaxValue;
                    h = points[i][0];
                }
                else
                {
                    slope = (decimal) (points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                   
                    h =  Math.Round(points[j][1] - slope * points[j][0], precision);
                }

                if (dict.ContainsKey(slope))
                {
                    if (dict[slope].ContainsKey(h))
                    {
                        if (!dict[slope][h].TryAddPoint(points[j][0], points[j][1]))
                            continue;
                    }
                    else
                    {
                        var pointsInLine = new PointsInLine();
                        pointsInLine.TryAddPoint(points[j][0], points[j][1]);
                        pointsInLine.TryAddPoint(points[i][0], points[i][1]);
                        dict[slope][h]=pointsInLine;
                    }
                }
                else
                {
                    var pointsInLine = new PointsInLine();
                    pointsInLine.TryAddPoint(points[j][0], points[j][1]);
                    pointsInLine.TryAddPoint(points[i][0], points[i][1]);
                    dict[slope] = [];
                    dict[slope][h]=pointsInLine;
                }

                if (dict[slope][h].count > maxPoints)
                    maxPoints = dict[slope][h].count;
            }
        }

        return maxPoints;
    }

    private class PointsInLine
    {
        public int count { get; private set; } = 0;
        private Dictionary<int, HashSet<int>> dict = [];

        public bool TryAddPoint(int x, int y)
        {
            if (!dict.ContainsKey(x))
            {
                dict.Add(x, [y]);
                count++;
                return true;
            }

            if (dict[x].Contains(y))
                return false;
            dict[x].Add(y);
            count++;
            return true;
        }
    }

    public override void Run()
    {
        int[][] input =[[84,250],[0,0],[0,-70],[-42,-230],[21,10],[42,90],[1,0],[1,-1]];
        Console.WriteLine(MaxPoints(input));
    }
}