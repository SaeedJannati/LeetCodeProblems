namespace LeetCodeProblems.Problems;

public class LeetCode329LongestIncreasingPathInAMatrix: BaseProblemClass
{
    void Dfs(int[][] matrix, int[,] pathLength, bool[,] visited, int height, int width, List<List<int>> directions,
        int row, int col,ref int maxLength)
    {
        int newRow = 0;
        int newCol = 0;
        int currentValue = 0;
        for (int i = 0; i < 4; i++)
        {
            newRow = row + directions[i][0];
            if (newRow < 0 || newRow >= height)
                continue;
            newCol = col + directions[i][1];
            if (newCol < 0 || newCol >= width)
                continue;
            if (matrix[newRow][newCol] <= matrix[row][col])
                continue;
            if (visited[newRow, newCol])
            {
                if (pathLength[newRow, newCol] > currentValue)
                    currentValue = pathLength[newRow,newCol];
                continue;
            }
            visited[newRow, newCol] = true;
            Dfs(matrix,pathLength,visited,height,width,directions,newRow,newCol,ref maxLength);
            if (pathLength[newRow, newCol] > currentValue)
                currentValue = pathLength[newRow,newCol];
        }
        pathLength[row, col] = currentValue+1;
        if(pathLength[row, col] > maxLength)
            maxLength = pathLength[row, col];
    }

    public int LongestIncreasingPath(int[][] matrix)
    {
        int height = matrix.Length;
        int width = matrix[0].Length;
        bool[,] visited = new bool[height, width];
        int[,] pathLength = new int[height, width];
        List<List<int>> directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
        int maxLengthPath = 1;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if(visited[i,j])
                    continue;
                Dfs(matrix,pathLength,visited,height,width,directions,i,j,ref maxLengthPath);
            }
        }
        return maxLengthPath;
    }

    public override void Run()
    {
        int[][] matrix = [[1, 2]]; 
            // [[9,9,4],[6,6,8],[2,1,1]];
        Console.WriteLine(LongestIncreasingPath(matrix));
    }
}