using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode25ReverseNodesInKGroup : BaseProblemClass
{
    public ListNode ReverseKGroup(ListNode head, int k)
    {
        bool reversed = true;
        ListNode root = head;
        ListNode prev = null;
        ListNode reverseStart = head;
        while (reversed)
        {
            var outPut = ReverseList(reverseStart, prev, k);
          if(outPut.reversed)
              if (prev == null)
                  root = outPut.headOfList;
            reversed = outPut.reversed;
            prev = reverseStart;
            reverseStart=outPut.next;
        }

        return root;
    }

    private (ListNode headOfList,ListNode next,bool reversed) ReverseList(ListNode head, ListNode prev, int count)
    {
        ListNode current = head;
        for (int i = 0; i < count; i++)
        {
            if (current == null)
            {
                if (prev != null)
                    return (prev,null,false);
                return (head,null,false);
            }

            current = current.next;
        }
        current = head;
        int counter = 0;
        ListNode previous = null;
        ListNode next = null;
        while (current != null && counter < count)
        {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
            counter++;
        }

        if (prev != null)
            prev.next = previous;
        head.next = next;
        if (prev != null)
            return (prev,next,true);
        return (previous,next,true);
    }

    public override void Run()
    {
        List<int> input = [1, 2, 3, 4, 5];
        int k = 2;
        ListNode head = ListNode.CreateLinkedLis(input);
       var newHead= ReverseKGroup(head,k);
        ListNode.PrintList(newHead);
    }
}