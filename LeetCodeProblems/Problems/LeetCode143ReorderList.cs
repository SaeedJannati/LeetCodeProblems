using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode143ReorderList : BaseProblemClass
{
    public void ReorderList(ListNode head)
    {
        if (head == null || head.next == null)
            return;
        var slow = head;
        var fast = head;
        ListNode previous = null;
        while (fast != null && fast.next != null)
        {
            previous = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode current = slow;
        ListNode next = null;
        previous.next = null;
        previous = null;
        while (current != null)
        {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }

        ListNode endCurrent = previous;
        ListNode endNext = null;
        current = head;
        while (current != null)
        {
            next = current.next;
            previous = endCurrent;
            current.next = endCurrent;
            endNext = endCurrent.next;
            endCurrent.next = next;
            current = next;
            endCurrent = endNext;
        }

        if (endCurrent != null)
            previous.next = endCurrent;
    }

    public override void Run()
    {
        ListNode head = ListNode.CreateLinkedLis([1, 2, 3, 4]);
        ReorderList(head);
    }
}