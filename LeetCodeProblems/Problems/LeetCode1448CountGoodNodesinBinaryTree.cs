using LeetCodeProblems.Auxilaries;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode1448CountGoodNodesinBinaryTree: BaseProblemClass
{
    public int GoodNodes(TreeNode root)
    {
        int counter = 0;
        int maxSoFar=int.MinValue;
        DFS(root,ref counter,maxSoFar);
        return counter;
    }

    void DFS(TreeNode node, ref int counter, int maxSoFar)
    {
        if (node.val >= maxSoFar)
        {
            maxSoFar = node.val;
            counter++;
        }
        if (node.left != null)
            DFS(node.left, ref counter, maxSoFar);
        if(node.right != null)
            DFS(node.right, ref counter, maxSoFar);
    }

    public override void Run()
    {
        var root = TreeBuilder.BuildTree([2, null, 4, 10, 8, null, null, 4]);
        var counter = GoodNodes(root);
        Console.WriteLine(counter); 
    }
}