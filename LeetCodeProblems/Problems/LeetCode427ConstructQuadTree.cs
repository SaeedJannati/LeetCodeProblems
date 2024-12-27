namespace LeetCodeProblems.Problems;

public class LeetCode427ConstructQuadTree: BaseProblemClass
{
    public Node Construct(int[][] grid)
    {
        return CreateNode(grid,0,grid.Length-1,0,grid.Length-1);
    }

    Node CreateNode(int[][] grid, int xMin, int xMax, int yMin, int yMax)
    {
        if (xMin == xMax && yMin == yMax)
            return new Node(grid[yMin][xMin] == 1, true);
        var values = new HashSet<int>();
        bool shouldDivide = false;
        for (int i = yMin; i <= yMax; i++)
        {
            for (int j = xMin; j <= xMax; j++)
            {
                values.Add(grid[i][j]);
                if (values.Count > 1)
                {
                    shouldDivide = true;
                    break;
                }
            }
            if (shouldDivide)
                break;
        }

        var node = new Node();
        if (!shouldDivide)
        {
            node.isLeaf = true;
            node.val=values.First()==1;
            return node;
        }
        int xMid=(xMin+xMax) / 2;
        
        node.topLeft = CreateNode(grid, xMin, (xMax + xMin) / 2, yMin, (yMax + yMin) / 2);
        node.bottomLeft = CreateNode(grid, xMin, (xMax + xMin) / 2, (yMax + yMin) / 2+1, yMax);
        node.topRight = CreateNode(grid, (xMax + xMin) / 2+1, xMax, yMin, (yMax + yMin) / 2);
        node.bottomRight = CreateNode(grid, (xMax + xMin) / 2+1, xMax, (yMax + yMin) / 2+1, yMax);
        node.isLeaf = false;
        node.val = !(node.topRight.val ^ node.bottomRight.val ^ node.bottomLeft.val ^ node.topLeft.val);
        return node;
    }

    public class Node
    {
        public bool val;
        public bool isLeaf;
        public Node topLeft;
        public Node topRight;
        public Node bottomLeft;
        public Node bottomRight;

        public Node()
        {
            val = false;
            isLeaf = false;
            topLeft = null;
            topRight = null;
            bottomLeft = null;
            bottomRight = null;
        }

        public Node(bool _val, bool _isLeaf)
        {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = null;
            topRight = null;
            bottomLeft = null;
            bottomRight = null;
        }

        public Node(bool _val, bool _isLeaf, Node _topLeft, Node _topRight, Node _bottomLeft, Node _bottomRight)
        {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = _topLeft;
            topRight = _topRight;
            bottomLeft = _bottomLeft;
            bottomRight = _bottomRight;
        }
    }

    public override void Run()
    {
        int[][] grid = [[0,1],[1,0]];
        var node = Construct(grid);
    }
}