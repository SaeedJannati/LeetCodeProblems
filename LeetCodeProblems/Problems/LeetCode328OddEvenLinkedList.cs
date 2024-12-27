using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode328OddEvenLinkedList : BaseProblemClass
{
    public ListNode OddEvenList(ListNode head)
    {
        if (head == null)
            return head;
        if (head.next == null)
            return head;
        if (head.next.next == null)
            return head;
        int counter = 0;
        ListNode current = head;
        ListNode currentEven = null;
        ListNode prev = null;
        ListNode evenHead = null;
        while (current != null)
        {
            counter++;
            if (counter % 2 == 1)
            {
                if (prev != null)
                    prev.next = current;
                prev = current;
                current = current.next;
                continue;
            }

            if (evenHead == null)
            {
                evenHead = current;
                currentEven = current;
            }
            else
            {
                currentEven.next = current;
            }

            currentEven = current;

            current = current.next;
            prev.next = current;
        }

        currentEven.next = null;
        prev.next = evenHead;


        return head;
    }

    public override void Run()
    {
        ListNode head = ListNode.CreateLinkedLis([1, 2, 3, 4, 5]);
        var node = OddEvenList(head);
        ListNode.PrintList(node);
    }
}