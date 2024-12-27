using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode61RotateList : BaseProblemClass
{
    public ListNode RotateRight(ListNode head, int k)
    {
        if (head == null || head.next == null)
            return head;
        int counter = 0;
        ListNode current = head;
        ListNode previous = null;
        while (current != null)
        {
            previous=current;
            current = current.next;
            counter++;
        }

        if (k >= counter)
            k %= counter;
        if (k == 0)
            return head;
        var output = GetTail(head, counter-k);
        output.tailPrev.next = null;
        previous.next = head;
        return output.tail;
    }

    private (ListNode tail, ListNode tailPrev) GetTail(ListNode root, int k)
    {
        int counter = 0;
        ListNode current = root;
        ListNode previous = null;
        while (counter < k && current != null)
        {
            previous = current;
            current = current.next;
            counter++;
        }

        return (current, previous);
    }

    public override void Run()
    {
        List<int> input = [1, 2];
        int k = 2;
        var head = ListNode.CreateLinkedLis(input);
        var newHead = RotateRight(head, k);
        ListNode.PrintList(newHead);
    }
}