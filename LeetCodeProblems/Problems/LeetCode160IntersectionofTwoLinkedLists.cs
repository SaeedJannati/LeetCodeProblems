using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode160IntersectionofTwoLinkedLists : BaseProblemClass
{
    #region O(n+m) TC and O(1) memory

    public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
    {
        var lengthA = GetLength(headA);
        var lengthB = GetLength(headB);
        var node = lengthA > lengthB ? headA : headB;
        var otherNode = lengthA > lengthB ? headB : headA;
        var delta=Math.Abs( lengthA - lengthB);
        for (int i = 0; i < delta; i++)
        {
            node=node.next;
        }

        while (node != null)
        {
            if(node==otherNode)
                return node;
            node = node.next;
            otherNode = otherNode.next;
        }
        return null;
    }

    private int GetLength(ListNode headA)
    {
        ListNode current = headA;
        int length = 0;
        while (current != null)
        {
            length++;
            current = current.next;
        }

        return length;
    }

    #endregion

    #region O(n+m) TC and memory

    // public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
    // {
    //     HashSet<ListNode> nodes = [];
    //     ListNode currentA=headA;
    //     ListNode currentB=headB;
    //     while (currentA !=null || currentB !=null)
    //     {
    //         if (currentA != null)
    //         {
    //             if(!nodes.Add(currentA))
    //                 return currentA;
    //             currentA = currentA.next;
    //         }
    //
    //         if (currentB != null)
    //         {
    //             if(!nodes.Add(currentB))
    //                 return currentB;
    //             currentB = currentB.next;
    //         }
    //
    //       
    //     }
    //
    //     return null;
    // }

    #endregion

    public override void Run()
    {
        ListNode nodeA = ListNode.CreateLinkedLis([5, 6, 1, 8, 4, 5]);
        ListNode nodeB = ListNode.CreateLinkedLis([4, 1, 8, 4, 5]);
        var node = GetIntersectionNode(nodeA, nodeB);
        Console.WriteLine(node?.val);
    }
}