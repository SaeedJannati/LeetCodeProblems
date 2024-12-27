using System.Text;

namespace LeetCodeProblems.Models;


    public class ListNode
    {
        public int val;
        public ListNode next;

        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }

        public static void PrintList(ListNode head)
        {
            if(head==null)
                Console.WriteLine("[]");
            var builder = new StringBuilder("[");
            var current = head;
            while (current!=null)
            {
                builder.Append($"{current.val.ToString()},");
                current = current.next;
            }
            builder.Remove(builder.Length-1,1);
            builder.Append(']');
            Console.WriteLine(builder.ToString());
        }

        public static ListNode CreateLinkedLis(List<int> numbers)
        {
            if (numbers == null || numbers.Count == 0)
                return null;
            var head = new ListNode(numbers[0]);
            var current = head;
            ListNode next=null;
            for (int i = 1,e=numbers.Count; i < e; i++)
            {
                next = new ListNode(numbers[i]);
                current.next =next;
                current = next;
            }

            return head;
        }
    }
