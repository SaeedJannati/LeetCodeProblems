namespace LeetCodeProblems.Problems;

public class LeetCode120Triangle: BaseProblemClass
{
    public int MinimumTotal(IList<IList<int>> triangle)
    {
        if (triangle.Count == 0)
            return 0;
        if(triangle.Count == 1)
            return triangle[0][0];
        triangle[1][0]+=triangle[0][0];
        triangle[1][1]+=triangle[0][0];
        if(triangle.Count == 2)
            return Math.Min(triangle[1][0], triangle[1][1]);
        for (int i = 2,e=triangle.Count; i < e; i++)
        {
            triangle[i][0]+=triangle[i-1][0];
            triangle[i][^1]+=triangle[i-1][^1];
            for (int j = 1,f=triangle[i].Count-1; j < f; j++)
            {
                triangle[i][j]+=Math.Min(triangle[i-1][j],triangle[i-1][j-1]); 
            }
        }

        return triangle[^1].Min();

    }

    public override void Run()
    {
        IList<IList<int>> input = [[2],[3,4],[6,5,7],[4,1,8,3]];
        var outPut = MinimumTotal(input);
        Console.WriteLine(outPut);
    }
}