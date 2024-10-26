using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode148SortList
{
    public ListNode SortList(ListNode head)
    {
        if (head == null)
            return head;
        if (head.next == null)
            return head;
        PriorityQueue<int, int> queue = new();
        ListNode current = head;
        while (current != null)
        {
            queue.Enqueue(current.val, current.val);
            current = current.next;
        }
        ListNode next = null;
         head = new(queue.Dequeue());
         current = head;
        while (queue.Count>0)
        {
            next= new ListNode(queue.Dequeue());
            current.next = next;
            current = next;
        }

        return head;
    }
}