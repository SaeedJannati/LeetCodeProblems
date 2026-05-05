package Problems;

public class LeetCode61RotateList extends BaseProblem {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        if (head.next == null) {
            return head;
        }
        if (k == 0) {
            return head;
        }
        int length = 0;
        ListNode node = head;
        ListNode tail = null;
        while (node != null) {
            length++;
            tail = node;
            node = node.next;
        }
        int toMove = k % length;
        if (toMove == 0) {
            return head;
        }
        int fromBegin = length - toMove;
        node = head;
        ListNode prev = null;
        while (fromBegin != 0) {
            prev = node;
            node = node.next;
            fromBegin--;
        }
        prev.next = null;
        tail.next = head;
        return node;
    }

    @Override
    public void Run() {
        var head = new ListNode(new int[]{1, 2});
        int k = 5;
        head = rotateRight(head, k);
        Auxileries.Print(head);
    }
}

