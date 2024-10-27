using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode230KthSmallestElementInABST
{
    
    public int KthSmallest(TreeNode root, int k)
    {
        int currentIndex = 0;
        int outPut = 0;
         GetElement(root, k,ref currentIndex,ref outPut);
         return currentIndex;
    }

    private void GetElement(TreeNode node, int k,ref int currentIndex,ref int outPut)
    {
        if(currentIndex==k)
            return;
        if (node.left != null)
            GetElement(node.left, k, ref currentIndex,ref outPut );
        currentIndex++;
        if (currentIndex == k)
        {
            outPut= node.val;
            return;
        }
        if(node.right != null)
            GetElement(node.right, k, ref currentIndex,ref outPut);
    }
}