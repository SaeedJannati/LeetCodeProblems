namespace LeetCodeProblems.Problems;

public class LeetCode407TrappingRainWaterII: BaseProblemClass
{
    public int TrapRainWater(int[][] heightMap)
    {
        int xLength = heightMap.Length;
        int zLength = heightMap[0].Length;
        int result = 0;
        var minHeap = new PriorityQueue<List<int>, int>();
        var visited = new bool[xLength][];
        for (var i = 0; i < xLength; i++)
        {
            visited[i] = new bool[zLength];
        }

        for (int i = 0; i < xLength; i++)
        {
            minHeap.Enqueue([i, 0, heightMap[i][0]], heightMap[i][0]);
            visited[i][0] = true;
            minHeap.Enqueue([i, zLength-1, heightMap[i][zLength-1]], heightMap[i][zLength-1]);
            visited[i][zLength-1] = true;
        }
        for (int i = 1; i < zLength-1; i++)
        {
            minHeap.Enqueue([0,i, heightMap[0][i]], heightMap[0][i]);
            visited[0][i] = true;
            minHeap.Enqueue([xLength-1,i, heightMap[xLength-1][i]], heightMap[xLength-1][i]);
            visited[xLength-1][i] = true;
        }
        List<List<int>> directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];
        while (minHeap.Count > 0)
        {
            var node = minHeap.Dequeue();
            int newRow = 0;
            int newCol = 0;
            foreach (var direction in directions)
            {
                newRow=node[0]+direction[0];
                if(newRow<0 || newRow>=xLength)
                    continue;
                newCol=node[1]+direction[1];
                if(newCol<0 || newCol>=zLength)
                    continue;
                if(visited[newRow][newCol])
                    continue;
                visited[newRow][newCol] = true;
                if(node[2]>heightMap[newRow][newCol])
                    result+=node[2]-heightMap[newRow][newCol];
                int height = Math.Max(heightMap[newRow][newCol], node[2]);
                minHeap.Enqueue([newRow,newCol,height], height);
            }
        }

        return result;
    }

    public override void Run()
    {
        int[][] heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]];
        Console.WriteLine(TrapRainWater(heightMap));
    }
}