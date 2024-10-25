using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode86PartitionList: BaseProblemClass
{
    public override void Run()
    {
        List<int> nodeValues = [2,1];
        int x=2;
        var head=ListNode.CreateLinkedLis(nodeValues);
        head=Partition(head,x);
        ListNode.PrintList(head);
    }
    public ListNode Partition(ListNode head, int x)
    {
        if (head == null)
            return head;
        if (head.next == null)
            return head;
        ListNode current=head;
        ListNode greaterHead=null;
        ListNode greaterCurrent=null;
        ListNode lessHead=null;
        ListNode lessCurrent=null;
        while (current != null)
        {
            if (current.val < x)
            {
                if (lessHead == null)
                {
                    lessHead=new (current.val);
                    lessCurrent=lessHead;
                }
                else
                {
                    lessCurrent.next = new(current.val);
                    lessCurrent=lessCurrent.next;
                }
                
            }
            else
            {
                if (greaterHead == null)
                {
                    greaterHead=new (current.val);
                    greaterCurrent=greaterHead;
                }
                else
                {
                    greaterCurrent.next = new(current.val);
                    greaterCurrent=greaterCurrent.next;
                }
            }
            current = current.next;
        }
        if(lessHead==null)
            return greaterHead;
        if (greaterHead == null)
            return lessHead;
        lessCurrent.next = greaterHead;
        return lessHead;
    }

   
}