using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode142LinkedListCycleII
{
    #region with memory limit

    public ListNode DetectCycle(ListNode head)
    {
        if (head == null || head.next == null)
            return null;
        ListNode slow = head;
        ListNode fast = head;
        while (fast is { next: not null })
        {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                break;
        }

        if (fast?.next == null)
            return null;
        slow = head;
        while (slow != fast)
        {
            fast = fast.next;
            slow = slow.next;
        }

        return slow;
    }

    #endregion

    #region with no memory limit

    // public ListNode DetectCycle(ListNode head) 
    // {
    //     HashSet<ListNode> visited = new HashSet<ListNode>();
    //     ListNode current = head;
    //     while (current != null)
    //     {
    //         if (!visited.Add(current))
    //             return current;
    //         current = current.next;
    //     }
    //     return null;
    // }

    #endregion
}