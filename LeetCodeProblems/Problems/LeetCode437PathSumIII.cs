using LeetCodeProblems.Auxilaries;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode437PathSumIII: BaseProblemClass
{
    public int PathSum(TreeNode root, int targetSum) {
        if(root == null)
            return 0;
        int matchCount = 0;
        Dfs(root, targetSum,ref matchCount);
        return matchCount;
    }

    List<long> Dfs(TreeNode node, int targetSum, ref int matchCount)
    {
        List<long> output = [];
        if(node.left != null)
            output=Dfs(node.left, targetSum, ref matchCount);
        if(node.right != null)
            output.AddRange(Dfs(node.right, targetSum, ref matchCount));
        for (int i = 0; i < output.Count; i++)
        {
            output[i] += node.val;
            if(output[i] == targetSum)
                matchCount++;
        }
        output.Add(node.val);
        if(node.val == targetSum)
            matchCount++;
        return output;
    }

    public override void Run()
    {
        var root = TreeBuilder.BuildTree([
            1000000000, 1000000000, null, 294967296, null, 1000000000, null, 1000000000, null, 1000000000
        ]);
        var targetSum = 0;
        Console.WriteLine(PathSum(root, targetSum));
    }
}