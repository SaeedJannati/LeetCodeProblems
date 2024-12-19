using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode234PalindromeLinkedList
{
    public bool IsPalindrome(ListNode head)
    {
        if (head == null )
            return false;
        if (head.next == null)
            return true;
        Stack<int> stack = new();
        Queue<int> queue = new();
        ListNode node = head;
        while (node is not null)
        {
            stack.Push(node.val);
            queue.Enqueue(node.val);
            node=node.next;
        }

        while (stack.Count > 0)
        {
            if(stack.Pop()!=queue.Dequeue())
                return false;
        }
        return true;
    }
}