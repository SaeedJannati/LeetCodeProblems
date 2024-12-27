using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode82RemoveDuplicatesFromSortedListII: BaseProblemClass
{
    
    public ListNode DeleteDuplicates(ListNode head)
    {
        if (head == null)
            return head;
        if (head.next == null)
            return head;
        ListNode previous = null;
        var current = head;
        ListNode next = null;
        bool foundDuplicate = false;
        while (current.next != null)
        {
            foundDuplicate = false;
            next = current.next;
            while (next.val == current.val)
            {
                foundDuplicate = true;
                if (next.next == null)
                {
                    next = null;
                    break;
                }
                next = next.next;
            }

            if (!foundDuplicate)
            {
                previous = current;
                current = next;
                continue;
            }

            if (previous == null)
            {
                if (next == null)
                    return null;
                head = next;
                current = next;
                continue;
            }
            previous.next = next;
            current = next;
            if(current==null)
                break;
        }
        return head;
    }

    public override void Run()
    {
       var head = ListNode.CreateLinkedLis([1,1,2]);
       head = DeleteDuplicates(head);
       ListNode.PrintList(head);
    }
}