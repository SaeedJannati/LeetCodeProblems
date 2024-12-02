using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode2130MaximumTwinSumOfALinkedList
{
    public int PairSum(ListNode head)
    {
        if (head == null || head.next == null)
            return 0;
        List<int> flatSet = [];
        ListNode current = head;
        while (current != null)
        {
            flatSet.Add(current.val);
            current = current.next;
        }
        var length = flatSet.Count;
        var maxTwinSum = int.MinValue;
        var currentTwinSum = 0;
        for (int i = 0, e = length / 2; i < e; i++)
        {
            currentTwinSum = flatSet[i]+flatSet[length-i-1];
            if(currentTwinSum > maxTwinSum)
                maxTwinSum = currentTwinSum;
        }
        return maxTwinSum;
    }
}