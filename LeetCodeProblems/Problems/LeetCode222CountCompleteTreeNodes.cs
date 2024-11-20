using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode222CountCompleteTreeNodes
{
    public int CountNodes(TreeNode root)
    {
        if (root == null)
            return 0;
        var height = GetHeight(root);
        var output=(int)Math.Pow(2,height+1)-1;
        
    }

    (int index,int modTwo) FindLeaf(TreeNode root, int height)
    {
        int begin = 0;
        int end=height;
        int mid = 0;
        int newMid = 0;
        while (true)
        {
            mid = (begin + end) / 2;
            var current = root;
            for (int i = 0; i < height-1; i++)
            {
                current = i < mid ? current.left : current.right;
            }

            if (current.left != null && current.right == null)
                return (mid,1);
            if (current.left == null)
            {
                end = mid ;
            }
            else
            {
                begin = mid ;
            }
            newMid = (begin + end) / 2;
             if (newMid == mid)
             {
                 if (current.left == null)
                 {
                     current = root;
                     for (int i = 0; i < height-1; i++)
                     {
                         current = i < mid-1 ? current.left : current.right;
                     }

                     return (mid + 1, current.right != null ? 1 : 0);
                 }
                 else
                 {
                     current = root;
                     for (int i = 0; i < height-1; i++)
                     {
                         current = i < mid+1 ? current.left : current.right;
                     }

                     return (mid + 1, current.right != null ? 1 : 0);
                 }
             }


        }
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
}