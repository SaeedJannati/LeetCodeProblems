using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode2095DeletetheMiddleNodeofaLinkedList
{
    public ListNode DeleteMiddle(ListNode head)
    {
        if (head == null || head.next == null)
        {
            return null;
        }
        ListNode previous = null;
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null )
        {
            fast = fast.next;
            if(fast == null)
                break;
            previous = slow;
            slow = slow.next;
            fast=fast.next;
        }
        previous.next = slow.next;
        return head;
    }
    //Mine
        // public ListNode DeleteMiddle(ListNode head)
        // {
        //     if (head.next == null)
        //         return null;
        //     int length = 0;
        //     var current = head;
        //     while (current != null)
        //     {
        //         length++;
        //         current = current.next;
        //     }
        //
        //     current = head;
        //     ListNode previous = null;
        //     ListNode next = null;
        //   var half=  length /= 2;
        //     if (half == 1 && length ==2)
        //     {
        //         head.next = null;
        //         return head;
        //     }
        //
        //     for (int i = 0; i < half; i++)
        //     {
        //         previous = current;
        //         current = current.next;
        //         next = current.next;
        //     }
        //     previous.next = next;
        //     return head;
        // }
    }