using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode129SumRootToLeafNumbers
{
    public int SumNumbers(TreeNode root)
    {
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return root.val;
        List<string> nums = new();
        TryGetString(root,"",nums);
        var outPut = 0;
        nums.ForEach(rawNum =>
        {
            outPut += int.Parse(rawNum);
        });
        return outPut;
    }

    public void TryGetString(TreeNode node,string numsSoFar,List<string> nums)
    {
        numsSoFar += node.val;
        if (node.left == null && node.right == null)
        {
            nums.Add(numsSoFar);
            return;
        }
        if(node.left != null)
            TryGetString(node.left,numsSoFar, nums);
        if(node.right != null)
            TryGetString(node.right, numsSoFar, nums);
    }
}