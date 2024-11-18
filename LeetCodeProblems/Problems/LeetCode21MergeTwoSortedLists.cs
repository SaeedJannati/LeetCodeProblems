using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode21MergeTwoSortedLists: BaseProblemClass
{
    public ListNode MergeTwoLists(ListNode list1, ListNode list2)
    {
        ListNode firstPointer = list1;
        ListNode secondPointer = list2;
        ListNode currentPointer = null;
        ListNode previousPointer = null;
        ListNode root=null;
        while (firstPointer != null || secondPointer != null)
        {
            if (currentPointer != null)
            {
                previousPointer = currentPointer;
            }

            if (firstPointer == null)
            {
                currentPointer = secondPointer;
                secondPointer = secondPointer.next;
            }
            else if (secondPointer == null)
            {
                currentPointer = firstPointer;
                firstPointer = firstPointer.next;
            }
            else
            {
                bool firstLesser = firstPointer.val < secondPointer.val;
                if (firstLesser)
                {
                    currentPointer = firstPointer;
                    firstPointer = firstPointer.next;
                }
                else
                {
                    currentPointer = secondPointer;
                    secondPointer = secondPointer.next;
                }
            }
            
            if (root == null)
                root = currentPointer;
            if (previousPointer != null)
                previousPointer.next = currentPointer;
        }
        if (previousPointer != null)
        {
            previousPointer.next = currentPointer;
        }
        return root;
    }

    public override void Run()
    {
        ListNode node = ListNode.CreateLinkedLis([0]);
        ListNode node2 = ListNode.CreateLinkedLis([0, 1]);
        var merged=MergeTwoLists(node, null);
        ListNode.PrintList(merged);
    }
}