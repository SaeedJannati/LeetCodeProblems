namespace LeetCodeProblems.Problems;

public class LeetCode138CopyListWithRandomPointer
{
    public class Node
    {
        public int val;
        public Node next;
        public Node random;

        public Node(int _val)
        {
            val = _val;
            next = null;
            random = null;
        }
    }

    public Node CopyRandomList(Node head)
    {
        if (head == null)
            return null;
        Dictionary<Node, Node> map = [];
        Node current = head;
        while (current != null)
        {
            var node = new Node(current.val);
            map.Add(current, node);
            current = current.next;
        }

        current = head;
        while (current != null)
        {
            if (current.next != null)
                map[current].next = map[current.next];
            if (current.random != null)
                map[current].random = map[current.random];
            current = current.next;
        }

        return map[head];
    }
}