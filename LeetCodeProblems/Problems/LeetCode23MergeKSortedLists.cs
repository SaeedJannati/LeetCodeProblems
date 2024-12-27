using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode23MergeKSortedLists
{
    public ListNode MergeKLists(ListNode[] lists)
    {
        Dictionary<int, List<ListNode>> dict = [];
        SortedList<int, int> sortedList = [];
        foreach (var node in lists)
        {
            AddToDict(dict,sortedList,node);
        }

        ListNode head = null;
        ListNode current=null;
        ListNode next=null;
        int value = 0;
        ListNode nodeFromDict = null;
        int nodeIndexInDict = 0;
        while (dict.Count>0)
        {
            value=sortedList.First().Value;
            nodeIndexInDict = dict[value].Count - 1;
            nodeFromDict=dict[value][nodeIndexInDict];
            dict[value].RemoveAt(nodeIndexInDict);
            if (dict[value].Count == 0)
            {
                sortedList.Remove(value);
                dict.Remove(value);
            }

            if (nodeFromDict.next != null)
            {
                AddToDict(dict,sortedList,nodeFromDict.next);
            }

            if (head == null)
            {
                head=new ListNode(value);
                current=head;
                continue;
            }

            next = new ListNode(value);
            current.next=next;
            current=next;
        }

        return head;
    }

    private void AddToDict(Dictionary<int, List<ListNode>> dict, SortedList<int, int> sortedList, ListNode node)
    {
        if(node == null)
            return;
        if (dict.ContainsKey(node.val))
        {
            dict[node.val].Add(node);
            return;
        }
        dict[node.val] = [node];
        sortedList.Add(node.val,node.val);
    }

}