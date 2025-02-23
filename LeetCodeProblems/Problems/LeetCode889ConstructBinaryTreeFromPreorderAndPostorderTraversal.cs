using LeetCodeProblems.Auxilaries;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode889ConstructBinaryTreeFromPreorderAndPostorderTraversal : BaseProblemClass
{
    Dictionary<int, int> postorderIndices = [];

    public TreeNode ConstructFromPrePost(int[] preorder, int[] postorder)
    {
        int length = preorder.Length;

        for (int i = 0; i < postorder.Length; i++)
        {
            postorderIndices[postorder[i]] = i;
        }

        return Construct(preorder, 0, length - 1, 0);
    }

    private TreeNode Construct(int[] preorder, int preStart, int preEnd, int postStart)
    {
        if (preStart > preEnd)
            return null;
        var node = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
            return node;
        var leftIndex=postorderIndices[preorder[preStart + 1]];
        var leftSubTreeLength = leftIndex - postStart + 1;
        node.left=Construct(preorder, preStart + 1, preStart+leftSubTreeLength, postStart);
        node.right=Construct(preorder,preStart+leftSubTreeLength+1,preEnd,postStart+leftSubTreeLength);
        return node;
    }

    public override void Run()
    {
        int[] preorder =
            // [2, 1, 3];
            [2, 1];
        // [1,2,4,5,3,6,7];
        int[] postorder =
            // [3, 1, 2];
            [1, 2];
        // [4,5,2,6,7,3,1];
        var root = ConstructFromPrePost(preorder, postorder);
        TreePrinter.PrintInOrderTraversal(root);
    }
}