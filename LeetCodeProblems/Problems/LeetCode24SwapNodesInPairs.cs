using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode24SwapNodesInPairs : BaseProblemClass
{
    public ListNode SwapPairs(ListNode head)
    {
        if (head == null)
            return head;
        if (head.next == null)
            return head;
        ListNode newHead = head.next;
        ListNode current = head;
        ListNode next = null;
        ListNode previous = null;
        ListNode doubleNext = null;
        while (current != null && current.next != null)
        {
            next = current.next;
            current.next = next.next;
            next.next = current;
            if (previous != null)
                previous.next = next;
            previous = current;
            current = current.next;
        }

        return newHead;
    }

    public override void Run()
    {
        ListNode head = ListNode.CreateLinkedLis([1, 2, 3]);
        head = SwapPairs(head);
        ListNode.PrintList(head);
    }
}