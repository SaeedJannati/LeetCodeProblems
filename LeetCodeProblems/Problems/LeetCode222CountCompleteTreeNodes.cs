using LeetCodeProblems.Auxilaries;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode222CountCompleteTreeNodes : BaseProblemClass
{
    public int CountNodes(TreeNode root)
    {
        if (root == null)
            return 0;
        if (root.left == null)
            return 1;
        if (root.right == null)
            return 2;
        var output = 0;
        Dfs(root, ref output);
        return output;
    }

    (int,int) FindLeaf(TreeNode root, int height)
    {
        int begin = 0;
        int end = height - 2;
        int mid = 0;
        int newMid = 0;
        TreeNode current = null;
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            current = root;
            for (int i = 0; i < height - 2; i++)
            {
                current = i < mid ? current.left : current.right;
            }

            if (current.left != null && current.right == null)
                return ((int)Math.Pow(2,height - 2 - mid) , 1); 
            if (current.left == null)
            {
                begin = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        int mod = 0;
        if (current.left == null)
            mod = 0;
        else if(current.right == null)
        {
            mod = 1;
        }
        else
        {
            mod = 0;
        }
        return  ((int)Math.Pow(2,height - 2 - mid) ,mod);
    }

    int GetHeight(TreeNode root)
    {
        var current = root;
        int output = 0;
        while (current != null)
        {
            current = current.left;
            output++;
        }

        return output;
    }

    void Dfs(TreeNode node, ref int count)
    {
        count++;
        if (node.left != null)
            Dfs(node.left, ref count);
        if (node.right != null)
            Dfs(node.right, ref count);
    }

    public override void Run()
    {
        var tree = TreeBuilder.BuildTree([1,2,3,4,5,6]);
        Console.WriteLine(CountNodes(tree));
    }
}