namespace LeetCodeProblems.Problems;

public class LeetCode973KClosestPointsToOrigin
{
    public int[][] KClosest(int[][] points, int k) {
        PriorityQueue<int[],long> queue = new();
        for (int i = 0, e = points.Length; i < e; i++)
        {
            long xDistance=points[i][0];
            xDistance*=xDistance;
            long yDistance=points[i][1];
            yDistance*=yDistance;
            queue.Enqueue(points[i],xDistance+yDistance);
        }
        int[][] result=new int[k][];
        for (int i = 0; i < k; i++)
        {
            result[i]=queue.Dequeue();
        }

        return result;
    }
}