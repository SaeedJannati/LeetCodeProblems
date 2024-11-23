using LeetCodeProblems.Auxilaries;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode1161MaximumLevelSumofaBinaryTree: BaseProblemClass
{
    public int MaxLevelSum(TreeNode root)
    {
        var levelSum = Bfs(root);
        int max = int.MinValue;
        int maxIndex = 0;
        for (int i = 0,e=levelSum.Count; i < e; i++)
        {
            if ( levelSum[i] > max)
            {
                maxIndex = i + 1;
                max = levelSum[i];
            }
        }

        return maxIndex;
    }

    List<int> Bfs(TreeNode root)
    {
        List<int> levelSum = [];
        TreeNode current = null;
        Queue<TreeNode> currentLevel = [];
        Queue<TreeNode> nextLevel = [];
        currentLevel.Enqueue(root);
        int sum = 0;
        while (currentLevel.Count > 0)
        {
            sum = 0;
            while (currentLevel.Count > 0)
            {
                current = currentLevel.Dequeue();
                if (current.left != null)
                    nextLevel.Enqueue(current.left);
                if (current.right != null)
                    nextLevel.Enqueue(current.right);
                sum += current.val;
            }
            levelSum.Add(sum);
            while (nextLevel.Count>0)
            {
                currentLevel.Enqueue(nextLevel.Dequeue());
            }
        }
        return levelSum;
    }

    public override void Run()
    {
        var root =  TreeBuilder.BuildTree([989, null, 10250, 98693, -89388, null, null, null, -32127]);
        var levelSum = MaxLevelSum(root);
        Console.WriteLine(levelSum);
    }
}