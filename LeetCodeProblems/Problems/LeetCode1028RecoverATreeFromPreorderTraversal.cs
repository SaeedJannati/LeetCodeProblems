using System.Text;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode1028RecoverATreeFromPreorderTraversal: BaseProblemClass
{
    public TreeNode RecoverFromPreorder(string traversal)
    {
        int length = traversal.Length;
        List<(int value,int dpeth)> preorder = new List<(int value, int dpeth)>();
        Stack<int> numStack = new Stack<int>();
        int depth = 0;
        for (int i = 0; i < length; i++)
        {
            if (traversal[i] == '-')
            {
                if (numStack.Count > 0)
                {
                    AddItem(numStack, preorder, depth);
                    depth = 0;
                }

                depth++;
                continue;
            }
            numStack.Push(traversal[i]-'0');
        }
        AddItem(numStack, preorder, depth);
        TreeNode root = new TreeNode(preorder[0].value);
        Stack<(TreeNode node,int depth)> ancestors = new ();
        ancestors.Push((root,0));
        for (int i = 1, e = preorder.Count; i < e; i++)
        {
            var node = new TreeNode(preorder[i].value) ;
            if (preorder[i].dpeth == preorder[i - 1].dpeth + 1)
            {
                ancestors.Peek().node.left = node;
                ancestors.Push((node,preorder[i].dpeth));
                continue;
            }

            if (preorder[i].dpeth == preorder[i - 1].dpeth)
            {
                ancestors.Pop();
                ancestors.Pop().node.right = node;
                ancestors.Push((node,preorder[i].dpeth));
                continue;
            }

            while (preorder[i].dpeth- ancestors.Peek().depth!=1)
            {
                ancestors.Pop();
            }
            ancestors.Pop().node.right = node;
            ancestors.Push((node,preorder[i].dpeth));
        }

        return root;
    }

    private  void AddItem(Stack<int> numStack, List<(int value, int dpeth)> preorder, int depth)
    {
        int num = 0;
        int powOfTen = 1;
        while (numStack.Count>0)
        {
            num+=numStack.Pop()*powOfTen;
            powOfTen *= 10;
        }
        preorder.Add((num,depth));
    }

    public override void Run()
    {
        string traversal = 
            "1-401--349---90--88"; 
            // "1-2--3--4-5--6--7";
        var root=RecoverFromPreorder(traversal);
        var builder=new StringBuilder();
        PrintPreorder(root, builder);
        Console.WriteLine(builder.ToString());
    }

    void PrintPreorder(TreeNode root,StringBuilder builder )
    {
        builder.Append($"{root.val},");
        if(root.left!=null)
            PrintPreorder(root.left,builder);
        if(root.right!=null)
            PrintPreorder(root.right,builder);
    }
}