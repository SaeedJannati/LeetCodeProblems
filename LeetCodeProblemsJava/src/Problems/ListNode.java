package Problems;

public class ListNode{
    int val;
    ListNode next;
    ListNode(){}
    ListNode(int value){
        this.val = value;
    }
    ListNode(int value,ListNode next){
        this.val = value;
        this.next = next;
    }
    ListNode(int[] values){
        ListNode node = this;
        this.val = values[0];
        for(int i = 1; i < values.length; i++){
            node.next = new ListNode(values[i]);
            node = node.next;
        }
    }

}
