package Problems;

public class LeetCode2095DeleteTheMiddleNodeOfALinkedList {

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode deleteMiddle(ListNode head) {
        if (head == null ) {
            return head;
        }
        if (head.next == null) {
            return null;
        }
        var previous = head;
        var slow = head;
        var fast = head;
        while (fast != null) {
            fast = fast.next;
            if (fast == null) {
                break;
            }
            previous = slow;
            slow = slow.next;
            fast = fast.next;
        }
        previous.next = slow.next;
        return head;
    }

}
