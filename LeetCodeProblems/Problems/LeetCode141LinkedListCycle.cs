using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode141LinkedListCycle
{
    public bool HasCycle(ListNode head)
    {
        if(head == null)
            return false;
        if (head.next == null)
            return false;
        HashSet<ListNode> visited = new();
        var current = head;
        while (current != null)
        {
            if (!visited.Add(current))
                return true;
            current = current.next;
        }

        return false;
    }
}