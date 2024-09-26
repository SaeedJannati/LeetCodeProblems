using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class Leetcode19RemoveNthNodeFromEndOfList
{
    public ListNode RemoveNthFromEnd(ListNode head, int n)
    {
        Dictionary<int, ListNode> nodesWithIndex = [];
        var currentNode = head;
        var index = 0;
        while (currentNode!=null)
        {
            nodesWithIndex[index] = currentNode;
            currentNode = currentNode.next;
            index++;
        }

        if (nodesWithIndex[index-n] == head)
            return head.next;
        nodesWithIndex[index-n-1].next=nodesWithIndex[index-n-1].next.next;
        return head;
    }
}