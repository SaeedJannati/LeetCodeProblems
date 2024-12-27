using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode105ConstructBinaryTreeFromPreorderAndInorderTraversal : BaseProblemClass
{
    public override void Run()
    {
        int[] preOrder = [3, 9, 20, 15, 7];
        int[] inOrder = [9, 3, 15, 20, 7];
        var root=BuildTree(preOrder, inOrder);
        PrintPreOrder(root);
        Console.WriteLine();
        PrintInOrder(root);
    }

    public TreeNode BuildTree(int[] preorder, int[] inorder)
    {
        var currentPreorderIndex = 0;
        var inorderMap = new Dictionary<int, int>();
        for (var i = 0; i < inorder.Length; i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return ConstructSubTree(preorder, inorderMap, ref currentPreorderIndex, 0, inorder.Length - 1);
    }

    private TreeNode ConstructSubTree(int[] preorder, Dictionary<int, int> inorderMap, ref int currentPreorderIndex, int inorderStartIndex,
        int inorderEndIndex)
    {
        if (inorderStartIndex > inorderEndIndex)
            return null;
        var rootVal = preorder[currentPreorderIndex];
        currentPreorderIndex++;
        var root = new TreeNode(rootVal);
        if (inorderStartIndex == inorderEndIndex)
            return root;
        var inorderIndex = inorderMap[rootVal];
        root.left = ConstructSubTree(preorder, inorderMap, ref currentPreorderIndex, inorderStartIndex, inorderIndex - 1);
        root.right = ConstructSubTree(preorder, inorderMap, ref currentPreorderIndex, inorderIndex + 1, inorderEndIndex);
        return root;
    }

    void PrintPreOrder(TreeNode? root)
    {
        if(root == null)
            return;
        Console.Write($"{root.val} ");
        PrintPreOrder(root.left);
        PrintPreOrder(root.right);

    }

    void PrintInOrder(TreeNode? root)
    {
        if(root == null)
            return;
        PrintInOrder(root.left);
        Console.Write($"{root.val} ");
        PrintInOrder(root.right);
     
    }
}